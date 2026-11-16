#include "dod.h"
#include "var.h"

using namespace nsVar;

void nsDod::dod() 
{
    // новий доданок = попередній, помножений на коефіцієнт рекурентності
    a *= -x * n / (n + 1);
}