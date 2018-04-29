#pragma once

#include "MyImageData.h"
#include "ImageLayer.h"
#include "FilterToLayer.h"
#include "LayerHistogramEqualization.h"
#include "LayerMedianFilter.h"
#include "LayerColorAbjustment.h"
#include "LayerInverse.h"
#include "LayerContractBalance.h"
#include "LayerDCTAndIDCT.h"

namespace NTNUEEPR_WPF {

	//typedef MyImage<unsigned char> MyImageData;
	typedef unsigned char PixelSize;

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();

			Setup();
		}

	protected:
		/// <summary>
		/// ¸Ñºc¤l
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
#pragma region UI Component 
	private: System::Windows::Forms::SplitContainer^  spC_main;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  msitem_loadimage;
	private: System::Windows::Forms::ToolStripMenuItem^  tsitem_loadimgbyfile;
	private: System::Windows::Forms::ToolStripMenuItem^  tsitem_loadimgbyfolder;



	private: System::Windows::Forms::ToolStripMenuItem^  msitem_compareimage;



	private: System::Windows::Forms::PictureBox^  pbox_display;






	private: System::Windows::Forms::SplitContainer^  split_compare;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::ToolStripMenuItem^  msitem_view;

#pragma endregion

	protected:

	protected:

#pragma region My Variable

		MyImage<unsigned char> *baseImage;
		List<MyImageData ^>^ myImages = gcnew List<MyImageData ^>();

		String^ mainImageName;

		List<FilterToLayer^ >^ myLayersTypes = gcnew List<FilterToLayer^>();
		List<FilterToLayer^ >^ myFactLayers = gcnew List<FilterToLayer^>();

		int index_selected_layer = -1;

	private: System::Windows::Forms::SplitContainer^  spC_rightMenu;
	protected:
	private: System::Windows::Forms::PictureBox^  pbox_colorhistogram;
	private: System::Windows::Forms::ToolStrip^  tstrip_layer;
	private: System::Windows::Forms::ToolStripSplitButton^  btn_addlayer;
	private: System::Windows::Forms::ToolStripButton^  btn_removeLayer;
	private: System::Windows::Forms::ToolStripButton^  btn_pushlayer;
	private: System::Windows::Forms::ToolStripButton^  btn_downlayer;
	private: System::Windows::Forms::ListView^  lview_layer;
	private: System::Windows::Forms::ColumnHeader^  col_enable;
	private: System::Windows::Forms::ColumnHeader^  col_name;
	private: System::Diagnostics::Process^  process1;
	private: System::Windows::Forms::Button^  btn_showhistogram;


#pragma region LayerItems
		
#pragma endregion




	protected:

	protected:

	protected:
#pragma endregion

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->spC_main = (gcnew System::Windows::Forms::SplitContainer());
			this->split_compare = (gcnew System::Windows::Forms::SplitContainer());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pbox_display = (gcnew System::Windows::Forms::PictureBox());
			this->spC_rightMenu = (gcnew System::Windows::Forms::SplitContainer());
			this->btn_showhistogram = (gcnew System::Windows::Forms::Button());
			this->pbox_colorhistogram = (gcnew System::Windows::Forms::PictureBox());
			this->tstrip_layer = (gcnew System::Windows::Forms::ToolStrip());
			this->btn_addlayer = (gcnew System::Windows::Forms::ToolStripSplitButton());
			this->btn_removeLayer = (gcnew System::Windows::Forms::ToolStripButton());
			this->btn_pushlayer = (gcnew System::Windows::Forms::ToolStripButton());
			this->btn_downlayer = (gcnew System::Windows::Forms::ToolStripButton());
			this->lview_layer = (gcnew System::Windows::Forms::ListView());
			this->col_enable = (gcnew System::Windows::Forms::ColumnHeader());
			this->col_name = (gcnew System::Windows::Forms::ColumnHeader());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->msitem_loadimage = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tsitem_loadimgbyfile = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tsitem_loadimgbyfolder = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->msitem_compareimage = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->msitem_view = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->process1 = (gcnew System::Diagnostics::Process());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->spC_main))->BeginInit();
			this->spC_main->Panel1->SuspendLayout();
			this->spC_main->Panel2->SuspendLayout();
			this->spC_main->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->split_compare))->BeginInit();
			this->split_compare->Panel1->SuspendLayout();
			this->split_compare->Panel2->SuspendLayout();
			this->split_compare->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbox_display))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->spC_rightMenu))->BeginInit();
			this->spC_rightMenu->Panel1->SuspendLayout();
			this->spC_rightMenu->Panel2->SuspendLayout();
			this->spC_rightMenu->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbox_colorhistogram))->BeginInit();
			this->tstrip_layer->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// spC_main
			// 
			this->spC_main->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->spC_main->Location = System::Drawing::Point(0, 29);
			this->spC_main->Margin = System::Windows::Forms::Padding(3, 20, 3, 3);
			this->spC_main->Name = L"spC_main";
			// 
			// spC_main.Panel1
			// 
			this->spC_main->Panel1->Controls->Add(this->split_compare);
			this->spC_main->Panel1->Controls->Add(this->pbox_display);
			// 
			// spC_main.Panel2
			// 
			this->spC_main->Panel2->Controls->Add(this->spC_rightMenu);
			this->spC_main->Size = System::Drawing::Size(499, 365);
			this->spC_main->SplitterDistance = 299;
			this->spC_main->TabIndex = 0;
			// 
			// split_compare
			// 
			this->split_compare->Location = System::Drawing::Point(3, 0);
			this->split_compare->Name = L"split_compare";
			// 
			// split_compare.Panel1
			// 
			this->split_compare->Panel1->Controls->Add(this->pictureBox1);
			// 
			// split_compare.Panel2
			// 
			this->split_compare->Panel2->Controls->Add(this->pictureBox2);
			this->split_compare->Size = System::Drawing::Size(304, 365);
			this->split_compare->SplitterDistance = 147;
			this->split_compare->TabIndex = 1;
			this->split_compare->Visible = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(28, 172);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(100, 50);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Location = System::Drawing::Point(37, 172);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(100, 50);
			this->pictureBox2->TabIndex = 0;
			this->pictureBox2->TabStop = false;
			// 
			// pbox_display
			// 
			this->pbox_display->ImageLocation = L"";
			this->pbox_display->Location = System::Drawing::Point(0, 0);
			this->pbox_display->Name = L"pbox_display";
			this->pbox_display->Size = System::Drawing::Size(0, 0);
			this->pbox_display->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pbox_display->TabIndex = 0;
			this->pbox_display->TabStop = false;
			// 
			// spC_rightMenu
			// 
			this->spC_rightMenu->Dock = System::Windows::Forms::DockStyle::Fill;
			this->spC_rightMenu->Location = System::Drawing::Point(0, 0);
			this->spC_rightMenu->Name = L"spC_rightMenu";
			this->spC_rightMenu->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// spC_rightMenu.Panel1
			// 
			this->spC_rightMenu->Panel1->Controls->Add(this->btn_showhistogram);
			this->spC_rightMenu->Panel1->Controls->Add(this->pbox_colorhistogram);
			// 
			// spC_rightMenu.Panel2
			// 
			this->spC_rightMenu->Panel2->Controls->Add(this->tstrip_layer);
			this->spC_rightMenu->Panel2->Controls->Add(this->lview_layer);
			this->spC_rightMenu->Size = System::Drawing::Size(196, 365);
			this->spC_rightMenu->SplitterDistance = 69;
			this->spC_rightMenu->TabIndex = 2;
			// 
			// btn_showhistogram
			// 
			this->btn_showhistogram->Dock = System::Windows::Forms::DockStyle::Top;
			this->btn_showhistogram->Location = System::Drawing::Point(0, 0);
			this->btn_showhistogram->Name = L"btn_showhistogram";
			this->btn_showhistogram->Size = System::Drawing::Size(196, 20);
			this->btn_showhistogram->TabIndex = 1;
			this->btn_showhistogram->Text = L"show";
			this->btn_showhistogram->UseVisualStyleBackColor = true;
			// 
			// pbox_colorhistogram
			// 
			this->pbox_colorhistogram->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pbox_colorhistogram->Location = System::Drawing::Point(0, 23);
			this->pbox_colorhistogram->Margin = System::Windows::Forms::Padding(0);
			this->pbox_colorhistogram->Name = L"pbox_colorhistogram";
			this->pbox_colorhistogram->Size = System::Drawing::Size(196, 47);
			this->pbox_colorhistogram->TabIndex = 0;
			this->pbox_colorhistogram->TabStop = false;
			// 
			// tstrip_layer
			// 
			this->tstrip_layer->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->btn_addlayer, this->btn_removeLayer,
					this->btn_pushlayer, this->btn_downlayer
			});
			this->tstrip_layer->Location = System::Drawing::Point(0, 0);
			this->tstrip_layer->Name = L"tstrip_layer";
			this->tstrip_layer->Size = System::Drawing::Size(196, 25);
			this->tstrip_layer->TabIndex = 3;
			this->tstrip_layer->Text = L"toolStrip1";
			// 
			// btn_addlayer
			// 
			this->btn_addlayer->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->btn_addlayer->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_addlayer.Image")));
			this->btn_addlayer->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->btn_addlayer->Name = L"btn_addlayer";
			this->btn_addlayer->Size = System::Drawing::Size(32, 22);
			this->btn_addlayer->Text = L"toolStripSplitButton1";
			this->btn_addlayer->ToolTipText = L"Add filter to this img";
			// 
			// btn_removeLayer
			// 
			this->btn_removeLayer->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->btn_removeLayer->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_removeLayer.Image")));
			this->btn_removeLayer->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->btn_removeLayer->Name = L"btn_removeLayer";
			this->btn_removeLayer->Size = System::Drawing::Size(23, 22);
			this->btn_removeLayer->Text = L"toolStripButton1";
			this->btn_removeLayer->ToolTipText = L"Remove layer to this img";
			this->btn_removeLayer->Click += gcnew System::EventHandler(this, &MyForm::RemoveLayer_Click);
			// 
			// btn_pushlayer
			// 
			this->btn_pushlayer->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->btn_pushlayer->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_pushlayer.Image")));
			this->btn_pushlayer->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->btn_pushlayer->Name = L"btn_pushlayer";
			this->btn_pushlayer->Size = System::Drawing::Size(23, 22);
			this->btn_pushlayer->Text = L"toolStripButton2";
			this->btn_pushlayer->ToolTipText = L"Push filter up";
			this->btn_pushlayer->Click += gcnew System::EventHandler(this, &MyForm::Pushlayer_Click);
			// 
			// btn_downlayer
			// 
			this->btn_downlayer->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->btn_downlayer->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_downlayer.Image")));
			this->btn_downlayer->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->btn_downlayer->Name = L"btn_downlayer";
			this->btn_downlayer->Size = System::Drawing::Size(23, 22);
			this->btn_downlayer->Text = L"toolStripButton3";
			this->btn_downlayer->ToolTipText = L"Pull image down ";
			this->btn_downlayer->Click += gcnew System::EventHandler(this, &MyForm::Downlayer_Click);
			// 
			// lview_layer
			// 
			this->lview_layer->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lview_layer->CheckBoxes = true;
			this->lview_layer->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(2) { this->col_enable, this->col_name });
			this->lview_layer->FullRowSelect = true;
			this->lview_layer->Location = System::Drawing::Point(0, 28);
			this->lview_layer->Name = L"lview_layer";
			this->lview_layer->Size = System::Drawing::Size(193, 264);
			this->lview_layer->TabIndex = 2;
			this->lview_layer->UseCompatibleStateImageBehavior = false;
			this->lview_layer->View = System::Windows::Forms::View::Details;
			this->lview_layer->ItemChecked += gcnew System::Windows::Forms::ItemCheckedEventHandler(this, &MyForm::lview_layer_ItemChecked);
			this->lview_layer->ItemSelectionChanged += gcnew System::Windows::Forms::ListViewItemSelectionChangedEventHandler(this, &MyForm::lview_layer_ItemSelectionChanged);
			// 
			// col_enable
			// 
			this->col_enable->Text = L"Enable";
			// 
			// col_name
			// 
			this->col_name->Text = L"Name";
			this->col_name->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->col_name->Width = 100;
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->msitem_loadimage,
					this->msitem_compareimage, this->msitem_view
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(499, 24);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"mstrip_cmd";
			// 
			// msitem_loadimage
			// 
			this->msitem_loadimage->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->tsitem_loadimgbyfile,
					this->tsitem_loadimgbyfolder
			});
			this->msitem_loadimage->Name = L"msitem_loadimage";
			this->msitem_loadimage->Size = System::Drawing::Size(84, 20);
			this->msitem_loadimage->Text = L"LoadImage";
			// 
			// tsitem_loadimgbyfile
			// 
			this->tsitem_loadimgbyfile->Name = L"tsitem_loadimgbyfile";
			this->tsitem_loadimgbyfile->Size = System::Drawing::Size(110, 22);
			this->tsitem_loadimgbyfile->Text = L"File";
			this->tsitem_loadimgbyfile->Click += gcnew System::EventHandler(this, &MyForm::TSItemLoadImageByFile_Click);
			// 
			// tsitem_loadimgbyfolder
			// 
			this->tsitem_loadimgbyfolder->Name = L"tsitem_loadimgbyfolder";
			this->tsitem_loadimgbyfolder->Size = System::Drawing::Size(110, 22);
			this->tsitem_loadimgbyfolder->Text = L"Folder";
			this->tsitem_loadimgbyfolder->Click += gcnew System::EventHandler(this, &MyForm::TSItemLoadImageByFolder_Click);
			// 
			// msitem_compareimage
			// 
			this->msitem_compareimage->Checked = true;
			this->msitem_compareimage->CheckState = System::Windows::Forms::CheckState::Checked;
			this->msitem_compareimage->Name = L"msitem_compareimage";
			this->msitem_compareimage->Size = System::Drawing::Size(72, 20);
			this->msitem_compareimage->Text = L"Compare";
			this->msitem_compareimage->Click += gcnew System::EventHandler(this, &MyForm::CompareImage_Click);
			// 
			// msitem_view
			// 
			this->msitem_view->Name = L"msitem_view";
			this->msitem_view->Size = System::Drawing::Size(46, 20);
			this->msitem_view->Text = L"View";
			// 
			// process1
			// 
			this->process1->StartInfo->Domain = L"";
			this->process1->StartInfo->LoadUserProfile = false;
			this->process1->StartInfo->Password = nullptr;
			this->process1->StartInfo->StandardErrorEncoding = nullptr;
			this->process1->StartInfo->StandardOutputEncoding = nullptr;
			this->process1->StartInfo->UserName = L"";
			this->process1->SynchronizingObject = this;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(499, 394);
			this->Controls->Add(this->spC_main);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"NTNUEEPR_HW2";
			this->ResizeEnd += gcnew System::EventHandler(this, &MyForm::MyForm_Resize_End);
			this->Resize += gcnew System::EventHandler(this, &MyForm::MyForm_Resize);
			this->spC_main->Panel1->ResumeLayout(false);
			this->spC_main->Panel1->PerformLayout();
			this->spC_main->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->spC_main))->EndInit();
			this->spC_main->ResumeLayout(false);
			this->split_compare->Panel1->ResumeLayout(false);
			this->split_compare->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->split_compare))->EndInit();
			this->split_compare->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbox_display))->EndInit();
			this->spC_rightMenu->Panel1->ResumeLayout(false);
			this->spC_rightMenu->Panel2->ResumeLayout(false);
			this->spC_rightMenu->Panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->spC_rightMenu))->EndInit();
			this->spC_rightMenu->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbox_colorhistogram))->EndInit();
			this->tstrip_layer->ResumeLayout(false);
			this->tstrip_layer->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

#pragma region LifeCycle
	private: System::Void MyForm_Resize_End(System::Object^  sender, System::EventArgs^  e);
	private: System::Void MyForm_Resize(System::Object^  sender, System::EventArgs^  e);
#pragma endregion

			 void Setup();

			 void LoadImageByFile();
			 void LoadImageByFolder();
			 void CompareImage();
			 void AddFilter(int index);
			 void RemoveFilter();
			 void PushFilter();
			 void PullFilter();
			 void OffsetFilter(int offset);

			 MyImageData^ ApplyLayer(MyImageData^ orgin);

			 void ShowMainImageByName(String^ name);
			 void AddImageToMenu(String^ name);

			 MyImageData^ CreateOrGetImage(String^ name);
			 MyImageData^ CalculateModifyImage(String^ name);

			 MyImageData^ FindMyImageByName(String^ name);

			 ToolStripMenuItem^ CreateNewLayerType(FilterToLayer^ layerData);

#pragma region UI Event
	private: System::Void TSItemAddLayer_Click(System::Object^  sender, System::EventArgs^  e) {
		ToolStripMenuItem^ item = ((ToolStripMenuItem^)sender );
		if (item != nullptr)
		{
			AddFilter(int::Parse(item->Name));
		}
	}

	private: System::Void TSItemLoadImageByFile_Click(System::Object^  sender, System::EventArgs^  e) {
		LoadImageByFile();
	}
	private: System::Void TSItemLoadImageByFolder_Click(System::Object^  sender, System::EventArgs^  e) {
		LoadImageByFolder();
	}
	private: System::Void RemoveLayer_Click(System::Object^  sender, System::EventArgs^  e) {
		RemoveFilter();
	}
	private: System::Void Pushlayer_Click(System::Object^  sender, System::EventArgs^  e) {
		PushFilter();
	}
	private: System::Void Downlayer_Click(System::Object^  sender, System::EventArgs^  e) {
		PullFilter();
	}
	private: System::Void CompareImage_Click(System::Object^  sender, System::EventArgs^  e) {
		CompareImage();
	}
	private: System::Void tstrip_layer_ItemClicked(System::Object^  sender, System::Windows::Forms::ToolStripItemClickedEventArgs^  e) {
	}

			 //menu strip item event
	private: System::Void ViewItem_Click(System::Object^  sender, System::EventArgs^  e);

	private: System::Void lview_layer_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		
	}

	private: System::Void lview_layer_ItemChecked(System::Object^  sender, System::Windows::Forms::ItemCheckedEventArgs^  e);
	private: System::Void lview_layer_ItemSelectionChanged(System::Object^  sender, System::Windows::Forms::ListViewItemSelectionChangedEventArgs^  e);
#pragma endregion




};
}
