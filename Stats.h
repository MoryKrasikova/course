#pragma once

namespace курсовая {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Collections::Generic;

	/// <summary>
	/// Сводка для Stats
	/// </summary>
	public ref class Stats : public System::Windows::Forms::Form
	{
	public:
		Form^ s;
		Stats(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
		Stats(Form^ s1)
		{
			s = s1;//передаем ссылку на форму Stats в s
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Stats()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridView^ dataGridView2;

	protected:

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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button1->BackColor = System::Drawing::Color::IndianRed;
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->ForeColor = System::Drawing::SystemColors::InfoText;
			this->button1->Location = System::Drawing::Point(220, 358);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(174, 47);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Главное меню";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Stats::button1_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->dataGridView1->BackgroundColor = System::Drawing::Color::IndianRed;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(11, 16);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(598, 53);
			this->dataGridView1->TabIndex = 3;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Stats::dataGridView1_CellContentClick);
			// 
			// dataGridView2
			// 
			this->dataGridView2->AllowUserToDeleteRows = false;
			this->dataGridView2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->dataGridView2->BackgroundColor = System::Drawing::Color::IndianRed;
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Location = System::Drawing::Point(11, 115);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->ReadOnly = true;
			this->dataGridView2->RowHeadersWidth = 51;
			this->dataGridView2->RowTemplate->Height = 24;
			this->dataGridView2->Size = System::Drawing::Size(600, 115);
			this->dataGridView2->TabIndex = 4;
			this->dataGridView2->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Stats::dataGridView2_CellContentClick);
			// 
			// Stats
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::RosyBrown;
			this->ClientSize = System::Drawing::Size(622, 453);
			this->Controls->Add(this->dataGridView2);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button1);
			this->Name = L"Stats";
			this->Text = L"Stats";
			this->Load += gcnew System::EventHandler(this, &Stats::Stats_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		s->Show();//открывается форма MyForm
	}
	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {

	}
	private: System::Void Stats_Load(System::Object^ sender, System::EventArgs^ e) {

		this->dataGridView1->ColumnCount = 2;

		this->dataGridView1->Columns[0]->Name = "Количество выигрышей";
		this->dataGridView1->Columns[1]->Name = "Количество проигрышей";

		this->dataGridView1->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
		String^ filename = "wins.txt";
		if (!File::Exists(filename)) {
			File::Create(filename)->Close();
		}
		int count = 0;
		String^ line;
		StreamReader^ reader = gcnew StreamReader(filename);
		while ((line = reader->ReadLine()) != nullptr)
		{
			count++;
		}
		reader->Close();


		String^ filename1 = "loss.txt";
		if (!File::Exists(filename1)) {
			File::Create(filename1)->Close();
		}
		StreamReader^ reader1 = gcnew StreamReader(filename1);
		String^ line1 = reader1->ReadLine();
		reader1->Close();

		dataGridView1->Rows[0]->Cells[0]->Value = count.ToString(); // Обновляем первую ячейку
		dataGridView1->Rows[0]->Cells[1]->Value = line1;

		this->dataGridView2->ColumnCount = 1;
		this->dataGridView2->Columns[0]->Name = "ТОП-3 победы по очкам";
		this->dataGridView2->Columns[0]->HeaderCell->Style->Alignment = DataGridViewContentAlignment::MiddleCenter;
		this->dataGridView2->Columns[0]->DefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleCenter;
		// Установка выравнивания заголовка по центру

		this->dataGridView2->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
		this->dataGridView2->Rows->Add("");
		this->dataGridView2->Rows->Add("");


		StreamReader^ reader2 = gcnew StreamReader(filename);
		List<int>^ numbers = gcnew List<int>();

		// Чтение чисел из файла
		while (!reader2->EndOfStream)
		{
			String^ line2 = reader2->ReadLine();
			// Преобразование строки в число
			int number;
			if (Int32::TryParse(line2, number))
			{
				numbers->Add(number);
			}
		}

		// Закрытие файла
		reader2->Close();

		// Сортировка чисел
		array<int>^ sortednumbers = numbers->ToArray();
		Array::Sort(sortednumbers);

		dataGridView2->Rows[0]->Cells[0]->Value = sortednumbers[0].ToString();
		dataGridView2->Rows[1]->Cells[0]->Value = sortednumbers[1].ToString();
		dataGridView2->Rows[2]->Cells[0]->Value = sortednumbers[2].ToString();

	}
	private: System::Void dataGridView2_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	}
};
}
