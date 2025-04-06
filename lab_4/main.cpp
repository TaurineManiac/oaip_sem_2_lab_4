#include <iostream>
#include <random>
#include <inputCheck.h>
#include "header.h"
#include <locale>

using namespace std;
using namespace mylib;

int main() {
    setlocale(LC_ALL, "Russian");

    // Ввод максимального размера дека
    cout << "Введите максимальный размер дека: ";
    int maxSize = checkTryToInputMaxSizeOfSmth();

    // Создаём дек
    Deququququque dq(maxSize);

    // Инициализация генератора случайных чисел
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dist(-100.0, 100.0);

    // Заполняем дек случайными числами
    cout << "Заполняем дек случайными числами..." << endl;
    for (int i = 0; i < maxSize; i++) {
        double randomNum = dist(gen);
        dq.addBack(randomNum);  // Исправлено: dq.addBack(randomNum)
    }
    dq.printALL();

    // Этап: добавление справа и удаление слева
    cout << "\nПереходим в режим ввода с удалением левого элемента." << endl;
    while (true) {
        cout << "1 - Ввести число для добавления справа.\n"
             << "2 - Выход.\n";
        int solution = checkYourSolution(2);
        if (solution == 1) {
            double num = checkTryToInputDouble();
            if (!dq.isEmpty()) {
                cout << "Дек до: " << endl;
                dq.printALL();
                cout << "Удаляем левый элемент: " << endl;
                dq.deleteFront();
                dq.printALL();
            }
            dq.addBack(num);
            cout << "Добавлено справа: " << num << endl;
            dq.printALL();
        } else if (solution == 2) {
            cout << "Выход из программы." << endl;
            break;  // Исправлено: break находится внутри цикла
        }
    }

    return 0;
}