#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;
#include "Letter.h"
public ref class answers
{
protected:
    int wronganswers; // ���������� �������� �������
    int rightanswers; // ���������� ������
    int tries; // ���������� �������
    String^ currentword;// ������� �����
    List<Letter^>^ letters; // ������ ��� �������� �������� ����
public:
    // �����������
    answers(int w, int r, int t) : wronganswers(w), rightanswers(r), tries(t){
        letters = gcnew List<Letter^>(); 
    }

    // ����������
    ~answers() {
    }

public:
    // ����� ��� ��������� �����
    void setcurrentword(String^ word) {
        currentword = word;
    }

    void setanswer(String^ ans) {
        addletter(ans); 
    }

    String^ getcurrentword() {
        return currentword;
    }

    void addletter(String^ letter) {
        letters->Add(gcnew Letter(letter));
    }

    void check(String^ answer, int wordlength, String^ %usedletters, String^ %anspeople, Label^ outputLabel) {
        int kol = 0; 
        int kol1 = 0;

        for (int i = 0; i < wordlength; i++) {
            if (currentword[i] == answer[0]) {
                kol += 1;
                anspeople = anspeople->Remove(i, 1);
                anspeople = anspeople->Insert(i, currentword[i].ToString()); // ��������� ����� � ansPeople
            }
        }
        for (int i = 0; i < usedletters->Length; i++) {
            if (answer[0] == usedletters[i]) { // ��������� ��� ����� ��������
                kol1 += 1;
                usedletters = usedletters->Remove(i, 1)->Insert(i, ".");  // ������� �������������� �����
            }
        }
        if (kol > 0) { 
            rightanswers += 1;
            outputLabel->Text = String::Format("�� ������� �����: {0}", anspeople);
            outputLabel->Text += String::Format("\n� ��� �������� {0} �������.", tries);
        }
        else { 
            wronganswers += 1;
            outputLabel->Text = String::Format("�� �� ������� ����� ��� ��� ������������ ��: {0}", anspeople);
            tries = 6 - wronganswers; 
            outputLabel->Text += String::Format("\n� ��� �������� {0} �������.", tries);
        }
    }
    // ����� ��� ��������� ���������� ������ �������
    int getrightanswers()  {
        return rightanswers;
    }

    // ����� ��� ��������� ���������� �������� �������
    int getwronganswers() {
        return wronganswers;
    }


};

