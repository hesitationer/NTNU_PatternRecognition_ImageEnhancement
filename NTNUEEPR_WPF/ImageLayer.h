#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace NTNUEEPR_WPF {

	/// <summary>
	/// Summary for ImageLayer
	/// </summary>
	public ref class ImageLayer : public System::Windows::Forms::ListViewItem
	{
	public:

	 System::Windows::Forms::CheckBox^  cbox_visable;
	 System::Windows::Forms::TextBox^  tbox_layername;

	 void Setup(void)
	 {
		 this->cbox_visable = (gcnew System::Windows::Forms::CheckBox());
		 this->tbox_layername = (gcnew System::Windows::Forms::TextBox());
		 // 
		 // cbox_visable
		 // 
		 this->cbox_visable->AutoSize = true;
		 this->cbox_visable->Location = System::Drawing::Point(15, 17);
		 this->cbox_visable->Name = L"cbox_visable";
		 this->cbox_visable->Size = System::Drawing::Size(56, 16);
		 this->cbox_visable->TabIndex = 0;
		 this->cbox_visable->Text = L"visable";
		 this->cbox_visable->UseVisualStyleBackColor = true;
		 // 
		 // tbox_layername
		 // 
		 this->tbox_layername->Location = System::Drawing::Point(77, 15);
		 this->tbox_layername->MaxLength = 10;
		 this->tbox_layername->Name = L"tbox_layername";
		 this->tbox_layername->ReadOnly = true;
		 this->tbox_layername->Size = System::Drawing::Size(104, 22);
		 this->tbox_layername->TabIndex = 1;
		 this->tbox_layername->Text = L"Layer";

	 }

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ImageLayer()
		{
			if (components)
			{
				delete components;
			}
		}
	protected:

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
		
#pragma endregion
	};
}
