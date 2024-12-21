#pragma once
using namespace System;
using namespace System::Collections::Generic;
ref class letter
{
private:
    System::Char let; // Символ буквы

public:
    // Конструктор
    letter(System::Char letter) 
    {
        let = letter;
    }

    // Метод для получения буквы
    System::Char getValue(){
        return let;
    }
};

