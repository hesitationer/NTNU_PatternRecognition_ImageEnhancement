#include "MyForm.h"

using namespace System;
using namespace System::IO;
using namespace System::Drawing;
using namespace System::Windows::Forms;

typedef System::Windows::Forms::DialogResult _DialogResult;


[STAThread]
void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	NTNUEEPR_WPF::MyForm form;
	Application::Run(%form);
}

System::Void NTNUEEPR_WPF::MyForm::MyForm_Resize(System::Object ^ sender, System::EventArgs ^ e)
{
	
}

System::Void NTNUEEPR_WPF::MyForm::MyForm_Resize_End(System::Object ^ sender, System::EventArgs ^ e)
{
	/*if(mainImageName!=nullptr)
		ShowMainImageByName(mainImageName);*/
}

void NTNUEEPR_WPF::MyForm::Setup()
{
	btn_addlayer->AllowDrop = true;
	btn_addlayer->DropDownItems->AddRange(
		gcnew cli::array<
		System::Windows::Forms::ToolStripItem^  >(6) {
		CreateNewLayerType(gcnew LayerHistogramEqualization()),
			CreateNewLayerType(gcnew LayerMedianFilter()),
			CreateNewLayerType(gcnew LayerColorAdjustmentFilter()),
			CreateNewLayerType(gcnew LayerInverse()),
			CreateNewLayerType(gcnew LayerContrastBalance()),
			CreateNewLayerType(gcnew LayerDCTAndIDCT())
	});
}

void NTNUEEPR_WPF::MyForm::LoadImageByFile()
{
	OpenFileDialog broswer;
	_DialogResult result = broswer.ShowDialog();
	if (_DialogResult::OK == result) {
		ShowMainImageByName(broswer.FileName);
	}
	
}

void NTNUEEPR_WPF::MyForm::LoadImageByFolder()
{
	FolderBrowserDialog browser;
	browser.SelectedPath = Environment::CurrentDirectory;
	_DialogResult result = browser.ShowDialog();

	if (result == _DialogResult::OK && 
		!String::IsNullOrWhiteSpace(browser.SelectedPath))
	{
		auto fileNames = Directory::GetFiles(browser.SelectedPath);
		if (fileNames->Length > 0 && pbox_display->Image == nullptr)
			ShowMainImageByName(fileNames[0]);
		for each (String^ name in fileNames)
		{
			AddImageToMenu(name);
		}
	}
}

void NTNUEEPR_WPF::MyForm::CompareImage()
{
}

void NTNUEEPR_WPF::MyForm::AddFilter(int index)
{
	auto item = gcnew ListViewItem();
	item->SubItems->Add(myLayersTypes[index]->Name());
	lview_layer->Items->Add(item);
	myFactLayers->Add(myLayersTypes[index]);
}

void NTNUEEPR_WPF::MyForm::RemoveFilter()
{
	if (index_selected_layer < 0)
		return;
	lview_layer->Items->RemoveAt(index_selected_layer);
	myFactLayers->RemoveAt(index_selected_layer);
	index_selected_layer = -1;
}

void NTNUEEPR_WPF::MyForm::PushFilter()
{
	OffsetFilter(1);
}

void NTNUEEPR_WPF::MyForm::PullFilter()
{
	OffsetFilter(-1);
}

void NTNUEEPR_WPF::MyForm::OffsetFilter(int offset)
{
	int index_origin = index_selected_layer;
	if (index_origin < 0)return;

	int index_new = index_origin + offset;
	if (index_new >= myFactLayers->Count) {
		if (index_origin == myFactLayers->Count - 1) {
			return;
		}
		index_new = myFactLayers->Count - 1;
	}
	else if (index_new < 0) {
		if (index_origin == 0)
			return;
		index_new = 0;
	}

	auto origin_ui_layer = lview_layer->Items[index_origin];
	auto origin_data_layer = myFactLayers[index_origin];

	RemoveFilter();

	lview_layer->Items->Insert(index_origin + offset, origin_ui_layer);
	myFactLayers->Insert(index_origin + offset, origin_data_layer);

	ShowMainImageByName(mainImageName);
}

void NTNUEEPR_WPF::MyForm::ShowMainImageByName(String^ name)
{
	mainImageName = name;
	MyImageData^ myOriginImg = CreateOrGetImage(name);
	if (myOriginImg == nullptr)
		return;

	myOriginImg = ApplyLayer(myOriginImg);
	MyImageData::TYPE* img_data = myOriginImg->data;
	if (img_data == nullptr)
		return;

	int container_width = spC_main->Panel1->Width;
	int container_height = spC_main->Panel1->Height;

	pbox_display->Width = container_width;
	pbox_display->Height = container_height;

	int img_width = img_data->GetWidth();
	int img_height = img_data->GetHeight();

	////draw pixel
	Bitmap^ bitmap = gcnew Bitmap(img_width, img_height, Drawing::Imaging::PixelFormat::Format24bppRgb);
	for(int index_w=0;index_w<img_width;index_w++)
		for (int index_h = 0; index_h < img_height; index_h++) {
			bitmap->SetPixel(index_w, index_h, Color::FromArgb
				(1, img_data->GetPixels(MyImageData::COLOR::R)[index_w][index_h],
					img_data->GetPixels(MyImageData::COLOR::G)[index_w][index_h],
					img_data->GetPixels(MyImageData::COLOR::B)[index_w][index_h]));
	}

	//display
	delete pbox_display->Image;
	pbox_display->Image = bitmap;
	pbox_display->Refresh();

	this->Width = pbox_display->Width + 
			spC_main->SplitterWidth + 200;
	this->Height = pbox_display->Height +
			menuStrip1->Height + 50;
		spC_main->SplitterDistance = spC_main->Width - 200;
}

NTNUEEPR_WPF::MyImageData ^ NTNUEEPR_WPF::MyForm::CalculateModifyImage(String ^ name)
{
	return nullptr;
}

void NTNUEEPR_WPF::MyForm::AddImageToMenu(String ^ name)
{
	MyImageData^ img = CreateOrGetImage(name);
	if (img == nullptr)
		return;

	auto items = msitem_view->DropDownItems;
	if (items->ContainsKey(name))
		return;

	int length = 0;
	for each (auto item in items)
	{
		if (item->ToString()->CompareTo(name)==0) {
			return;
		}
		length++;
	}
	items->Add(name);
	items[length]->Click += gcnew System::EventHandler
		(this, &MyForm::ViewItem_Click);
}


NTNUEEPR_WPF::MyImageData^ NTNUEEPR_WPF::MyForm::CreateOrGetImage(String ^ name)
{
	auto img = FindMyImageByName(name);
	if(img == nullptr)
	{
		img = gcnew MyImageData(name);
		if (img->data == nullptr) {
			return nullptr;
		}
		myImages->Add(img);
		AddImageToMenu(name);
	}
	return img;
}

NTNUEEPR_WPF::MyImageData ^ NTNUEEPR_WPF::MyForm::FindMyImageByName(String ^ name)
{
	for each (MyImageData^ img in myImages)
	{
		if (String::Compare(img->name, name) == 0) {
			return img;
		}
	}
	return nullptr;
}

ToolStripMenuItem ^ NTNUEEPR_WPF::MyForm::CreateNewLayerType(FilterToLayer ^ layerData)
{
	//UI
	ToolStripMenuItem^ newItem = gcnew ToolStripMenuItem();
	newItem->Size = System::Drawing::Size(110, 22);
	newItem->Text = (layerData->Name());
	newItem->Name = myLayersTypes->Count.ToString();
	newItem->Click += gcnew System::EventHandler(this, &MyForm::TSItemAddLayer_Click);

	//Data
	myLayersTypes->Add(layerData);

	return newItem;
}

NTNUEEPR_WPF::MyImageData^ NTNUEEPR_WPF::MyForm::ApplyLayer(MyImageData^ orgin) {
	if (orgin->data == nullptr)
		return nullptr;
	MyImageData^ result = orgin;
	for each (FilterToLayer^ layer in myFactLayers)
	{
		if (layer->isEnable)
			result = layer->Execute(result);
	}
	return result;
}

System::Void NTNUEEPR_WPF::MyForm::ViewItem_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	ShowMainImageByName(sender->ToString());
}

System::Void NTNUEEPR_WPF::MyForm::lview_layer_ItemChecked(System::Object ^ sender, System::Windows::Forms::ItemCheckedEventArgs ^ e)
{
	int index = e->Item->Index;
	if (index >= myFactLayers->Count)
		return;
	myFactLayers[index]->isEnable = e->Item->Checked;
	ShowMainImageByName(mainImageName);
}

System::Void NTNUEEPR_WPF::MyForm::lview_layer_ItemSelectionChanged(System::Object ^ sender, System::Windows::Forms::ListViewItemSelectionChangedEventArgs ^ e)
{
	if (e->IsSelected)
	{
		index_selected_layer = (e->Item->Index);
	}
}



