#pragma once
namespace MyCards13 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для GuestForm
	/// </summary>
	public ref class GuestForm : public System::Windows::Forms::Form
	{
	public:
		GuestForm()
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~GuestForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Button^ button1;

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(96, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(140, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Здравсвуйте, Гость!";
			this->label1->Click += gcnew System::EventHandler(this, &GuestForm::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(9, 35);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(289, 17);
			this->label2->TabIndex = 2;
			this->label2->Text = L"На данный момент в нашем Университете";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 52);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(239, 17);
			this->label3->TabIndex = 3;
			this->label3->Text = L"обучаются 2983 студентов, из них:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(9, 69);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(198, 17);
			this->label4->TabIndex = 4;
			this->label4->Text = L"Математический факультет:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(9, 86);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(171, 17);
			this->label5->TabIndex = 5;
			this->label5->Text = L"Технический факультет:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(9, 103);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(213, 17);
			this->label6->TabIndex = 6;
			this->label6->Text = L"Железнодорожный факультет:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(9, 120);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(246, 17);
			this->label7->TabIndex = 7;
			this->label7->Text = L"Дорожно-транспортный факультет:";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(9, 137);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(259, 17);
			this->label8->TabIndex = 8;
			this->label8->Text = L"Факультет инф. систем и технологий:";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(9, 154);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(195, 17);
			this->label9->TabIndex = 9;
			this->label9->Text = L"Международный факультет:";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->button1->Location = System::Drawing::Point(12, 188);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(313, 38);
			this->button1->TabIndex = 10;
			this->button1->Text = L"Войти в аккаунт";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &GuestForm::button1_Click_1);
			// 
			// GuestForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(337, 238);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(355, 285);
			this->MinimumSize = System::Drawing::Size(355, 285);
			this->Name = L"GuestForm";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Вы вошли как: Гость";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
};
}
