#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;
#include "answers.h"
public ref class gameresult :
    public answers
{
private:
    int win; // ���������� ���������
    int loss; // ���������� ����������
    int winresult; // ����� ��� ��������
    int kol; // ����� ���������� �������
    static int gamesplayed; // ���������� ���

public:
    // �����������
    gameresult() : answers(0, 0, 6), win(0), loss(0), winresult(0), kol(0) {}

    // ����� ��� ����������� ���������� � Label
    void displayatats(Label^ outputLabel2) {
        outputLabel2->Text += String::Format("��������� �����: ");
        for (int i = 0; i < letters->Count; ++i) {
            outputLabel2->Text += String::Format("{0} ", letters[i]->getvalue());
        }
        outputLabel2->Text += String::Format("\n");
        outputLabel2->Text += String::Format("���������� �������:\n");
        outputLabel2->Text += String::Format("������ ������: {0}\n",rightanswers);
        outputLabel2->Text += String::Format("�������� ������: {0}\n", wronganswers);
        outputLabel2->Text += String::Format("���������� ���:\n");
        outputLabel2->Text += String::Format("��������: {0}\n", win);
        outputLabel2->Text += String::Format("���������: {0}\n", loss);
        outputLabel2->Text += String::Format("�������: {0}\n", kol);

    }

    void kolwin() {
        win += 1;
    }

    int getwin() {
        return win;
    }

    void kolloss() {
        loss += 1;
    }

    void getloss(int% loss) {
        loss = this->loss;
        kol = rightanswers + wronganswers;
    }

    void getwinresult(int% winresult) {
        winresult = rightanswers + wronganswers;
        this->winresult = winresult;
        kol = this->winresult;
    }
};

