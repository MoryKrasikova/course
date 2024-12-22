#pragma once
#include <sstream>  
#include <string> 
#include <fstream>
#include "word.h"
#include "answers.h"
#include "Letter.h"
#include "gameresult.h"
#include "Fileexception.h"
namespace курсовая {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Game
	/// </summary>
	public ref class Game : public System::Windows::Forms::Form
	{
	public:
		Form^ g;
		Game(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
		Game(Form^ g1)
		{
			g = g1;//передаем ссылку на форму Game в g
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Game()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Label^ label2;

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
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(18, 485);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(0, 0);
			this->button1->TabIndex = 0;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button2->BackColor = System::Drawing::Color::IndianRed;
			this->button2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button2->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->button2->FlatAppearance->BorderSize = 0;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->ForeColor = System::Drawing::SystemColors::InfoText;
			this->button2->Location = System::Drawing::Point(17, 12);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(156, 47);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Животные";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Game::button2_Click);
			// 
			// button3
			// 
			this->button3->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button3->BackColor = System::Drawing::Color::IndianRed;
			this->button3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button3->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->button3->FlatAppearance->BorderSize = 0;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->ForeColor = System::Drawing::SystemColors::InfoText;
			this->button3->Location = System::Drawing::Point(208, 12);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(156, 47);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Страны";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &Game::button3_Click);
			// 
			// button4
			// 
			this->button4->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button4->BackColor = System::Drawing::Color::IndianRed;
			this->button4->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button4->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->button4->FlatAppearance->BorderSize = 0;
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button4->ForeColor = System::Drawing::SystemColors::InfoText;
			this->button4->Location = System::Drawing::Point(400, 12);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(156, 47);
			this->button4->TabIndex = 4;
			this->button4->Text = L"Общая тема";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &Game::button4_Click);
			// 
			// button5
			// 
			this->button5->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button5->BackColor = System::Drawing::Color::IndianRed;
			this->button5->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button5->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->button5->FlatAppearance->BorderSize = 0;
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button5->ForeColor = System::Drawing::SystemColors::InfoText;
			this->button5->Location = System::Drawing::Point(586, 12);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(156, 47);
			this->button5->TabIndex = 5;
			this->button5->Text = L"Растения";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &Game::button5_Click);
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(12, 73);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(730, 62);
			this->label1->TabIndex = 6;
			this->label1->Click += gcnew System::EventHandler(this, &Game::label1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textBox1->Location = System::Drawing::Point(17, 151);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(725, 22);
			this->textBox1->TabIndex = 7;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Game::textBox1_TextChanged);
			// 
			// button6
			// 
			this->button6->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button6->BackColor = System::Drawing::Color::IndianRed;
			this->button6->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button6->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->button6->FlatAppearance->BorderSize = 0;
			this->button6->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button6->ForeColor = System::Drawing::SystemColors::InfoText;
			this->button6->Location = System::Drawing::Point(17, 179);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(156, 47);
			this->button6->TabIndex = 8;
			this->button6->Text = L"Сохранить";
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Click += gcnew System::EventHandler(this, &Game::button6_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->pictureBox1->Location = System::Drawing::Point(20, 232);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(398, 309);
			this->pictureBox1->TabIndex = 9;
			this->pictureBox1->TabStop = false;
			// 
			// button7
			// 
			this->button7->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button7->BackColor = System::Drawing::Color::IndianRed;
			this->button7->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button7->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->button7->FlatAppearance->BorderSize = 0;
			this->button7->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button7->ForeColor = System::Drawing::SystemColors::InfoText;
			this->button7->Location = System::Drawing::Point(513, 494);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(156, 47);
			this->button7->TabIndex = 10;
			this->button7->Text = L"Главное меню";
			this->button7->UseVisualStyleBackColor = false;
			this->button7->Click += gcnew System::EventHandler(this, &Game::button7_Click);
			// 
			// label2
			// 
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(444, 232);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(298, 243);
			this->label2->TabIndex = 11;
			this->label2->Click += gcnew System::EventHandler(this, &Game::label2_Click);
			// 
			// Game
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::RosyBrown;
			this->ClientSize = System::Drawing::Size(754, 553);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"Game";
			this->Text = L"Game";
			this->Load += gcnew System::EventHandler(this, &Game::Game_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	int length = 0;
	int wr = 0;
	int loss = 0;
	String^ word1 = "";
	String^ randomword = "";
	String^ anspeople = "";
	gameresult^ gr = gcnew gameresult();
	word^ w = gcnew word();
	String^ usedletters = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
	private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		g->Show();//открывается форма MyForm
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		InitializeGame1("animals.txt");
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		InitializeGame1("countries.txt");
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		InitializeGame1("words.txt");
	}
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
		InitializeGame1("plants.txt");
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: void InitializeGame1(String^ filename) {
		button2->Enabled = false;
		button3->Enabled = false;
		button4->Enabled = false;
		button5->Enabled = false;
		textBox1->Enabled = true;
		button6->Enabled = true;
		label2->Text = "";
		try {
			Fileexception::checkfileexists(filename);
		} catch (Fileexception^ ex) {
			MessageBox::Show(ex->Message + "\nИмя файла: " + ex->Filename, "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}

		w->selectrandomword(filename); // Выбор случайного слова
		randomword = w->getrandomword(); // Получаем выбранное слово
		gr->setcurrentword(randomword);
		word1 = gr->getcurrentword();
		length = word1->Length;
		label1->Text = String::Format("Слово из {0} букв, введите букву",length);
		for (int i = 0; i < length; i++) {
			anspeople += "_ ";
		}// Заполняем символами '_'
	}

	private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ userinput = "";

		userinput = textBox1->Text;
		if (userinput->Length != 1 || !Char::IsLetter(userinput[0])) {
			label1->Text = "Пожалуйста, введите одну букву.";
			return;
		}
		else {
			label1->Text = "";
		}
		String^ ui = userinput->Substring(0, 1);
		gr->setanswer(ui);

		// Проверка введенной буквы
		gr->check(ui, length, usedletters, anspeople, label1);

		int count = 0;
		for (int i = 0; i < anspeople->Length; i++) {
			if (anspeople[i]!='_' && anspeople[i]!=' ') {
				count += 1;
			}
		}

		if (count == length) { // При выигрыше
			gr->getwinresult(wr);
			label1->Text = "";
			label1->Text = String::Format("Вы отгадали слово - {0} за {1} попыток.\n", word1, wr);
			gr->kolwin();
		}

		if (gr->getwronganswers() == 6) { // При проигрыше
			gr->getloss(loss);
			label1->Text = String::Format("Вы проиграли! Слово - {0}\n", word1);
			gr->kolloss();
		}
		if (count == length || gr->getwronganswers() == 6)
		{
			gr->displayatats(label2);
			length = 0;
			wr = 0;
			loss = 0;
			word1 = "";
			randomword = "";
			anspeople = "";
			usedletters = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
			gr = gcnew gameresult();
			w = gcnew word();
			button6->Enabled = false;
			textBox1->Enabled = false;
			button2->Enabled = true;
			button3->Enabled = true;
			button4->Enabled = true;
			button5->Enabled = true;
		}
		textBox1->Clear();
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void Game_Load(System::Object^ sender, System::EventArgs^ e) {
		button6->Enabled = false;
		textBox1->Enabled = false;
	}
};
}
