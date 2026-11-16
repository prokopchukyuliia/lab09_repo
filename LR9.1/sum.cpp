#include <cmath>
#include "dod.h"
#include "sum.h"
#include "var.h"

using namespace nsDod;
using namespace nsVar;

void nsSum::sum() 
{
    n = 0;
    a = x; // перший доданок
    s = a; // сума поки що дорівнює першому доданку
    do {
        n++;
        dod(); // обчислюємо наступний доданок
        s += a; // додаємо його до суми
    } while (fabs(a) > e); // повторюємо, поки доданок більший за точність
}