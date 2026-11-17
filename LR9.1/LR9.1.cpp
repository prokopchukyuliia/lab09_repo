// LR9.1.cpp
// < Прокопчук Юлія >
// Лабораторна робота № 9.1
// Простори імен 
// Варіант 24


#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include "sum.h"
#include "var.h"

using namespace std;
using namespace nsSum;
using namespace nsVar;

int main() 
{
    cout << "x_p = "; cin >> x_p;
    cout << "x_k = "; cin >> x_k;
    cout << "dx  = "; cin >> dx;
    cout << "eps = "; cin >> e;
    cout << endl;

    const string line = "+----------+-------------+-------------+--------+";

    cout << "Table of ln(x+1) calculated by Taylor series" << endl;
    cout << line << endl;
    cout << "| " << setw(8) << "x"
        << " | " << setw(11) << "ln(x+1)"
        << " | " << setw(11) << "series sum"
        << " | " << setw(6) << "terms" << " |" << endl;
    cout << line << endl;

    cout << fixed << setprecision(4);

    x = x_p;
    while (x <= x_k) 
    {
        if (x > -1 && x <= 1) 
        {
            sum(); // обчислюємо суму ряду для поточного x

            // n + 1 - кількість доданків, бо перший доданок (n = 0) теж у сумі
            cout << "| " << setw(8) << x
                << " | " << setw(11) << log(x + 1)
                << " | " << setw(11) << s
                << " | " << setw(6) << n + 1 << " |" << endl;
        }
        else 
        {
            // x поза областю збіжності ряду - пропускаємо
            cout << "| " << setw(8) << x
                << " | " << left << setw(25) << "out of range" << right
                << " | " << setw(6) << "-" << " |" << endl;
        }

        x += dx; // наступне значення аргументу
    }
    cout << line << endl;

    cin.get();
    cin.get();
    return 0;
}