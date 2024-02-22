#include "pch.h"
#include "CppUnitTest.h"
#include "../LB_7.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestCreate)
		{
			const int rowCount = 7;
			const int colCount = 6;
			int** a = new int* [rowCount];
			for (int i = 0; i < rowCount; ++i)
				a[i] = new int[colCount];

			Create(a, rowCount, colCount, 9, 61); 

			for (int i = 0; i < rowCount; ++i)
				for (int j = 0; j < colCount; ++j)
					Assert::IsTrue(a[i][j] >= 9 && a[i][j] <= 61);

			for (int i = 0; i < rowCount; ++i)
				delete[] a[i];
			delete[] a;
		}

		TEST_METHOD(TestSort)
		{
			const int rowCount = 7;
			const int colCount = 6;
			int** a = new int* [rowCount];
			for (int i = 0; i < rowCount; ++i)
				a[i] = new int[colCount];

			int testArray[rowCount][colCount] = {
				{5, 3, 4, 2, 1, 6},
				{1, 2, 3, 4, 5, 6},
				{6, 5, 4, 3, 2, 1},
				{4, 3, 6, 5, 1, 2},
				{1, 2, 3, 4, 5, 6},
				{6, 5, 4, 3, 2, 1},
				{5, 3, 4, 2, 1, 6}
			};

			for (int i = 0; i < rowCount; ++i)
				for (int j = 0; j < colCount; ++j)
					a[i][j] = testArray[i][j];

			Sort(a, rowCount, colCount);

			for (int i = 0; i < rowCount - 1; ++i)
				Assert::IsTrue(a[i][0] <= a[i + 1][0] ||
					(a[i][0] == a[i + 1][0] && a[i][1] >= a[i + 1][1]) ||
					(a[i][0] == a[i + 1][0] && a[i][1] == a[i + 1][1] && a[i][2] >= a[i + 1][2]));

			for (int i = 0; i < rowCount; ++i)
				delete[] a[i];
			delete[] a;
		}

		TEST_METHOD(TestCalc)
		{
			const int rowCount = 7;
			const int colCount = 6;
			int** a = new int* [rowCount];
			for (int i = 0; i < rowCount; ++i)
				a[i] = new int[colCount];

			int testArray[rowCount][colCount] = {
				{10, 20, 30, 40, 50, 60},
				{11, 21, 31, 41, 51, 61},
				{12, 22, 32, 42, 52, 62},
				{13, 23, 33, 43, 53, 63},
				{14, 24, 34, 44, 54, 64},
				{15, 25, 35, 45, 55, 65},
				{16, 26, 36, 46, 56, 66}
			};

			for (int i = 0; i < rowCount; ++i)
				for (int j = 0; j < colCount; ++j)
					a[i][j] = testArray[i][j];

			int S, k;
			Calc(a, rowCount, colCount, S, k);

		
			Assert::IsTrue(S != 0);
			Assert::IsTrue(k != 0);

			for (int i = 0; i < rowCount; ++i)
				delete[] a[i];
			delete[] a;
		}
	};
}
