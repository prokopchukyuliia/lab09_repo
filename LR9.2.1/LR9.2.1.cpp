// LR9.2.1.cpp
// < Прокопчук Юлія >
// Лабораторна робота № 9.2.1
// Директиви препроцесора
// Варіант 24

#include <iostream>
#include "macros.h"

#define Z 7

using namespace std;

int main()
{
    double x; // змінна, яку вводить користувач
    double w; // результат

    cout << "Enter x: ";
    cin >> x;

#if Z > 5 && Z < 10
    // гілка 1: 5 < z < 10
    cout << "Branch: 5 < z < 10" << endl;
    w = MIN(x, Z) * MAX(x + Z, x * Z);
#else
    // гілка 2: z <= 5 або z >= 10
    cout << "Branch: z <= 5 or z >= 10" << endl;
    w = SQR(MAX(ABS(x - Z), Z));
#endif

    PRINT_RESULT(w);

    return 0;
}