#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;
public ref class answers
{
protected:
    int wronganswers; // Количество неверных ответов
    int rightanswers; // Количество верных
    int tries; // Количество попыток
    String^ currentword;// Текущее слово
    List<String^>^ letters; // Список для хранения введённых букв
public:
    // Конструктор
    answers(int w, int r, int t) : wronganswers(w), rightanswers(r), tries(t){
        letters = gcnew List<String^>();
    }

    // Деструктор
    ~answers() {
    }

public:
    // Метод для установки слова
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
                anspeople = anspeople->Insert(i*2, currentword[i].ToString()); // Открываем букву в ansPeople

            }
        }
        for (int i = 0; i < usedletters->Length; i++) {
            if (answer[0] == usedletters[i]) { // Сравнение без учета регистра
                kol1 += 1;
                usedletters = usedletters->Remove(i, 1);
                usedletters = usedletters->Insert(i, ".");  // Убираем использованную букву
            }
        }
        if (kol > 0 && kol1>0) { 
            rightanswers += 1;
            outputLabel->Text = String::Format("Вы угадали букву: {0}", anspeople);
            outputLabel->Text += String::Format("\nУ вас осталось {0} попыток.", tries);
        }
        else { 
            wronganswers += 1;
            outputLabel->Text = String::Format("Вы не угадали букву или уже использовали ее: {0}", anspeople);
            tries = 6 - wronganswers; 
            outputLabel->Text += String::Format("\nУ вас осталось {0} попыток.", tries);
            picture += 1;
        }
    }
    // Метод для получения количества верных ответов
    int getrightanswers()  {
        return rightanswers;
    }

    // Метод для получения количества неверных ответов
    int getwronganswers() {
        return wronganswers;
    }


};

