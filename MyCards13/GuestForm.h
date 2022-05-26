#pragma once
#include "funcsHeader.h"
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
		GuestForm();
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
	private: System::Windows::Forms::Label^ sum_f;

	private: System::Windows::Forms::Label^ math_f;
	private: System::Windows::Forms::Label^ tech_f;
	private: System::Windows::Forms::Label^ railway_f;
	private: System::Windows::Forms::Label^ roadt_f;
	private: System::Windows::Forms::Label^ ist_f;
	private: System::Windows::Forms::Label^ int_f;






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
			this->sum_f = (gcnew System::Windows::Forms::Label());
			this->math_f = (gcnew System::Windows::Forms::Label());
			this->tech_f = (gcnew System::Windows::Forms::Label());
			this->railway_f = (gcnew System::Windows::Forms::Label());
			this->roadt_f = (gcnew System::Windows::Forms::Label());
			this->ist_f = (gcnew System::Windows::Forms::Label());
			this->int_f = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(96, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(147, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Здравствуйте, Гость!";
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
			// sum_f
			// 
			this->sum_f->AutoSize = true;
			this->sum_f->Location = System::Drawing::Point(12, 52);
			this->sum_f->Name = L"sum_f";
			this->sum_f->Size = System::Drawing::Size(257, 17);
			this->sum_f->TabIndex = 3;
			this->sum_f->Text = L"обучаются студенты на факультетах:";
			// 
			// math_f
			// 
			this->math_f->AutoSize = true;
			this->math_f->Location = System::Drawing::Point(9, 69);
			this->math_f->Name = L"math_f";
			this->math_f->Size = System::Drawing::Size(198, 17);
			this->math_f->TabIndex = 4;
			this->math_f->Text = L"Математический факультет:";
			// 
			// tech_f
			// 
			this->tech_f->AutoSize = true;
			this->tech_f->Location = System::Drawing::Point(9, 86);
			this->tech_f->Name = L"tech_f";
			this->tech_f->Size = System::Drawing::Size(171, 17);
			this->tech_f->TabIndex = 5;
			this->tech_f->Text = L"Технический факультет:";
			// 
			// railway_f
			// 
			this->railway_f->AutoSize = true;
			this->railway_f->Location = System::Drawing::Point(9, 103);
			this->railway_f->Name = L"railway_f";
			this->railway_f->Size = System::Drawing::Size(213, 17);
			this->railway_f->TabIndex = 6;
			this->railway_f->Text = L"Железнодорожный факультет:";
			// 
			// roadt_f
			// 
			this->roadt_f->AutoSize = true;
			this->roadt_f->Location = System::Drawing::Point(9, 120);
			this->roadt_f->Name = L"roadt_f";
			this->roadt_f->Size = System::Drawing::Size(246, 17);
			this->roadt_f->TabIndex = 7;
			this->roadt_f->Text = L"Дорожно-транспортный факультет:";
			// 
			// ist_f
			// 
			this->ist_f->AutoSize = true;
			this->ist_f->Location = System::Drawing::Point(9, 137);
			this->ist_f->Name = L"ist_f";
			this->ist_f->Size = System::Drawing::Size(259, 17);
			this->ist_f->TabIndex = 8;
			this->ist_f->Text = L"Факультет инф. систем и технологий:";
			// 
			// int_f
			// 
			this->int_f->AutoSize = true;
			this->int_f->Location = System::Drawing::Point(9, 154);
			this->int_f->Name = L"int_f";
			this->int_f->Size = System::Drawing::Size(195, 17);
			this->int_f->TabIndex = 9;
			this->int_f->Text = L"Международный факультет:";
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
			this->Controls->Add(this->int_f);
			this->Controls->Add(this->ist_f);
			this->Controls->Add(this->roadt_f);
			this->Controls->Add(this->railway_f);
			this->Controls->Add(this->tech_f);
			this->Controls->Add(this->math_f);
			this->Controls->Add(this->sum_f);
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
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {this->Close();}
};
}
