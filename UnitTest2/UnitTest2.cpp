#include "pch.h"
#include "CppUnitTest.h"
#include "../LR9.2.1/macros.h" // макроси беремо з головного проєкту

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

// формула гілки 5 < z < 10, записана через макроси
double Branch1(double x, double z)
{
    return MIN(x, z) * MAX(x + z, x * z);
}

// формула гілки z <= 5 або z >= 10, записана через макроси
double Branch2(double x, double z)
{
    return SQR(MAX(ABS(x - z), z));
}

namespace UnitTestMacros
{
    TEST_CLASS(UnitTest2)
    {
    public:
        // перевірка базових макросів
        TEST_METHOD(TestBasicMacros)
        {
            Assert::AreEqual(5.0, (double)MAX(2, 5));   // більше з двох
            Assert::AreEqual(2.0, (double)MIN(2, 5));   // менше з двох
            Assert::AreEqual(4.0, (double)ABS(-4));     // модуль
            Assert::AreEqual(9.0, (double)SQR(3));      // квадрат
        }

        // гілка 5 < z < 10: x = 2, z = 7 -> 28
        TEST_METHOD(TestBranch1_SmallX)
        {
            Assert::AreEqual(28.0, Branch1(2, 7));
        }

        // гілка 5 < z < 10: x = 8, z = 7 -> 392
        TEST_METHOD(TestBranch1_LargeX)
        {
            Assert::AreEqual(392.0, Branch1(8, 7));
        }

        // гілка z <= 5: x = 2, z = 3 -> 9
        TEST_METHOD(TestBranch2_SmallZ)
        {
            Assert::AreEqual(9.0, Branch2(2, 3));
        }

        // гілка z >= 10: x = 8, z = 12 -> 144
        TEST_METHOD(TestBranch2_LargeZ)
        {
            Assert::AreEqual(144.0, Branch2(8, 12));
        }
    };
}