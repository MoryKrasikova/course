#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;
using namespace System::IO;
#include "answers.h"
public ref class gameresult :
    public answers
{
private:
    int win; // Количество выигрышей
    int loss; // Количество проигрышей
    static int gamesplayed; // Статистика игр

public:
    // Конструктор
    gameresult() : answers(0, 0, 6), win(0), loss(0) {}

    // Метод для отображения статистики в Label
    void displayatats(Label^ outputLabel2) {
        outputLabel2->Text += String::Format("Введенные буквы: ");
        for (int i = 0; i < letters->Count; ++i) {
            outputLabel2->Text += String::Format("{0} ", letters[i]);
        }
        outputLabel2->Text += String::Format("\n");
        outputLabel2->Text += String::Format("Статистика ответов:\n");
        outputLabel2->Text += String::Format("Верные ответы: {0}\n",rightanswers);
        outputLabel2->Text += String::Format("Неверные ответы: {0}\n", wronganswers);
        outputLabel2->Text += String::Format("Попытки: {0}\n", wronganswers + rightanswers);

    }

    void kolwin() {
        String^ filename = "wins.txt";

        // Проверка, существует ли файл, если нет, создаем его
        if (!File::Exists(filename)) {
            File::Create(filename)->Close(); 
        }

        StreamWriter^ writer = gcnew StreamWriter(filename, true); // true для добавления
        writer->WriteLine(wronganswers + rightanswers);
        writer->Close(); 
    }

    void kolloss() {
        String^ filename = "loss.txt";
        int losscount = 0; 
        // Проверка, существует ли файл, если нет, создаем его
        if (!File::Exists(filename)) {
            File::Create(filename)->Close(); 
        }
        else {
            // Чтение текущего количества проигрышей
            StreamReader^ reader = gcnew StreamReader(filename);
            String^ line = reader->ReadLine();
            if (line != nullptr) {
                losscount = Int32::Parse(line); // Преобразование строки в число
            }
            reader->Close(); 
        }

        losscount++;

        // Запись обновленного количества проигрышей в файл
        StreamWriter^ writer = gcnew StreamWriter(filename, false); // false для перезаписи
        writer->WriteLine(losscount); 
        writer->Close(); 
    }
    int gettries()
    {
        int kol = wronganswers + rightanswers;
        return kol;
    }
};

