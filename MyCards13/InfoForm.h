#pragma once
#include "funcsHeader.h"
#include "EditCardForm.h"
namespace MyCards13 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	static int card_index, facultyIndex;
	/// <summary>
	/// Сводка для InfoForm
	/// </summary>
	public ref class InfoForm : public System::Windows::Forms::Form
	{
	public:
		InfoForm(Card& card, int c_ind, int f_ind, bool canEdit);
	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~InfoForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::Button^ EditButton;
	private: System::Windows::Forms::Button^ ExitButton;
	private: System::Windows::Forms::TextBox^ InfoText;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->EditButton = (gcnew System::Windows::Forms::Button());
			this->ExitButton = (gcnew System::Windows::Forms::Button());
			this->InfoText = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// EditButton
			// 
			this->EditButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->EditButton->Location = System::Drawing::Point(18, 369);
			this->EditButton->Name = L"EditButton";
			this->EditButton->Size = System::Drawing::Size(523, 48);
			this->EditButton->TabIndex = 7;
			this->EditButton->Text = L"Изменить";
			this->EditButton->UseVisualStyleBackColor = true;
			this->EditButton->Click += gcnew System::EventHandler(this, &InfoForm::EditButton_Click);
			// 
			// ExitButton
			// 
			this->ExitButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->ExitButton->Location = System::Drawing::Point(18, 423);
			this->ExitButton->Name = L"ExitButton";
			this->ExitButton->Size = System::Drawing::Size(523, 48);
			this->ExitButton->TabIndex = 8;
			this->ExitButton->Text = L"Выход";
			this->ExitButton->UseVisualStyleBackColor = true;
			this->ExitButton->Click += gcnew System::EventHandler(this, &InfoForm::ExitButton_Click);
			// 
			// InfoText
			// 
			this->InfoText->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->InfoText->Location = System::Drawing::Point(18, 12);
			this->InfoText->Multiline = true;
			this->InfoText->Name = L"InfoText";
			this->InfoText->ReadOnly = true;
			this->InfoText->Size = System::Drawing::Size(523, 351);
			this->InfoText->TabIndex = 9;
			// 
			// InfoForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(553, 483);
			this->Controls->Add(this->InfoText);
			this->Controls->Add(this->ExitButton);
			this->Controls->Add(this->EditButton);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"InfoForm";
			this->Text = L"Портфолио";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void EditButton_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void ExitButton_Click(System::Object^ sender, System::EventArgs^ e);
};
}
