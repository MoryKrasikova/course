#pragma once
using namespace System;
using namespace System::Collections::Generic;
public ref class Letter
{
private:
    Char let; // ������ �����

public:
    // �����������
    Letter(Char letter)  
    {
        let = letter;
    }

    // ����� ��� ��������� �����
    Char getvalue() {
        return let;
    }
};

