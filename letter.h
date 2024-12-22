#pragma once
using namespace System;
using namespace System::Collections::Generic;
public ref class Letter
{
private:
    String^ let; // Символ буквы

public:
    // Конструктор
    Letter(String^ letter)  
    {
        let = letter;
    }

    // Метод для получения буквы
    String^ getvalue() {
        return let;
    }
};

