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
    int win; // ���������� ���������
    int loss; // ���������� ����������
    static int gamesplayed; // ���������� ���

public:
    // �����������
    gameresult() : answers(0, 0, 6), win(0), loss(0) {}

    // ����� ��� ����������� ���������� � Label
    void displayatats(Label^ outputLabel2) {
        outputLabel2->Text += String::Format("��������� �����: ");
        for (int i = 0; i < letters->Count; ++i) {
            outputLabel2->Text += String::Format("{0} ", letters[i]);
        }
        outputLabel2->Text += String::Format("\n");
        outputLabel2->Text += String::Format("���������� �������:\n");
        outputLabel2->Text += String::Format("������ ������: {0}\n",rightanswers);
        outputLabel2->Text += String::Format("�������� ������: {0}\n", wronganswers);
        outputLabel2->Text += String::Format("�������: {0}\n", wronganswers + rightanswers);

    }

    void kolwin() {
        String^ filename = "wins.txt";

        // ��������, ���������� �� ����, ���� ���, ������� ���
        if (!File::Exists(filename)) {
            File::Create(filename)->Close(); 
        }

        StreamWriter^ writer = gcnew StreamWriter(filename, true); // true ��� ����������
        writer->WriteLine(wronganswers + rightanswers);
        writer->Close(); 
    }

    void kolloss() {
        String^ filename = "loss.txt";
        int losscount = 0; 
        // ��������, ���������� �� ����, ���� ���, ������� ���
        if (!File::Exists(filename)) {
            File::Create(filename)->Close(); 
        }
        else {
            // ������ �������� ���������� ����������
            StreamReader^ reader = gcnew StreamReader(filename);
            String^ line = reader->ReadLine();
            if (line != nullptr) {
                losscount = Int32::Parse(line); // �������������� ������ � �����
            }
            reader->Close(); 
        }

        losscount++;

        // ������ ������������ ���������� ���������� � ����
        StreamWriter^ writer = gcnew StreamWriter(filename, false); // false ��� ����������
        writer->WriteLine(losscount); 
        writer->Close(); 
    }
    int gettries()
    {
        int kol = wronganswers + rightanswers;
        return kol;
    }
};

