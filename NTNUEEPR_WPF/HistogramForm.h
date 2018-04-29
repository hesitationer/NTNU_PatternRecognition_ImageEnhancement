#pragma once

namespace NTNUEEPR_WPF {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for HistogramForm
	/// </summary>
	public ref class HistogramForm : public System::Windows::Forms::Form
	{
	public:
		HistogramForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~HistogramForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pbox_red;
	protected:

	private: System::Windows::Forms::CheckBox^  cbox_red;

	private: System::Windows::Forms::CheckBox^  cbox_green;

	private: System::Windows::Forms::CheckBox^  cbox_blue;

	private: System::Windows::Forms::Label^  lbl_color;
	private: System::Windows::Forms::PictureBox^  pbox_blue;

	private: System::Windows::Forms::PictureBox^  pbox_green;
	protected:

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
		void InitializeComponent(void)
		{
			this->pbox_red = (gcnew System::Windows::Forms::PictureBox());
			this->cbox_red = (gcnew System::Windows::Forms::CheckBox());
			this->cbox_green = (gcnew System::Windows::Forms::CheckBox());
			this->cbox_blue = (gcnew System::Windows::Forms::CheckBox());
			this->lbl_color = (gcnew System::Windows::Forms::Label());
			this->pbox_blue = (gcnew System::Windows::Forms::PictureBox());
			this->pbox_green = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbox_red))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbox_blue))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbox_green))->BeginInit();
			this->SuspendLayout();
			// 
			// pbox_red
			// 
			this->pbox_red->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pbox_red->BackColor = System::Drawing::Color::Transparent;
			this->pbox_red->Location = System::Drawing::Point(12, 49);
			this->pbox_red->Name = L"pbox_red";
			this->pbox_red->Size = System::Drawing::Size(260, 200);
			this->pbox_red->TabIndex = 0;
			this->pbox_red->TabStop = false;
			// 
			// cbox_red
			// 
			this->cbox_red->AutoSize = true;
			this->cbox_red->Location = System::Drawing::Point(12, 27);
			this->cbox_red->Name = L"cbox_red";
			this->cbox_red->Size = System::Drawing::Size(43, 16);
			this->cbox_red->TabIndex = 1;
			this->cbox_red->Text = L"Red";
			this->cbox_red->UseVisualStyleBackColor = true;
			this->cbox_red->CheckedChanged += gcnew System::EventHandler(this, &HistogramForm::Red_CheckedChanged);
			// 
			// cbox_green
			// 
			this->cbox_green->AutoSize = true;
			this->cbox_green->Location = System::Drawing::Point(95, 27);
			this->cbox_green->Name = L"cbox_green";
			this->cbox_green->Size = System::Drawing::Size(52, 16);
			this->cbox_green->TabIndex = 2;
			this->cbox_green->Text = L"Green";
			this->cbox_green->UseVisualStyleBackColor = true;
			this->cbox_green->CheckedChanged += gcnew System::EventHandler(this, &HistogramForm::Green_CheckedChanged);
			// 
			// cbox_blue
			// 
			this->cbox_blue->AutoSize = true;
			this->cbox_blue->Location = System::Drawing::Point(178, 27);
			this->cbox_blue->Name = L"cbox_blue";
			this->cbox_blue->Size = System::Drawing::Size(46, 16);
			this->cbox_blue->TabIndex = 3;
			this->cbox_blue->Text = L"Blue";
			this->cbox_blue->UseVisualStyleBackColor = true;
			this->cbox_blue->CheckedChanged += gcnew System::EventHandler(this, &HistogramForm::Blue_CheckedChanged);
			// 
			// lbl_color
			// 
			this->lbl_color->AutoSize = true;
			this->lbl_color->Location = System::Drawing::Point(12, 9);
			this->lbl_color->Name = L"lbl_color";
			this->lbl_color->Size = System::Drawing::Size(67, 12);
			this->lbl_color->TabIndex = 4;
			this->lbl_color->Text = L"Shown Color";
			// 
			// pbox_blue
			// 
			this->pbox_blue->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pbox_blue->BackColor = System::Drawing::Color::Transparent;
			this->pbox_blue->Location = System::Drawing::Point(12, 49);
			this->pbox_blue->Name = L"pbox_blue";
			this->pbox_blue->Size = System::Drawing::Size(260, 200);
			this->pbox_blue->TabIndex = 5;
			this->pbox_blue->TabStop = false;
			// 
			// pbox_green
			// 
			this->pbox_green->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pbox_green->BackColor = System::Drawing::Color::Transparent;
			this->pbox_green->Location = System::Drawing::Point(12, 49);
			this->pbox_green->Name = L"pbox_green";
			this->pbox_green->Size = System::Drawing::Size(260, 200);
			this->pbox_green->TabIndex = 6;
			this->pbox_green->TabStop = false;
			// 
			// HistogramForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->pbox_green);
			this->Controls->Add(this->pbox_blue);
			this->Controls->Add(this->lbl_color);
			this->Controls->Add(this->cbox_blue);
			this->Controls->Add(this->cbox_green);
			this->Controls->Add(this->cbox_red);
			this->Controls->Add(this->pbox_red);
			this->Name = L"HistogramForm";
			this->Text = L"HistogramForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbox_red))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbox_blue))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbox_green))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	public: 
		void SetHistogram(int* histogram,int length,int max,PictureBox^ pbox) {
			int unit_width = pbox->Width / length;
			int unit_width_counter = 0;
			Bitmap^ bitmap = gcnew Bitmap(pbox->Width,pbox->Height, Drawing::Imaging::PixelFormat::Format32bppRgb);
			for (int index = 0; index < length;index++) {
				for (; unit_width_counter < unit_width*index; unit_width_counter++) {
					//int uint_height = pbox->Height / max;
					//for (; uint_height_counter < uint_height*index;uint_height_counter++) {
					//	bitmap->SetPixel(unit_width_counter,unit_h,histogram[index]);
					//}
				}
			}
		}

	private: System::Void Blue_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		if (cbox_blue->Checked)
			pbox_blue->Show();
		else
			pbox_blue->Hide();
	}
	private: System::Void Red_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		if (cbox_red->Checked)
			pbox_red->Show();
		else
			pbox_red->Hide();
	}
	private: System::Void Green_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		if (cbox_green->Checked)
			pbox_green->Show();
		else
			pbox_green->Hide();
	}
};
}
