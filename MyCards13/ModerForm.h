#pragma once
//#include "funcsHeader.h"
#include "EditCardForm.h"
namespace MyCards13 {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	static std::vector<Card> _base;
	static std::vector <WorkerCard> workers_;

	/// <summary>
	/// Сводка для ModerForm
	/// </summary>
	/// 
	public ref class ModerForm : public System::Windows::Forms::Form
	{
	public:
		ModerForm(void)
		{
			InitializeComponent();
			addPaymentBox->SelectedIndex = 0;
			RefreshWorkersBox(WorkersBox);
			workers_ = load_base();
			//
			//TODO: добавьте код конструктора
			//
		}
	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~ModerForm()
		{
			if (components)
			{
				delete components;
			}
			_base.clear();
			//Application::Exit();
		}
	private: System::Windows::Forms::ListBox^ StudentsBox;
	protected:

	private: System::Windows::Forms::ComboBox^ facultiesBox;
	protected:


	private: System::Windows::Forms::Button^ ShowStuds;

	private: System::Windows::Forms::Button^ EditButton;
	private: System::Windows::Forms::Button^ DeleteButton;
	private: System::Windows::Forms::GroupBox^ AddStudentGBox;

	private: System::Windows::Forms::Button^ ClearAddButton;
	private: System::Windows::Forms::Button^ AddButton;
	private: System::Windows::Forms::ComboBox^ addPaymentBox;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ addGroupBox;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ addLNameBox;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ addNameBox;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::CheckBox^ clearBool;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ NewPost;
	private: System::Windows::Forms::TextBox^ newWorkerPost;


	private: System::Windows::Forms::Button^ deleteWorker;

	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::CheckBox^ clearWorkerBox;
	private: System::Windows::Forms::Button^ clearWorkerButton;



	private: System::Windows::Forms::Button^ AddWorker;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ workerPostBox;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ workerLNameBox;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ workerNameBox;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::ListBox^ WorkersBox;
	private: System::Windows::Forms::NumericUpDown^ newSalaryBox;
	private: System::Windows::Forms::NumericUpDown^ addSalaryBox;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Button^ newSalary;



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
			this->StudentsBox = (gcnew System::Windows::Forms::ListBox());
			this->facultiesBox = (gcnew System::Windows::Forms::ComboBox());
			this->ShowStuds = (gcnew System::Windows::Forms::Button());
			this->EditButton = (gcnew System::Windows::Forms::Button());
			this->DeleteButton = (gcnew System::Windows::Forms::Button());
			this->AddStudentGBox = (gcnew System::Windows::Forms::GroupBox());
			this->clearBool = (gcnew System::Windows::Forms::CheckBox());
			this->ClearAddButton = (gcnew System::Windows::Forms::Button());
			this->AddButton = (gcnew System::Windows::Forms::Button());
			this->addPaymentBox = (gcnew System::Windows::Forms::ComboBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->addGroupBox = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->addLNameBox = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->addNameBox = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->newSalary = (gcnew System::Windows::Forms::Button());
			this->newSalaryBox = (gcnew System::Windows::Forms::NumericUpDown());
			this->NewPost = (gcnew System::Windows::Forms::Button());
			this->newWorkerPost = (gcnew System::Windows::Forms::TextBox());
			this->deleteWorker = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->addSalaryBox = (gcnew System::Windows::Forms::NumericUpDown());
			this->clearWorkerBox = (gcnew System::Windows::Forms::CheckBox());
			this->clearWorkerButton = (gcnew System::Windows::Forms::Button());
			this->AddWorker = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->workerPostBox = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->workerLNameBox = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->workerNameBox = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->WorkersBox = (gcnew System::Windows::Forms::ListBox());
			this->AddStudentGBox->SuspendLayout();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->newSalaryBox))->BeginInit();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->addSalaryBox))->BeginInit();
			this->SuspendLayout();
			// 
			// StudentsBox
			// 
			this->StudentsBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->StudentsBox->FormattingEnabled = true;
			this->StudentsBox->ItemHeight = 20;
			this->StudentsBox->Location = System::Drawing::Point(12, 55);
			this->StudentsBox->Name = L"StudentsBox";
			this->StudentsBox->Size = System::Drawing::Size(475, 324);
			this->StudentsBox->TabIndex = 0;
			this->StudentsBox->SelectedIndexChanged += gcnew System::EventHandler(this, &ModerForm::StudentsBox_SelectedIndexChanged);
			// 
			// facultiesBox
			// 
			this->facultiesBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->facultiesBox->FormattingEnabled = true;
			this->facultiesBox->Items->AddRange(gcnew cli::array< System::Object^  >(6) {
				L"Математический факультет", L"Технический факультет",
					L"Железнодорожный факультет", L"Дорожно-транспортный факультет", L"Факультет информационных систем и технологий", L"Международный факультет"
			});
			this->facultiesBox->Location = System::Drawing::Point(12, 12);
			this->facultiesBox->Name = L"facultiesBox";
			this->facultiesBox->Size = System::Drawing::Size(354, 28);
			this->facultiesBox->TabIndex = 1;
			this->facultiesBox->Text = L"Выбрать факультет...";
			// 
			// ShowStuds
			// 
			this->ShowStuds->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->ShowStuds->Location = System::Drawing::Point(372, 11);
			this->ShowStuds->Name = L"ShowStuds";
			this->ShowStuds->Size = System::Drawing::Size(115, 28);
			this->ShowStuds->TabIndex = 3;
			this->ShowStuds->Text = L"Показать";
			this->ShowStuds->UseVisualStyleBackColor = true;
			this->ShowStuds->Click += gcnew System::EventHandler(this, &ModerForm::ShowStuds_Click);
			// 
			// EditButton
			// 
			this->EditButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->EditButton->Location = System::Drawing::Point(12, 391);
			this->EditButton->Name = L"EditButton";
			this->EditButton->Size = System::Drawing::Size(134, 115);
			this->EditButton->TabIndex = 5;
			this->EditButton->Text = L"Изменить выбранного студента";
			this->EditButton->UseVisualStyleBackColor = true;
			this->EditButton->Click += gcnew System::EventHandler(this, &ModerForm::EditButton_Click);
			// 
			// DeleteButton
			// 
			this->DeleteButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->DeleteButton->Location = System::Drawing::Point(12, 515);
			this->DeleteButton->Name = L"DeleteButton";
			this->DeleteButton->Size = System::Drawing::Size(134, 109);
			this->DeleteButton->TabIndex = 6;
			this->DeleteButton->Text = L"Удалить выбранного студента";
			this->DeleteButton->UseVisualStyleBackColor = true;
			this->DeleteButton->Click += gcnew System::EventHandler(this, &ModerForm::button3_Click);
			// 
			// AddStudentGBox
			// 
			this->AddStudentGBox->Controls->Add(this->clearBool);
			this->AddStudentGBox->Controls->Add(this->ClearAddButton);
			this->AddStudentGBox->Controls->Add(this->AddButton);
			this->AddStudentGBox->Controls->Add(this->addPaymentBox);
			this->AddStudentGBox->Controls->Add(this->label5);
			this->AddStudentGBox->Controls->Add(this->addGroupBox);
			this->AddStudentGBox->Controls->Add(this->label4);
			this->AddStudentGBox->Controls->Add(this->addLNameBox);
			this->AddStudentGBox->Controls->Add(this->label3);
			this->AddStudentGBox->Controls->Add(this->addNameBox);
			this->AddStudentGBox->Controls->Add(this->label2);
			this->AddStudentGBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->AddStudentGBox->Location = System::Drawing::Point(152, 391);
			this->AddStudentGBox->Name = L"AddStudentGBox";
			this->AddStudentGBox->Size = System::Drawing::Size(335, 233);
			this->AddStudentGBox->TabIndex = 7;
			this->AddStudentGBox->TabStop = false;
			this->AddStudentGBox->Text = L"Добавить студента";
			// 
			// clearBool
			// 
			this->clearBool->AutoSize = true;
			this->clearBool->Checked = true;
			this->clearBool->CheckState = System::Windows::Forms::CheckState::Checked;
			this->clearBool->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->clearBool->Location = System::Drawing::Point(9, 162);
			this->clearBool->Name = L"clearBool";
			this->clearBool->Size = System::Drawing::Size(311, 24);
			this->clearBool->TabIndex = 17;
			this->clearBool->Text = L"Очищать форму при добавлении";
			this->clearBool->UseVisualStyleBackColor = true;
			// 
			// ClearAddButton
			// 
			this->ClearAddButton->Location = System::Drawing::Point(289, 192);
			this->ClearAddButton->Name = L"ClearAddButton";
			this->ClearAddButton->Size = System::Drawing::Size(31, 30);
			this->ClearAddButton->TabIndex = 16;
			this->ClearAddButton->Text = L"#";
			this->ClearAddButton->UseVisualStyleBackColor = true;
			this->ClearAddButton->Click += gcnew System::EventHandler(this, &ModerForm::ClearAddButton_Click);
			// 
			// AddButton
			// 
			this->AddButton->Location = System::Drawing::Point(10, 192);
			this->AddButton->Name = L"AddButton";
			this->AddButton->Size = System::Drawing::Size(273, 30);
			this->AddButton->TabIndex = 9;
			this->AddButton->Text = L"Добавить";
			this->AddButton->UseVisualStyleBackColor = true;
			this->AddButton->Click += gcnew System::EventHandler(this, &ModerForm::AddButton_Click);
			// 
			// addPaymentBox
			// 
			this->addPaymentBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->addPaymentBox->FormattingEnabled = true;
			this->addPaymentBox->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Контракт\t", L"Бюджет", L"Направление" });
			this->addPaymentBox->Location = System::Drawing::Point(155, 130);
			this->addPaymentBox->Name = L"addPaymentBox";
			this->addPaymentBox->Size = System::Drawing::Size(165, 26);
			this->addPaymentBox->TabIndex = 9;
			this->addPaymentBox->SelectedIndexChanged += gcnew System::EventHandler(this, &ModerForm::addPaymentBox_SelectedIndexChanged);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label5->Location = System::Drawing::Point(6, 130);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(134, 20);
			this->label5->TabIndex = 15;
			this->label5->Text = L"Форма оплаты";
			// 
			// addGroupBox
			// 
			this->addGroupBox->Location = System::Drawing::Point(155, 95);
			this->addGroupBox->Name = L"addGroupBox";
			this->addGroupBox->Size = System::Drawing::Size(165, 26);
			this->addGroupBox->TabIndex = 14;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label4->Location = System::Drawing::Point(6, 95);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(67, 20);
			this->label4->TabIndex = 13;
			this->label4->Text = L"Группа";
			// 
			// addLNameBox
			// 
			this->addLNameBox->Location = System::Drawing::Point(155, 63);
			this->addLNameBox->Name = L"addLNameBox";
			this->addLNameBox->Size = System::Drawing::Size(165, 26);
			this->addLNameBox->TabIndex = 12;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label3->Location = System::Drawing::Point(5, 63);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(87, 20);
			this->label3->TabIndex = 11;
			this->label3->Text = L"Фамилия";
			// 
			// addNameBox
			// 
			this->addNameBox->Location = System::Drawing::Point(155, 31);
			this->addNameBox->Name = L"addNameBox";
			this->addNameBox->Size = System::Drawing::Size(165, 26);
			this->addNameBox->TabIndex = 10;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label2->Location = System::Drawing::Point(6, 31);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(42, 20);
			this->label2->TabIndex = 9;
			this->label2->Text = L"Имя";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label10);
			this->groupBox1->Controls->Add(this->label9);
			this->groupBox1->Controls->Add(this->newSalary);
			this->groupBox1->Controls->Add(this->newSalaryBox);
			this->groupBox1->Controls->Add(this->NewPost);
			this->groupBox1->Controls->Add(this->newWorkerPost);
			this->groupBox1->Controls->Add(this->deleteWorker);
			this->groupBox1->Controls->Add(this->groupBox2);
			this->groupBox1->Controls->Add(this->WorkersBox);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->groupBox1->Location = System::Drawing::Point(506, 11);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(568, 613);
			this->groupBox1->TabIndex = 8;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Работники университета";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(331, 380);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(197, 20);
			this->label10->TabIndex = 23;
			this->label10->Text = L"Должность работника";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(331, 461);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(221, 20);
			this->label9->TabIndex = 22;
			this->label9->Text = L"Оплата труда работника";
			// 
			// newSalary
			// 
			this->newSalary->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->newSalary->Location = System::Drawing::Point(445, 484);
			this->newSalary->Name = L"newSalary";
			this->newSalary->Size = System::Drawing::Size(111, 26);
			this->newSalary->TabIndex = 21;
			this->newSalary->Text = L"Изменить";
			this->newSalary->UseVisualStyleBackColor = true;
			this->newSalary->Click += gcnew System::EventHandler(this, &ModerForm::newSalary_Click);
			// 
			// newSalaryBox
			// 
			this->newSalaryBox->Location = System::Drawing::Point(335, 484);
			this->newSalaryBox->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100000, 0, 0, 0 });
			this->newSalaryBox->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			this->newSalaryBox->Name = L"newSalaryBox";
			this->newSalaryBox->Size = System::Drawing::Size(104, 26);
			this->newSalaryBox->TabIndex = 19;
			this->newSalaryBox->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			// 
			// NewPost
			// 
			this->NewPost->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->NewPost->Location = System::Drawing::Point(445, 411);
			this->NewPost->Name = L"NewPost";
			this->NewPost->Size = System::Drawing::Size(111, 26);
			this->NewPost->TabIndex = 20;
			this->NewPost->Text = L"Изменить";
			this->NewPost->UseVisualStyleBackColor = true;
			this->NewPost->Click += gcnew System::EventHandler(this, &ModerForm::NewPost_Click);
			// 
			// newWorkerPost
			// 
			this->newWorkerPost->Location = System::Drawing::Point(335, 411);
			this->newWorkerPost->Name = L"newWorkerPost";
			this->newWorkerPost->Size = System::Drawing::Size(104, 26);
			this->newWorkerPost->TabIndex = 19;
			this->newWorkerPost->Text = L"...";
			// 
			// deleteWorker
			// 
			this->deleteWorker->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->deleteWorker->Location = System::Drawing::Point(335, 516);
			this->deleteWorker->Name = L"deleteWorker";
			this->deleteWorker->Size = System::Drawing::Size(221, 96);
			this->deleteWorker->TabIndex = 9;
			this->deleteWorker->Text = L"Удалить выбранного работника";
			this->deleteWorker->UseVisualStyleBackColor = true;
			this->deleteWorker->Click += gcnew System::EventHandler(this, &ModerForm::deleteWorker_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->addSalaryBox);
			this->groupBox2->Controls->Add(this->clearWorkerBox);
			this->groupBox2->Controls->Add(this->clearWorkerButton);
			this->groupBox2->Controls->Add(this->AddWorker);
			this->groupBox2->Controls->Add(this->label1);
			this->groupBox2->Controls->Add(this->workerPostBox);
			this->groupBox2->Controls->Add(this->label6);
			this->groupBox2->Controls->Add(this->workerLNameBox);
			this->groupBox2->Controls->Add(this->label7);
			this->groupBox2->Controls->Add(this->workerNameBox);
			this->groupBox2->Controls->Add(this->label8);
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->groupBox2->Location = System::Drawing::Point(15, 380);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(310, 233);
			this->groupBox2->TabIndex = 18;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Добавить работника";
			// 
			// addSalaryBox
			// 
			this->addSalaryBox->Location = System::Drawing::Point(155, 128);
			this->addSalaryBox->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100000, 0, 0, 0 });
			this->addSalaryBox->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			this->addSalaryBox->Name = L"addSalaryBox";
			this->addSalaryBox->Size = System::Drawing::Size(150, 26);
			this->addSalaryBox->TabIndex = 18;
			this->addSalaryBox->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			// 
			// clearWorkerBox
			// 
			this->clearWorkerBox->AutoSize = true;
			this->clearWorkerBox->Checked = true;
			this->clearWorkerBox->CheckState = System::Windows::Forms::CheckState::Checked;
			this->clearWorkerBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->clearWorkerBox->Location = System::Drawing::Point(9, 162);
			this->clearWorkerBox->Name = L"clearWorkerBox";
			this->clearWorkerBox->Size = System::Drawing::Size(260, 22);
			this->clearWorkerBox->TabIndex = 17;
			this->clearWorkerBox->Text = L"Очищать форму при добавлении";
			this->clearWorkerBox->UseVisualStyleBackColor = true;
			// 
			// clearWorkerButton
			// 
			this->clearWorkerButton->Location = System::Drawing::Point(275, 192);
			this->clearWorkerButton->Name = L"clearWorkerButton";
			this->clearWorkerButton->Size = System::Drawing::Size(30, 30);
			this->clearWorkerButton->TabIndex = 16;
			this->clearWorkerButton->Text = L"#";
			this->clearWorkerButton->UseVisualStyleBackColor = true;
			this->clearWorkerButton->Click += gcnew System::EventHandler(this, &ModerForm::clearWorkerButton_Click);
			// 
			// AddWorker
			// 
			this->AddWorker->Location = System::Drawing::Point(9, 192);
			this->AddWorker->Name = L"AddWorker";
			this->AddWorker->Size = System::Drawing::Size(260, 30);
			this->AddWorker->TabIndex = 9;
			this->AddWorker->Text = L"Добавить";
			this->AddWorker->UseVisualStyleBackColor = true;
			this->AddWorker->Click += gcnew System::EventHandler(this, &ModerForm::AddWorker_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label1->Location = System::Drawing::Point(6, 130);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(127, 20);
			this->label1->TabIndex = 15;
			this->label1->Text = L"Оплата труда";
			// 
			// workerPostBox
			// 
			this->workerPostBox->Location = System::Drawing::Point(155, 95);
			this->workerPostBox->Name = L"workerPostBox";
			this->workerPostBox->Size = System::Drawing::Size(150, 26);
			this->workerPostBox->TabIndex = 14;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label6->Location = System::Drawing::Point(6, 95);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(103, 20);
			this->label6->TabIndex = 13;
			this->label6->Text = L"Должность";
			// 
			// workerLNameBox
			// 
			this->workerLNameBox->Location = System::Drawing::Point(155, 63);
			this->workerLNameBox->Name = L"workerLNameBox";
			this->workerLNameBox->Size = System::Drawing::Size(150, 26);
			this->workerLNameBox->TabIndex = 12;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label7->Location = System::Drawing::Point(5, 63);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(87, 20);
			this->label7->TabIndex = 11;
			this->label7->Text = L"Фамилия";
			// 
			// workerNameBox
			// 
			this->workerNameBox->Location = System::Drawing::Point(155, 31);
			this->workerNameBox->Name = L"workerNameBox";
			this->workerNameBox->Size = System::Drawing::Size(150, 26);
			this->workerNameBox->TabIndex = 10;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label8->Location = System::Drawing::Point(6, 31);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(42, 20);
			this->label8->TabIndex = 9;
			this->label8->Text = L"Имя";
			// 
			// WorkersBox
			// 
			this->WorkersBox->FormattingEnabled = true;
			this->WorkersBox->ItemHeight = 20;
			this->WorkersBox->Location = System::Drawing::Point(15, 44);
			this->WorkersBox->Name = L"WorkersBox";
			this->WorkersBox->Size = System::Drawing::Size(541, 324);
			this->WorkersBox->TabIndex = 0;
			// 
			// ModerForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->CausesValidation = false;
			this->ClientSize = System::Drawing::Size(1086, 635);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->ShowStuds);
			this->Controls->Add(this->DeleteButton);
			this->Controls->Add(this->EditButton);
			this->Controls->Add(this->facultiesBox);
			this->Controls->Add(this->StudentsBox);
			this->Controls->Add(this->AddStudentGBox);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"ModerForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Вы зашли как: Модератор";
			this->Load += gcnew System::EventHandler(this, &ModerForm::ModerForm_Load);
			this->AddStudentGBox->ResumeLayout(false);
			this->AddStudentGBox->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->newSalaryBox))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->addSalaryBox))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Close();
	}
	private: System::Void ModerForm_Load(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void ShowStuds_Click(System::Object^ sender, System::EventArgs^ e)
	{
		StudentsBox->Items->Clear();
		std::string path_ = GetPath(facultiesBox);
		_base = load_base(path_);
		ReadBase(StudentsBox, path_);
	}
	private: System::Void clearButt_Click(System::Object^ sender, System::EventArgs^ e)
	{
		StudentsBox->Items->Clear();
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (StudentsBox->SelectedIndex >= 0)
		{
			_base.erase(_base.begin() + StudentsBox->SelectedIndex);
			std::string path_ = GetPath(facultiesBox);
			RewriteBase(_base, path_);
			StudentsBox->Items->Clear();
			ReadBase(StudentsBox, path_);
		}
		else { DoAlert("Вы не выбрали студента!"); }
	}
	private: System::Void EditButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (StudentsBox->SelectedIndex >= 0)
		{
			EditCardForm^ form = gcnew EditCardForm(StudentsBox->SelectedIndex, facultiesBox->SelectedIndex);
			form->ShowDialog();
			StudentsBox->Items->Clear();
			ReadBase(StudentsBox, GetPath(facultiesBox));
		}
		else { DoAlert("Вы не выбрали студента!"); }
	}
	private: System::Void AddButton_Click(System::Object^ sender, System::EventArgs^ e) {
		std::string NewStudent = Stos(addNameBox->Text);
		NewStudent = NewStudent + " " + Stos(addLNameBox->Text);
		NewStudent = NewStudent + " " + Stos(addGroupBox->Text) + " ";
		NewStudent += std::to_string(addPaymentBox->SelectedIndex);
		std::string path_ = GetPath(facultiesBox);
		if (std::regex_match(NewStudent.c_str(), STUDENT_REGEX))
		{
			if (!isExist(NewStudent, path_))
			{
				BaseAppend(NewStudent, path_);
				_base.push_back(TextToCard(NewStudent));

				StudentsBox->Items->Clear();
				ReadBase(StudentsBox, path_);

				AddAccount(addLNameBox->Text, addGroupBox->Text + "_" + addLNameBox->Text, 0);

				if (clearBool->Checked)
				{
					addNameBox->Clear();
					addLNameBox->Clear();
					addGroupBox->Clear();
				}
			}
			else DoAlert("Такой студент уже есть в базе!");
		}
		else if (path_ != "") DoAlert("Вы не корректно ввели данные студента!");
	}
	private: System::Void ClearAddButton_Click(System::Object^ sender, System::EventArgs^ e) {
		addNameBox->Clear();
		addLNameBox->Clear();
		addGroupBox->Clear();
		addPaymentBox->SelectedIndex = 0;
	}
	private: System::Void addPaymentBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void StudentsBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void AddWorker_Click(System::Object^ sender, System::EventArgs^ e) //добавить работника
	{
		std::string stats = Stos(workerNameBox->Text) + " " + Stos(workerLNameBox->Text) + " "
			+ Stos(workerPostBox->Text) + " 2022 " + Stos(addSalaryBox->Value.ToString());
		if (std::regex_match(stats, WORKER_REGEX))
		{
			workers_.push_back(TextToWCard(stats));
			BaseAppend(stats,WORKERS_PATH);
			RefreshWorkersBox(WorkersBox);
			//
			if (clearWorkerBox->Checked)
			{
				workerNameBox->Clear();
				workerLNameBox->Clear();
				workerPostBox->Clear();
			}
		}
		else { DoAlert("Введены некорректные данные!"); }
	}
	private: System::Void clearWorkerButton_Click(System::Object^ sender, System::EventArgs^ e) //очистить форму
	{
		workerNameBox->Clear();
		workerLNameBox->Clear();
		workerPostBox->Clear();
	}
	private: System::Void deleteWorker_Click(System::Object^ sender, System::EventArgs^ e) //удалить работника
	{
		if (WorkersBox->SelectedIndex >= 0)
		{
			workers_.erase(workers_.begin() + WorkersBox->SelectedIndex);
			RewriteBase(workers_);
			RefreshWorkersBox(WorkersBox);
		}
		else { DoAlert("Вы не выбрали работника!"); }
	}
	private: System::Void NewPost_Click(System::Object^ sender, System::EventArgs^ e) //изменить должность
	{
		if (WorkersBox->SelectedIndex >= 0)
		{
			workers_.at(WorkersBox->SelectedIndex).SetPost(Stos(newWorkerPost->Text));
			if (std::regex_match(workers_.at(WorkersBox->SelectedIndex).GetInfo(), WORKER_REGEX))
			{
				RewriteBase(workers_);
				RefreshWorkersBox(WorkersBox);
			}
			else DoAlert("Введены некорректные данные!");
		}
		else { DoAlert("Вы не выбрали работника!"); }
	}
	private: System::Void newSalary_Click(System::Object^ sender, System::EventArgs^ e) //изменить зарплату
	{
		if (WorkersBox->SelectedIndex >= 0)
		{
			workers_.at(WorkersBox->SelectedIndex).ChangeSalary(newSalaryBox->Value.ToInt32(newSalaryBox->Value));
			if (std::regex_match(workers_.at(WorkersBox->SelectedIndex).GetInfo(), WORKER_REGEX))
			{
				RewriteBase(workers_);
				RefreshWorkersBox(WorkersBox);
			}
			else DoAlert("Введены некорректные данные!");
		}
		else { DoAlert("Вы не выбрали работника!"); }
	}
	};
}
