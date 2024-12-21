#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;
public ref class word
{
    String^ randomword; 
    int length; 

public:
    // �����������
    word() : length(0) {}

    // ����������
    ~word() {}

    // ����� ��� ������ ���������� �����
    void selectrandomword(String^ filename) {
        List<String^>^ words = gcnew List<String^>(); // ������ ��� �������� ����
        StreamReader^ file = gcnew StreamReader(filename); 

        String^ word;
        // ��������� ��� ������ �� �����
        String^ line = file->ReadLine();
        file->Close(); 

        if (line != nullptr) {
            // ��������� ������ �� ����� �� ��������
            array<String^>^ splitWords = line->Split(' ');

            // ��������� ������ ����� � ������
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

    // ����� ��� ��������� �����
    String^ getrandomword() {
        return randomword;
    }

    // ����� ��� ��������� ����� �����
    int getlength() {
        return length;
    }
};

