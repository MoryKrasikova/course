#pragma once
using namespace System;
using namespace System::Collections::Generic;
ref class letter
{
private:
    System::Char let; // ������ �����

public:
    // �����������
    letter(System::Char letter) 
    {
        let = letter;
    }

    // ����� ��� ��������� �����
    System::Char getValue(){
        return let;
    }
};

