#pragma once
using namespace System;
using namespace System::Collections::Generic;
public ref class Letter
{
private:
    Char let; // Символ буквы

public:
    // Конструктор
    Letter(Char letter)  
    {
        let = letter;
    }

    // Метод для получения буквы
    Char getvalue() {
        return let;
    }
};

