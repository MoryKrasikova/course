#pragma once
using namespace System;
using namespace System::Collections::Generic;
public ref class Letter
{
private:
    String^ let; // ������ �����

public:
    // �����������
    Letter(String^ letter)  
    {
        let = letter;
    }

    // ����� ��� ��������� �����
    String^ getvalue() {
        return let;
    }
};

