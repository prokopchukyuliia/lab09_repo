#include "pch.h"
#include "CppUnitTest.h"
#include <cmath>

#include "../LR9.1/var.cpp"
#include "../LR9.1/dod.cpp"
#include "../LR9.1/sum.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestSum
{
    TEST_CLASS(UnitTest1)
    {
    public:
        // перевірка для додатного x
        TEST_METHOD(TestPositiveX)
        {
            nsVar::x = 0.5;
            nsVar::e = 0.0001;
            nsSum::sum();

            // сума ряду має збігатися з log(x + 1) з точністю e
            Assert::AreEqual(log(nsVar::x + 1), nsVar::s, nsVar::e);
        }

        // перевірка для від'ємного x
        TEST_METHOD(TestNegativeX)
        {
            nsVar::x = -0.5;
            nsVar::e = 0.0001;
            nsSum::sum();

            Assert::AreEqual(log(nsVar::x + 1), nsVar::s, nsVar::e);
        }

        // перевірка для x = 0, сума має дорівнювати 0
        TEST_METHOD(TestZeroX)
        {
            nsVar::x = 0;
            nsVar::e = 0.0001;
            nsSum::sum();

            Assert::AreEqual(0.0, nsVar::s, nsVar::e);
        }
    };
}