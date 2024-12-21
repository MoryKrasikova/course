#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;
public ref class word
{
    String^ randomword; 
    int length; 

public:
    // Конструктор
    word() : length(0) {}

    // Деструктор
    ~word() {}

    // Метод для выбора случайного слова
    void selectrandomword(String^ filename) {
        List<String^>^ words = gcnew List<String^>(); // Список для хранения слов
        StreamReader^ file = gcnew StreamReader(filename); 

        String^ word;
        // Считываем всю строку из файла
        String^ line = file->ReadLine();
        file->Close(); 

        if (line != nullptr) {
            // Разбиваем строку на слова по пробелам
            array<String^>^ splitWords = line->Split(' ');

            // Добавляем каждое слово в список
            for each (String ^ word in splitWords) {
                if (!String::IsNullOrWhiteSpace(word)) {
                    words->Add(word);
                }
            }
        }
        if (words->Count > 0) {
            Random^ rand = gcnew Random(); 
            int randomindex = rand->Next(0, words->Count); 

            length = words[randomindex]->Length; 
            randomword = words[randomindex]; 
        }
    }

    // Метод для получения слова
    String^ getrandomword() {
        return randomword;
    }

    // Метод для получения длины слова
    int getlength() {
        return length;
    }
};

