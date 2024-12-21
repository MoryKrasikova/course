#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;
ref class word
{
    String^ randomword; 
    int length; 

public:
    // Конструктор
    word() : length(0) {}

    // Деструктор
    ~word() {}

    // Метод для выбора случайного слова
    void selectRandomWord(String^ filename) {
        List<String^>^ words = gcnew List<String^>(); // Список для хранения слов
        StreamReader^ file = gcnew StreamReader(filename); 

        String^ word;
        while ((word = file->ReadLine()) != nullptr) {
            words->Add(word); 
        }
        file->Close(); 

        if (words->Count > 0) {
            Random^ rand = gcnew Random(); 
            int randomindex = rand->Next(0, words->Count); 

            length = words[randomindex]->Length; 
            randomword = words[randomindex]; 
        }
    }

    // Метод для получения слова
    String^ getRandomWord() {
        return randomword;
    }

    // Метод для получения длины слова
    int getLength() {
        return length;
    }
};

