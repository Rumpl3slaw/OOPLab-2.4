#include "pch.h"
#include "CppUnitTest.h"
#include "../OOPLab 2.4/Matrix.cpp"
#include "../OOPLab 2.4/CalcnormMatrices.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{

			Matrix A(2);
			A[0][0] = 7; A[0][1] = 7;
			A[1][0] = 7; A[1][1] = 7;

			Assert::AreEqual(A.CalcnormMatrices(), 14.0);
		}
	};
}
