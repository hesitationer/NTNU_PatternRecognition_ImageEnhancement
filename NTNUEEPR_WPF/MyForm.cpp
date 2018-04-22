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
	if(spC_main->SplitterDistance >= 200)
		spC_main->SplitterDistance = spC_main->Width - 200;
}

System::Void NTNUEEPR_WPF::MyForm::MyForm_Resize_End(System::Object ^ sender, System::EventArgs ^ e)
{
	if(mainImageName!=nullptr)
		ShowMainImageByName(mainImageName);
}

void NTNUEEPR_WPF::MyForm::Setup()
{
	btn_addlayer->AllowDrop = true;
	btn_addlayer->DropDownItems->AddRange(
		gcnew cli::array<
		System::Windows::Forms::ToolStripItem^  >(2) {
		CreateNewLayerType(gcnew LayerHistogramEqualization()),
			CreateNewLayerType(gcnew LayerMedianFilter() )
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
		if (fileNames->Length > 0)
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
	throw gcnew System::NotImplementedException();
}

void NTNUEEPR_WPF::MyForm::PushFilter()
{
	throw gcnew System::NotImplementedException();
}

void NTNUEEPR_WPF::MyForm::PullFilter()
{
	throw gcnew System::NotImplementedException();
}

void NTNUEEPR_WPF::MyForm::ShowMainImageByName(String^ name)
{
	mainImageName = name;
	MyImageData^ myOriginImg = CreateOrGetImage(name);
	if (myOriginImg == nullptr)return;
	myOriginImg = ApplyLayer(myOriginImg);
	MyImageData::TYPE* myImg = myOriginImg->data;
	if (myImg == nullptr)return;

	int container_width = spC_main->Panel1->Width;
	int container_height = spC_main->Panel1->Height;

	pbox_display->Width = container_width;
	pbox_display->Height = container_height;

	int img_width = myImg->GetWidth();
	int img_height = myImg->GetHeight();

	//calculate photo scale

	float scale = 1, width_scale = 1;

	if (img_height > container_height)
		scale = (float)container_height / (float)img_height;
	if (img_width > container_width)
		width_scale = (float)container_width / (float)img_width;
	if (scale > width_scale)
		scale = width_scale;

	//draw pixel
	Bitmap^ bitmap = gcnew Bitmap(name);
	for(int index_w=0;index_w<img_width;index_w++)
		for (int index_h = 0; index_h < img_height; index_h++) {
			int index_face_w = (int)((float)index_w * scale);
			int index_face_h = (int)((float)index_h * scale);
			bitmap->SetPixel(index_face_w, index_face_h, Color::FromArgb
				(1, myImg->GetPixels(MyImageData::COLOR::R)[index_w][index_h],
					myImg->GetPixels(MyImageData::COLOR::G)[index_w][index_h],
					myImg->GetPixels(MyImageData::COLOR::B)[index_w][index_h]));
		}

	//display
	pbox_display->Image = bitmap;
	pbox_display->Refresh();
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


