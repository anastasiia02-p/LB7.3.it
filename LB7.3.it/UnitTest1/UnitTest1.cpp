#include "pch.h"
#include "CppUnitTest.h"
#include "../LB7.3.it/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            int rowCount = 3;
            int colCount = 3;
            int** a = new int* [rowCount];
            for (int i = 0; i < rowCount; i++)
                a[i] = new int[colCount];


            a[0][0] = -1; a[0][1] = 0; a[0][2] = -3;
            a[1][0] = 0;  a[1][1] = 0; a[1][2] = 0;
            a[2][0] = 2;  a[2][1] = 4; a[2][2] = 6;

          
            int firstPositiveRow = FindFirstPositiveRow(a, rowCount, colCount);
            Assert::AreEqual(2, firstPositiveRow); // Перший рядок з позитивним елементом - 2

            for (int i = 0; i < rowCount; i++)
                delete[] a[i];
            delete[] a;
		}
	};
}
