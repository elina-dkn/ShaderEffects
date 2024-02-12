#pragma once

namespace Week1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ToolWindow
	/// </summary>
	public ref class ToolWindow : public System::Windows::Forms::Form
	{
	public:
	public:
		static int Rchannel;
		static int Gchannel;
		static int Bchannel;
		static int Schannel;
		static int option;
		static bool resetLight;
		static bool resetTeapot;
	private: System::Windows::Forms::RadioButton^ option1;
	public:
	private: System::Windows::Forms::RadioButton^ option2;
	private: System::Windows::Forms::RadioButton^ option3;
	private: System::Windows::Forms::Button^ reset_light;
	private: System::Windows::Forms::Button^ reset_teapot;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TrackBar^ trackBar1;
	private: System::Windows::Forms::TrackBar^ trackBar2;
	private: System::Windows::Forms::TrackBar^ trackBar3;
	private: System::Windows::Forms::TrackBar^ trackBar4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ specular_label;
	private: System::Windows::Forms::Label^ r_label;
	private: System::Windows::Forms::Label^ g_label;
	private: System::Windows::Forms::Label^ b_label;
		   //static bool RenderBlueChannel;
	



	public:
		ToolWindow(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			Schannel = trackBar1->Value;
			Rchannel = trackBar2->Value;
			Gchannel = trackBar4->Value;
			Bchannel = trackBar3->Value;
			resetLight = false;
			resetTeapot = false;
			option = 0;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ToolWindow()
		{
			if (components)
			{
				delete components;
			}
		}

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
			this->option1 = (gcnew System::Windows::Forms::RadioButton());
			this->option2 = (gcnew System::Windows::Forms::RadioButton());
			this->option3 = (gcnew System::Windows::Forms::RadioButton());
			this->reset_light = (gcnew System::Windows::Forms::Button());
			this->reset_teapot = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->trackBar2 = (gcnew System::Windows::Forms::TrackBar());
			this->trackBar3 = (gcnew System::Windows::Forms::TrackBar());
			this->trackBar4 = (gcnew System::Windows::Forms::TrackBar());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->specular_label = (gcnew System::Windows::Forms::Label());
			this->r_label = (gcnew System::Windows::Forms::Label());
			this->g_label = (gcnew System::Windows::Forms::Label());
			this->b_label = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar4))->BeginInit();
			this->SuspendLayout();
			// 
			// option1
			// 
			this->option1->AutoSize = true;
			this->option1->Checked = true;
			this->option1->Location = System::Drawing::Point(10, 20);
			this->option1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->option1->Name = L"option1";
			this->option1->Size = System::Drawing::Size(78, 17);
			this->option1->TabIndex = 0;
			this->option1->TabStop = true;
			this->option1->Text = L"Move Light";
			this->option1->UseVisualStyleBackColor = true;
			this->option1->Click += gcnew System::EventHandler(this, &ToolWindow::option1_Click);
			// 
			// option2
			// 
			this->option2->AutoSize = true;
			this->option2->Location = System::Drawing::Point(10, 245);
			this->option2->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->option2->Name = L"option2";
			this->option2->Size = System::Drawing::Size(104, 17);
			this->option2->TabIndex = 1;
			this->option2->Text = L"Color By Position";
			this->option2->UseVisualStyleBackColor = true;
			this->option2->Click += gcnew System::EventHandler(this, &ToolWindow::option2_Click);
			// 
			// option3
			// 
			this->option3->AutoSize = true;
			this->option3->Location = System::Drawing::Point(9, 310);
			this->option3->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->option3->Name = L"option3";
			this->option3->Size = System::Drawing::Size(138, 17);
			this->option3->TabIndex = 2;
			this->option3->Text = L"Move Cubes To Sphere";
			this->option3->UseVisualStyleBackColor = true;
			this->option3->Click += gcnew System::EventHandler(this, &ToolWindow::option3_Click);
			// 
			// reset_light
			// 
			this->reset_light->Location = System::Drawing::Point(10, 42);
			this->reset_light->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->reset_light->Name = L"reset_light";
			this->reset_light->Size = System::Drawing::Size(128, 19);
			this->reset_light->TabIndex = 3;
			this->reset_light->Text = L"Reset Light Position";
			this->reset_light->UseVisualStyleBackColor = true;
			this->reset_light->Click += gcnew System::EventHandler(this, &ToolWindow::reset_light_Click);
			// 
			// reset_teapot
			// 
			this->reset_teapot->Location = System::Drawing::Point(10, 279);
			this->reset_teapot->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->reset_teapot->Name = L"reset_teapot";
			this->reset_teapot->Size = System::Drawing::Size(128, 19);
			this->reset_teapot->TabIndex = 4;
			this->reset_teapot->Text = L"Reset Teapot Position";
			this->reset_teapot->UseVisualStyleBackColor = true;
			this->reset_teapot->Click += gcnew System::EventHandler(this, &ToolWindow::reset_teapot_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(9, 72);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(92, 13);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Specular Strength";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(9, 105);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(76, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Specular Color";
			// 
			// trackBar1
			// 
			this->trackBar1->Location = System::Drawing::Point(112, 66);
			this->trackBar1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->trackBar1->Maximum = 128;
			this->trackBar1->Minimum = 1;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(314, 45);
			this->trackBar1->TabIndex = 7;
			this->trackBar1->Value = 4;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &ToolWindow::trackBar1_Scroll);
			this->trackBar1->ValueChanged += gcnew System::EventHandler(this, &ToolWindow::trackBar1_ValueChanged);
			// 
			// trackBar2
			// 
			this->trackBar2->Location = System::Drawing::Point(112, 116);
			this->trackBar2->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->trackBar2->Maximum = 300;
			this->trackBar2->Name = L"trackBar2";
			this->trackBar2->Size = System::Drawing::Size(314, 45);
			this->trackBar2->TabIndex = 8;
			this->trackBar2->Value = 100;
			this->trackBar2->Scroll += gcnew System::EventHandler(this, &ToolWindow::trackBar2_Scroll);
			this->trackBar2->ValueChanged += gcnew System::EventHandler(this, &ToolWindow::trackBar2_ValueChanged);
			// 
			// trackBar3
			// 
			this->trackBar3->Location = System::Drawing::Point(112, 206);
			this->trackBar3->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->trackBar3->Maximum = 300;
			this->trackBar3->Name = L"trackBar3";
			this->trackBar3->Size = System::Drawing::Size(314, 45);
			this->trackBar3->TabIndex = 9;
			this->trackBar3->Value = 100;
			this->trackBar3->Scroll += gcnew System::EventHandler(this, &ToolWindow::trackBar3_Scroll);
			this->trackBar3->ValueChanged += gcnew System::EventHandler(this, &ToolWindow::trackBar3_ValueChanged);
			// 
			// trackBar4
			// 
			this->trackBar4->Location = System::Drawing::Point(112, 155);
			this->trackBar4->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->trackBar4->Maximum = 300;
			this->trackBar4->Name = L"trackBar4";
			this->trackBar4->Size = System::Drawing::Size(314, 45);
			this->trackBar4->TabIndex = 10;
			this->trackBar4->Value = 100;
			this->trackBar4->Scroll += gcnew System::EventHandler(this, &ToolWindow::trackBar4_Scroll);
			this->trackBar4->ValueChanged += gcnew System::EventHandler(this, &ToolWindow::trackBar4_ValueChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(94, 206);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(14, 13);
			this->label3->TabIndex = 11;
			this->label3->Text = L"B";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(94, 164);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(15, 13);
			this->label4->TabIndex = 12;
			this->label4->Text = L"G";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(94, 124);
			this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(15, 13);
			this->label5->TabIndex = 13;
			this->label5->Text = L"R";
			// 
			// specular_label
			// 
			this->specular_label->AutoSize = true;
			this->specular_label->Location = System::Drawing::Point(441, 72);
			this->specular_label->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->specular_label->Name = L"specular_label";
			this->specular_label->Size = System::Drawing::Size(13, 13);
			this->specular_label->TabIndex = 14;
			this->specular_label->Text = L"4";
			// 
			// r_label
			// 
			this->r_label->AutoSize = true;
			this->r_label->Location = System::Drawing::Point(441, 124);
			this->r_label->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->r_label->Name = L"r_label";
			this->r_label->Size = System::Drawing::Size(28, 13);
			this->r_label->TabIndex = 15;
			this->r_label->Text = L"1.00";
			// 
			// g_label
			// 
			this->g_label->AutoSize = true;
			this->g_label->Location = System::Drawing::Point(441, 164);
			this->g_label->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->g_label->Name = L"g_label";
			this->g_label->Size = System::Drawing::Size(28, 13);
			this->g_label->TabIndex = 16;
			this->g_label->Text = L"1.00";
			// 
			// b_label
			// 
			this->b_label->AutoSize = true;
			this->b_label->Location = System::Drawing::Point(441, 206);
			this->b_label->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->b_label->Name = L"b_label";
			this->b_label->Size = System::Drawing::Size(28, 13);
			this->b_label->TabIndex = 17;
			this->b_label->Text = L"1.00";
			// 
			// ToolWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(472, 336);
			this->Controls->Add(this->b_label);
			this->Controls->Add(this->g_label);
			this->Controls->Add(this->r_label);
			this->Controls->Add(this->specular_label);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->trackBar4);
			this->Controls->Add(this->trackBar3);
			this->Controls->Add(this->trackBar2);
			this->Controls->Add(this->trackBar1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->reset_teapot);
			this->Controls->Add(this->reset_light);
			this->Controls->Add(this->option3);
			this->Controls->Add(this->option2);
			this->Controls->Add(this->option1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"ToolWindow";
			this->Text = L"ToolWindow";
			this->TopMost = true;
			this->Load += gcnew System::EventHandler(this, &ToolWindow::ToolWindow_Load);
			this->MouseLeave += gcnew System::EventHandler(this, &ToolWindow::ToolWindow_MouseLeave);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar4))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void ToolWindow_Load(System::Object^ sender, System::EventArgs^ e) {
		
	}

private: System::Void trackBar1_Scroll(System::Object^ sender, System::EventArgs^ e) {
	Schannel = trackBar1->Value;
}
private: System::Void trackBar2_Scroll(System::Object^ sender, System::EventArgs^ e) {
	Rchannel = trackBar2->Value;
}
private: System::Void trackBar4_Scroll(System::Object^ sender, System::EventArgs^ e) {
	Gchannel = trackBar4->Value;
}
private: System::Void trackBar3_Scroll(System::Object^ sender, System::EventArgs^ e) {
	Bchannel = trackBar3->Value;
}
private: System::Void trackBar1_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	specular_label->Text = trackBar1->Value.ToString();
}
private: System::Void trackBar2_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	r_label->Text = ((float)trackBar2->Value / 100).ToString();
}
private: System::Void trackBar4_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	g_label->Text = ((float)trackBar4->Value / 100).ToString();
}
private: System::Void trackBar3_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	b_label->Text = ((float)trackBar3->Value / 100).ToString();
}
private: System::Void option1_Click(System::Object^ sender, System::EventArgs^ e) {
	option = 1;
}

private: System::Void option2_Click(System::Object^ sender, System::EventArgs^ e) {
	option = 2;
}
private: System::Void option3_Click(System::Object^ sender, System::EventArgs^ e) {
	option = 3;
}
private: System::Void reset_light_Click(System::Object^ sender, System::EventArgs^ e) {
	resetLight = true;
}
private: System::Void reset_teapot_Click(System::Object^ sender, System::EventArgs^ e) {
	resetTeapot = true;
}
private: System::Void ToolWindow_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
	resetLight = false;
	resetTeapot = false;
}
};
}
