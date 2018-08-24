#pragma once

namespace MarsLander1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
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
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  lba1;
	private: System::Windows::Forms::Label^  lba2;
	private: System::Windows::Forms::Label^  lba3;
	private: System::Windows::Forms::Label^  lbdr1;
	private: System::Windows::Forms::Label^  lbdr2;
	private: System::Windows::Forms::Label^  lbdr3;
	private: System::Windows::Forms::Label^  lbdr4;
	private: System::Windows::Forms::Label^  lbar;
	protected: 

	protected: 

	protected: 















	private: System::Windows::Forms::Label^  lbtts1;
	private: System::Windows::Forms::Label^  lbts2;
	private: System::Windows::Forms::Label^  lbsg1;
	private: System::Windows::Forms::Label^  lbsg2;
	private: System::Windows::Forms::Label^  lbsg3;
	private: System::Windows::Forms::Label^  lbore1;
	private: System::Windows::Forms::Label^  lbore2;
	private: System::Windows::Forms::Label^  lbore3;
	private: System::Windows::Forms::Label^  lbate1;
















	protected: 

	protected: 
















	private: System::Windows::Forms::Label^  label18;
	private: System::Windows::Forms::TextBox^  txta1;
	private: System::Windows::Forms::TextBox^  txta2;
	private: System::Windows::Forms::TextBox^  txta3;
	private: System::Windows::Forms::TextBox^  txtdr1;
	private: System::Windows::Forms::TextBox^  txtdr2;
	private: System::Windows::Forms::TextBox^  txtdr4;












	private: System::Windows::Forms::TextBox^  txtdr3;
	private: System::Windows::Forms::TextBox^  txtar;
	private: System::Windows::Forms::TextBox^  txtts1;
	private: System::Windows::Forms::TextBox^  txtts2;
	private: System::Windows::Forms::TextBox^  txtsg1;
	private: System::Windows::Forms::TextBox^  txtsg2;
	private: System::Windows::Forms::TextBox^  txtsg3;
	private: System::Windows::Forms::TextBox^  txtore1;
private: System::Windows::Forms::TextBox^  txtore2;
private: System::Windows::Forms::TextBox^  txtore3;
private: System::Windows::Forms::TextBox^  txtate1;
private: System::Windows::Forms::TextBox^  txtate2;
private: System::Windows::Forms::Label^  lbate2;
private: System::Windows::Forms::Label^  lbate3;
private: System::Windows::Forms::Label^  lbpra;

















private: System::Windows::Forms::TextBox^  txtate3;
private: System::Windows::Forms::TextBox^  txtpra;
private: System::Windows::Forms::TextBox^  txtts;
private: System::Windows::Forms::Label^  lbts;
private: System::Windows::Forms::Button^  button1;
private: System::Windows::Forms::Button^  button2;
private: System::Windows::Forms::Button^  button3;





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
			this->lba1 = (gcnew System::Windows::Forms::Label());
			this->lba2 = (gcnew System::Windows::Forms::Label());
			this->lba3 = (gcnew System::Windows::Forms::Label());
			this->lbdr1 = (gcnew System::Windows::Forms::Label());
			this->lbdr2 = (gcnew System::Windows::Forms::Label());
			this->lbdr3 = (gcnew System::Windows::Forms::Label());
			this->lbdr4 = (gcnew System::Windows::Forms::Label());
			this->lbar = (gcnew System::Windows::Forms::Label());
			this->lbtts1 = (gcnew System::Windows::Forms::Label());
			this->lbts2 = (gcnew System::Windows::Forms::Label());
			this->lbsg1 = (gcnew System::Windows::Forms::Label());
			this->lbsg2 = (gcnew System::Windows::Forms::Label());
			this->lbsg3 = (gcnew System::Windows::Forms::Label());
			this->lbore1 = (gcnew System::Windows::Forms::Label());
			this->lbore2 = (gcnew System::Windows::Forms::Label());
			this->lbore3 = (gcnew System::Windows::Forms::Label());
			this->lbate1 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->txta1 = (gcnew System::Windows::Forms::TextBox());
			this->txta2 = (gcnew System::Windows::Forms::TextBox());
			this->txta3 = (gcnew System::Windows::Forms::TextBox());
			this->txtdr1 = (gcnew System::Windows::Forms::TextBox());
			this->txtdr2 = (gcnew System::Windows::Forms::TextBox());
			this->txtdr4 = (gcnew System::Windows::Forms::TextBox());
			this->txtdr3 = (gcnew System::Windows::Forms::TextBox());
			this->txtar = (gcnew System::Windows::Forms::TextBox());
			this->txtts1 = (gcnew System::Windows::Forms::TextBox());
			this->txtts2 = (gcnew System::Windows::Forms::TextBox());
			this->txtsg1 = (gcnew System::Windows::Forms::TextBox());
			this->txtsg2 = (gcnew System::Windows::Forms::TextBox());
			this->txtsg3 = (gcnew System::Windows::Forms::TextBox());
			this->txtore1 = (gcnew System::Windows::Forms::TextBox());
			this->txtore2 = (gcnew System::Windows::Forms::TextBox());
			this->txtore3 = (gcnew System::Windows::Forms::TextBox());
			this->txtate1 = (gcnew System::Windows::Forms::TextBox());
			this->txtate2 = (gcnew System::Windows::Forms::TextBox());
			this->lbate2 = (gcnew System::Windows::Forms::Label());
			this->lbate3 = (gcnew System::Windows::Forms::Label());
			this->lbpra = (gcnew System::Windows::Forms::Label());
			this->txtate3 = (gcnew System::Windows::Forms::TextBox());
			this->txtpra = (gcnew System::Windows::Forms::TextBox());
			this->txtts = (gcnew System::Windows::Forms::TextBox());
			this->lbts = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// lba1
			// 
			this->lba1->AutoSize = true;
			this->lba1->Location = System::Drawing::Point(30, 9);
			this->lba1->Name = L"lba1";
			this->lba1->Size = System::Drawing::Size(84, 13);
			this->lba1->TabIndex = 0;
			this->lba1->Text = L"Accelerometer 1";
			this->lba1->Click += gcnew System::EventHandler(this, &Form1::lba1_Click);
			// 
			// lba2
			// 
			this->lba2->AutoSize = true;
			this->lba2->Location = System::Drawing::Point(30, 32);
			this->lba2->Name = L"lba2";
			this->lba2->Size = System::Drawing::Size(84, 13);
			this->lba2->TabIndex = 1;
			this->lba2->Text = L"Accelerometer 2";
			this->lba2->Click += gcnew System::EventHandler(this, &Form1::lba2_Click);
			// 
			// lba3
			// 
			this->lba3->AutoSize = true;
			this->lba3->Location = System::Drawing::Point(30, 57);
			this->lba3->Name = L"lba3";
			this->lba3->Size = System::Drawing::Size(84, 13);
			this->lba3->TabIndex = 2;
			this->lba3->Text = L"Accelerometer 3";
			this->lba3->Click += gcnew System::EventHandler(this, &Form1::lba3_Click);
			// 
			// lbdr1
			// 
			this->lbdr1->AutoSize = true;
			this->lbdr1->Location = System::Drawing::Point(30, 74);
			this->lbdr1->Name = L"lbdr1";
			this->lbdr1->Size = System::Drawing::Size(85, 13);
			this->lbdr1->TabIndex = 3;
			this->lbdr1->Text = L"Doppler Radar 1";
			this->lbdr1->Click += gcnew System::EventHandler(this, &Form1::lbdr1_Click);
			// 
			// lbdr2
			// 
			this->lbdr2->AutoSize = true;
			this->lbdr2->Location = System::Drawing::Point(30, 97);
			this->lbdr2->Name = L"lbdr2";
			this->lbdr2->Size = System::Drawing::Size(85, 13);
			this->lbdr2->TabIndex = 4;
			this->lbdr2->Text = L"Doppler Radar 2";
			this->lbdr2->Click += gcnew System::EventHandler(this, &Form1::lbdr2_Click);
			// 
			// lbdr3
			// 
			this->lbdr3->AutoSize = true;
			this->lbdr3->Location = System::Drawing::Point(30, 119);
			this->lbdr3->Name = L"lbdr3";
			this->lbdr3->Size = System::Drawing::Size(85, 13);
			this->lbdr3->TabIndex = 5;
			this->lbdr3->Text = L"Doppler Radar 3";
			this->lbdr3->Click += gcnew System::EventHandler(this, &Form1::label6_Click);
			// 
			// lbdr4
			// 
			this->lbdr4->AutoSize = true;
			this->lbdr4->Location = System::Drawing::Point(30, 138);
			this->lbdr4->Name = L"lbdr4";
			this->lbdr4->Size = System::Drawing::Size(85, 13);
			this->lbdr4->TabIndex = 6;
			this->lbdr4->Text = L"Doppler Radar 4";
			this->lbdr4->Click += gcnew System::EventHandler(this, &Form1::lbdr4_Click);
			// 
			// lbar
			// 
			this->lbar->AutoSize = true;
			this->lbar->Location = System::Drawing::Point(30, 154);
			this->lbar->Name = L"lbar";
			this->lbar->Size = System::Drawing::Size(74, 13);
			this->lbar->TabIndex = 7;
			this->lbar->Text = L"Altimeter radar";
			this->lbar->Click += gcnew System::EventHandler(this, &Form1::lbar_Click);
			// 
			// lbtts1
			// 
			this->lbtts1->AutoSize = true;
			this->lbtts1->Location = System::Drawing::Point(30, 173);
			this->lbtts1->Name = L"lbtts1";
			this->lbtts1->Size = System::Drawing::Size(110, 13);
			this->lbtts1->TabIndex = 8;
			this->lbtts1->Text = L"Temperature sensor 1";
			this->lbtts1->Click += gcnew System::EventHandler(this, &Form1::lbtts1_Click);
			// 
			// lbts2
			// 
			this->lbts2->AutoSize = true;
			this->lbts2->Location = System::Drawing::Point(30, 193);
			this->lbts2->Name = L"lbts2";
			this->lbts2->Size = System::Drawing::Size(110, 13);
			this->lbts2->TabIndex = 9;
			this->lbts2->Text = L"Temperature sensor 2";
			this->lbts2->Click += gcnew System::EventHandler(this, &Form1::lbts2_Click);
			// 
			// lbsg1
			// 
			this->lbsg1->AutoSize = true;
			this->lbsg1->Location = System::Drawing::Point(30, 216);
			this->lbsg1->Name = L"lbsg1";
			this->lbsg1->Size = System::Drawing::Size(137, 13);
			this->lbsg1->TabIndex = 10;
			this->lbsg1->Text = L"Strappeddown gyroscope 1";
			this->lbsg1->Click += gcnew System::EventHandler(this, &Form1::lbsg1_Click);
			// 
			// lbsg2
			// 
			this->lbsg2->AutoSize = true;
			this->lbsg2->Location = System::Drawing::Point(30, 235);
			this->lbsg2->Name = L"lbsg2";
			this->lbsg2->Size = System::Drawing::Size(137, 13);
			this->lbsg2->TabIndex = 11;
			this->lbsg2->Text = L"Strappeddown gyroscope 2";
			this->lbsg2->Click += gcnew System::EventHandler(this, &Form1::lbsg2_Click);
			// 
			// lbsg3
			// 
			this->lbsg3->AutoSize = true;
			this->lbsg3->Location = System::Drawing::Point(30, 251);
			this->lbsg3->Name = L"lbsg3";
			this->lbsg3->Size = System::Drawing::Size(137, 13);
			this->lbsg3->TabIndex = 12;
			this->lbsg3->Text = L"Strappeddown gyroscope 3";
			this->lbsg3->Click += gcnew System::EventHandler(this, &Form1::lbsg3_Click);
			// 
			// lbore1
			// 
			this->lbore1->AutoSize = true;
			this->lbore1->Location = System::Drawing::Point(30, 267);
			this->lbore1->Name = L"lbore1";
			this->lbore1->Size = System::Drawing::Size(110, 13);
			this->lbore1->TabIndex = 13;
			this->lbore1->Text = L"Opposed roll engine 1";
			this->lbore1->Click += gcnew System::EventHandler(this, &Form1::lbore1_Click);
			// 
			// lbore2
			// 
			this->lbore2->AutoSize = true;
			this->lbore2->Location = System::Drawing::Point(30, 293);
			this->lbore2->Name = L"lbore2";
			this->lbore2->Size = System::Drawing::Size(110, 13);
			this->lbore2->TabIndex = 14;
			this->lbore2->Text = L"Opposed roll engine 2";
			this->lbore2->Click += gcnew System::EventHandler(this, &Form1::lbore2_Click);
			// 
			// lbore3
			// 
			this->lbore3->AutoSize = true;
			this->lbore3->Location = System::Drawing::Point(30, 310);
			this->lbore3->Name = L"lbore3";
			this->lbore3->Size = System::Drawing::Size(110, 13);
			this->lbore3->TabIndex = 15;
			this->lbore3->Text = L"Opposed roll engine 3";
			this->lbore3->Click += gcnew System::EventHandler(this, &Form1::lbore3_Click);
			// 
			// lbate1
			// 
			this->lbate1->AutoSize = true;
			this->lbate1->Location = System::Drawing::Point(30, 336);
			this->lbate1->Name = L"lbate1";
			this->lbate1->Size = System::Drawing::Size(102, 13);
			this->lbate1->TabIndex = 16;
			this->lbate1->Text = L"Axial thrust engine 1";
			this->lbate1->Click += gcnew System::EventHandler(this, &Form1::lbate1_Click);
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(30, 360);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(0, 13);
			this->label18->TabIndex = 17;
			// 
			// txta1
			// 
			this->txta1->Location = System::Drawing::Point(186, 12);
			this->txta1->Name = L"txta1";
			this->txta1->ReadOnly = true;
			this->txta1->Size = System::Drawing::Size(100, 20);
			this->txta1->TabIndex = 18;
			this->txta1->TextChanged += gcnew System::EventHandler(this, &Form1::txta1_TextChanged);
			// 
			// txta2
			// 
			this->txta2->Location = System::Drawing::Point(186, 35);
			this->txta2->Name = L"txta2";
			this->txta2->ReadOnly = true;
			this->txta2->Size = System::Drawing::Size(100, 20);
			this->txta2->TabIndex = 19;
			// 
			// txta3
			// 
			this->txta3->Location = System::Drawing::Point(186, 57);
			this->txta3->Name = L"txta3";
			this->txta3->ReadOnly = true;
			this->txta3->Size = System::Drawing::Size(100, 20);
			this->txta3->TabIndex = 20;
			// 
			// txtdr1
			// 
			this->txtdr1->Location = System::Drawing::Point(186, 77);
			this->txtdr1->Name = L"txtdr1";
			this->txtdr1->ReadOnly = true;
			this->txtdr1->Size = System::Drawing::Size(100, 20);
			this->txtdr1->TabIndex = 21;
			// 
			// txtdr2
			// 
			this->txtdr2->Location = System::Drawing::Point(186, 99);
			this->txtdr2->Name = L"txtdr2";
			this->txtdr2->ReadOnly = true;
			this->txtdr2->Size = System::Drawing::Size(100, 20);
			this->txtdr2->TabIndex = 22;
			// 
			// txtdr4
			// 
			this->txtdr4->Location = System::Drawing::Point(186, 141);
			this->txtdr4->Name = L"txtdr4";
			this->txtdr4->ReadOnly = true;
			this->txtdr4->Size = System::Drawing::Size(100, 20);
			this->txtdr4->TabIndex = 23;
			// 
			// txtdr3
			// 
			this->txtdr3->Location = System::Drawing::Point(186, 122);
			this->txtdr3->Name = L"txtdr3";
			this->txtdr3->ReadOnly = true;
			this->txtdr3->Size = System::Drawing::Size(100, 20);
			this->txtdr3->TabIndex = 24;
			// 
			// txtar
			// 
			this->txtar->Location = System::Drawing::Point(186, 157);
			this->txtar->Name = L"txtar";
			this->txtar->ReadOnly = true;
			this->txtar->Size = System::Drawing::Size(100, 20);
			this->txtar->TabIndex = 25;
			// 
			// txtts1
			// 
			this->txtts1->Location = System::Drawing::Point(186, 176);
			this->txtts1->Name = L"txtts1";
			this->txtts1->ReadOnly = true;
			this->txtts1->Size = System::Drawing::Size(100, 20);
			this->txtts1->TabIndex = 26;
			// 
			// txtts2
			// 
			this->txtts2->Location = System::Drawing::Point(186, 196);
			this->txtts2->Name = L"txtts2";
			this->txtts2->ReadOnly = true;
			this->txtts2->Size = System::Drawing::Size(100, 20);
			this->txtts2->TabIndex = 27;
			// 
			// txtsg1
			// 
			this->txtsg1->Location = System::Drawing::Point(186, 216);
			this->txtsg1->Name = L"txtsg1";
			this->txtsg1->ReadOnly = true;
			this->txtsg1->Size = System::Drawing::Size(100, 20);
			this->txtsg1->TabIndex = 28;
			this->txtsg1->TextChanged += gcnew System::EventHandler(this, &Form1::txtsg1_TextChanged);
			// 
			// txtsg2
			// 
			this->txtsg2->Location = System::Drawing::Point(186, 235);
			this->txtsg2->Name = L"txtsg2";
			this->txtsg2->ReadOnly = true;
			this->txtsg2->Size = System::Drawing::Size(100, 20);
			this->txtsg2->TabIndex = 29;
			this->txtsg2->TextChanged += gcnew System::EventHandler(this, &Form1::textBox12_TextChanged);
			// 
			// txtsg3
			// 
			this->txtsg3->Location = System::Drawing::Point(186, 254);
			this->txtsg3->Name = L"txtsg3";
			this->txtsg3->ReadOnly = true;
			this->txtsg3->Size = System::Drawing::Size(100, 20);
			this->txtsg3->TabIndex = 30;
			this->txtsg3->TextChanged += gcnew System::EventHandler(this, &Form1::txtsg3_TextChanged);
			// 
			// txtore1
			// 
			this->txtore1->Location = System::Drawing::Point(186, 270);
			this->txtore1->Name = L"txtore1";
			this->txtore1->ReadOnly = true;
			this->txtore1->Size = System::Drawing::Size(100, 20);
			this->txtore1->TabIndex = 31;
			this->txtore1->TextChanged += gcnew System::EventHandler(this, &Form1::txtore1_TextChanged);
			// 
			// txtore2
			// 
			this->txtore2->Location = System::Drawing::Point(186, 292);
			this->txtore2->Name = L"txtore2";
			this->txtore2->ReadOnly = true;
			this->txtore2->Size = System::Drawing::Size(100, 20);
			this->txtore2->TabIndex = 32;
			this->txtore2->TextChanged += gcnew System::EventHandler(this, &Form1::txtore2_TextChanged);
			// 
			// txtore3
			// 
			this->txtore3->Location = System::Drawing::Point(186, 313);
			this->txtore3->Name = L"txtore3";
			this->txtore3->ReadOnly = true;
			this->txtore3->Size = System::Drawing::Size(100, 20);
			this->txtore3->TabIndex = 33;
			this->txtore3->TextChanged += gcnew System::EventHandler(this, &Form1::txtore3_TextChanged);
			// 
			// txtate1
			// 
			this->txtate1->Location = System::Drawing::Point(186, 334);
			this->txtate1->Name = L"txtate1";
			this->txtate1->ReadOnly = true;
			this->txtate1->Size = System::Drawing::Size(100, 20);
			this->txtate1->TabIndex = 34;
			this->txtate1->TextChanged += gcnew System::EventHandler(this, &Form1::txtate1_TextChanged);
			// 
			// txtate2
			// 
			this->txtate2->Location = System::Drawing::Point(186, 357);
			this->txtate2->Name = L"txtate2";
			this->txtate2->ReadOnly = true;
			this->txtate2->Size = System::Drawing::Size(100, 20);
			this->txtate2->TabIndex = 35;
			this->txtate2->TextChanged += gcnew System::EventHandler(this, &Form1::txtate2_TextChanged);
			// 
			// lbate2
			// 
			this->lbate2->AutoSize = true;
			this->lbate2->Location = System::Drawing::Point(30, 360);
			this->lbate2->Name = L"lbate2";
			this->lbate2->Size = System::Drawing::Size(102, 13);
			this->lbate2->TabIndex = 36;
			this->lbate2->Text = L"Axial thrust engine 2";
			this->lbate2->Click += gcnew System::EventHandler(this, &Form1::lbate2_Click);
			// 
			// lbate3
			// 
			this->lbate3->AutoSize = true;
			this->lbate3->Location = System::Drawing::Point(30, 384);
			this->lbate3->Name = L"lbate3";
			this->lbate3->Size = System::Drawing::Size(102, 13);
			this->lbate3->TabIndex = 37;
			this->lbate3->Text = L"Axial thrust engine 3";
			this->lbate3->Click += gcnew System::EventHandler(this, &Form1::lbate3_Click);
			// 
			// lbpra
			// 
			this->lbpra->AutoSize = true;
			this->lbpra->Location = System::Drawing::Point(30, 401);
			this->lbpra->Name = L"lbpra";
			this->lbpra->Size = System::Drawing::Size(135, 13);
			this->lbpra->TabIndex = 38;
			this->lbpra->Text = L"Parachute release actuator";
			this->lbpra->Click += gcnew System::EventHandler(this, &Form1::label21_Click);
			// 
			// txtate3
			// 
			this->txtate3->Location = System::Drawing::Point(186, 380);
			this->txtate3->Name = L"txtate3";
			this->txtate3->ReadOnly = true;
			this->txtate3->Size = System::Drawing::Size(100, 20);
			this->txtate3->TabIndex = 39;
			this->txtate3->TextChanged += gcnew System::EventHandler(this, &Form1::txtate3_TextChanged);
			// 
			// txtpra
			// 
			this->txtpra->Location = System::Drawing::Point(186, 404);
			this->txtpra->Name = L"txtpra";
			this->txtpra->ReadOnly = true;
			this->txtpra->Size = System::Drawing::Size(100, 20);
			this->txtpra->TabIndex = 40;
			this->txtpra->TextChanged += gcnew System::EventHandler(this, &Form1::txtpra_TextChanged);
			// 
			// txtts
			// 
			this->txtts->Location = System::Drawing::Point(186, 428);
			this->txtts->Name = L"txtts";
			this->txtts->ReadOnly = true;
			this->txtts->Size = System::Drawing::Size(100, 20);
			this->txtts->TabIndex = 41;
			this->txtts->TextChanged += gcnew System::EventHandler(this, &Form1::txtts_TextChanged);
			// 
			// lbts
			// 
			this->lbts->AutoSize = true;
			this->lbts->Location = System::Drawing::Point(30, 425);
			this->lbts->Name = L"lbts";
			this->lbts->Size = System::Drawing::Size(98, 13);
			this->lbts->TabIndex = 42;
			this->lbts->Text = L"Touchdown sensor";
			this->lbts->Click += gcnew System::EventHandler(this, &Form1::lbts_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(326, 63);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 43;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(326, 97);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 44;
			this->button2->Text = L"button2";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(326, 128);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 45;
			this->button3->Text = L"button3";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(497, 483);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->lbts);
			this->Controls->Add(this->txtts);
			this->Controls->Add(this->txtpra);
			this->Controls->Add(this->txtate3);
			this->Controls->Add(this->lbpra);
			this->Controls->Add(this->lbate3);
			this->Controls->Add(this->lbate2);
			this->Controls->Add(this->txtate2);
			this->Controls->Add(this->txtate1);
			this->Controls->Add(this->txtore3);
			this->Controls->Add(this->txtore2);
			this->Controls->Add(this->txtore1);
			this->Controls->Add(this->txtsg3);
			this->Controls->Add(this->txtsg2);
			this->Controls->Add(this->txtsg1);
			this->Controls->Add(this->txtts2);
			this->Controls->Add(this->txtts1);
			this->Controls->Add(this->txtar);
			this->Controls->Add(this->txtdr3);
			this->Controls->Add(this->txtdr4);
			this->Controls->Add(this->txtdr2);
			this->Controls->Add(this->txtdr1);
			this->Controls->Add(this->txta3);
			this->Controls->Add(this->txta2);
			this->Controls->Add(this->txta1);
			this->Controls->Add(this->label18);
			this->Controls->Add(this->lbate1);
			this->Controls->Add(this->lbore3);
			this->Controls->Add(this->lbore2);
			this->Controls->Add(this->lbore1);
			this->Controls->Add(this->lbsg3);
			this->Controls->Add(this->lbsg2);
			this->Controls->Add(this->lbsg1);
			this->Controls->Add(this->lbts2);
			this->Controls->Add(this->lbtts1);
			this->Controls->Add(this->lbar);
			this->Controls->Add(this->lbdr4);
			this->Controls->Add(this->lbdr3);
			this->Controls->Add(this->lbdr2);
			this->Controls->Add(this->lbdr1);
			this->Controls->Add(this->lba3);
			this->Controls->Add(this->lba2);
			this->Controls->Add(this->lba1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void label6_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void textBox12_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void label21_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void txtpra_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void lbate3_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void lbate2_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void lba1_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void lba2_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void lba3_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void lbdr1_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void lbdr2_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void lbdr4_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void lbar_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void lbtts1_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void lbts2_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void lbsg1_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void txtsg1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void lbsg2_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void lbsg3_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void txtsg3_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void lbore1_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void txtore1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void lbore2_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void txtore2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void lbore3_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void txtore3_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void lbate1_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void txtate1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void txtate2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void txtate3_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void lbts_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void txtts_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void txta1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
};
}
