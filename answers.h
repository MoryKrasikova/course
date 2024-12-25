#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;
public ref class answers
{
protected:
    int wronganswers; // ���������� �������� �������
    int rightanswers; // ���������� ������
    int tries; // ���������� �������
    String^ currentword;// ������� �����
    List<String^>^ letters; // ������ ��� �������� �������� ����
public:
    // �����������
    answers(int w, int r, int t) : wronganswers(w), rightanswers(r), tries(t){
        letters = gcnew List<String^>();
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
        letters->Add(letter);
    }

    void check(String^ answer, int wordlength, String^ %usedletters, String^ %anspeople, Label^ outputLabel, int %picture) {
        int kol = 0; 
        int kol1 = 0;

        for (int i = 0; i < wordlength; i++) {
            if (answer[0] == currentword[i]) {
                kol += 1;
                anspeople = anspeople->Remove(i*2, 1);
                anspeople = anspeople->Insert(i*2, currentword[i].ToString()); // ��������� ����� � ansPeople

            }
        }
        for (int i = 0; i < usedletters->Length; i++) {
            if (answer[0] == usedletters[i]) { // ��������� ��� ����� ��������
                kol1 += 1;
                usedletters = usedletters->Remove(i, 1);
                usedletters = usedletters->Insert(i, ".");  // ������� �������������� �����
            }
        }
        if (kol > 0 && kol1>0) { 
            rightanswers += 1;
            outputLabel->Text = String::Format("�� ������� �����: {0}", anspeople);
            outputLabel->Text += String::Format("\n� ��� �������� {0} �������.", tries);
        }
        else { 
            wronganswers += 1;
            outputLabel->Text = String::Format("�� �� ������� ����� ��� ��� ������������ ��: {0}", anspeople);
            tries = 6 - wronganswers; 
            outputLabel->Text += String::Format("\n� ��� �������� {0} �������.", tries);
            picture += 1;
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

