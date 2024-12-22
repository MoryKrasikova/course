#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;
#include "answers.h"
public ref class gameresult :
    public answers
{
private:
    int win; // Количество выигрышей
    int loss; // Количество проигрышей
    int winresult; // Баллы при выигрыше
    int kol; // Общее количество попыток
    static int gamesplayed; // Статистика игр

public:
    // Конструктор
    gameresult() : answers(0, 0, 6), win(0), loss(0), winresult(0), kol(0) {}

    // Метод для отображения статистики в Label
    void displayatats(Label^ outputLabel2) {
        outputLabel2->Text += String::Format("Введенные буквы: ");
        for (int i = 0; i < letters->Count; ++i) {
            outputLabel2->Text += String::Format("{0} ", letters[i]->getvalue());
        }
        outputLabel2->Text += String::Format("\n");
        outputLabel2->Text += String::Format("Статистика ответов:\n");
        outputLabel2->Text += String::Format("Верные ответы: {0}\n",rightanswers);
        outputLabel2->Text += String::Format("Неверные ответы: {0}\n", wronganswers);
        outputLabel2->Text += String::Format("Статистика игр:\n");
        outputLabel2->Text += String::Format("Выигрыши: {0}\n", win);
        outputLabel2->Text += String::Format("Проигрыши: {0}\n", loss);
        outputLabel2->Text += String::Format("Попытки: {0}\n", kol);

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

