#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;
#include "Letter.h"
ref class answers
{
protected:
    int wronganswers; // ���������� �������� �������
    int rightanswers; // ���������� ������
    int tries; // ���������� �������
private:
    String^ currentword; // ������� �����
    List<Letter^>^ letters; // ������ ��� �������� �������� ����
public:
    // �����������
    answers(int w, int r, int t) : wronganswers(w), rightanswers(r), tries(t) {
        letters = gcnew List<Letter^>(); 
    }

    // ����������
    ~answers() {
    }

    // ����� ��� ��������� �����
private:
    void setCurrentWord(String^ word) {
        currentword = word;
    }

public:
    void setAnswer(char ans) {
        addLetter(ans); 
    }

    String^ getCurrentWord() {
        return currentword;
    }

    void addLetter(char letter) {
        letters->Add(gcnew Letter(letter));
    }

    void check(char answer, int wordlength, String^% usedletters, String^% anspeople, Label^ outputLabel) {
        int kol = 0; 
        int kol1 = 0; 

        for (int i = 0; i < wordlength; i++) {
            if (answer == currentword[i]) { 
                kol += 1;
                anspeople = anspeople->Remove(i, 1)->Insert(i, currentword[i].ToString()); // ��������� ����� � ansPeople
            }
        }

        for (int i = 0; i < usedletters->Length; i++) {
            if (answer == usedletters[i]) {
                kol1 += 1;
                usedletters = usedletters->Remove(i, 1)->Insert(i, "."); 
            }
        }


        if (kol > 0 && kol1 > 0) { 
            rightanswers += 1;
            outputLabel->Text = String::Format("�� ������� �����: {0}", anspeople);
        }
        else { 
            wronganswers += 1;
            outputLabel->Text = String::Format("�� �� ������� ����� ��� ��� ������������ �: {0}", anspeople);
            tries = 6 - wronganswers; 
            outputLabel->Text += String::Format("\n� ��� �������� {0} �������.", tries);
        }
    }
    // ����� ��� ��������� ���������� ������ �������
    int getRightAnswers()  {
        return rightanswers;
    }

    // ����� ��� ��������� ���������� �������� �������
    int getWrongAnswers() {
        return wronganswers;
    }
    //����� ��� ������ �������������� ����
    void displayLetters(Label^ outputLabel1) {
        outputLabel1->Text = String::Format("��������� �����: ");
        for (int i = 0; i < letters->Count; ++i) {
            outputLabel1->Text += String::Format("{0} ", letters[i]->getValue());
        }
        outputLabel1->Text += String::Format("\n");
    }

};

