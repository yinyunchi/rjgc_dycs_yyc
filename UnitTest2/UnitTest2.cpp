#include "pch.h"
#include "CppUnitTest.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
int max(int a, int b) {
    int t = a;
    if (b > a)
    {
        t = b;
    }
    return t;
}
int Scan(int arry[], int cnt) {
    int flag = 1, t = 0,res = -1, sum = 0;
    for (int i = 0; i < cnt; i++)
    {
        if (arry[i] > 0)
        {
            flag = 0;
        }
    }
    if (flag == 1)
    {
        t = 0;
    }
    else
    {
        for (int i = 0; i < cnt; i++) {
            if (sum < 0) {
                sum = arry[i];
            }
            else {
                sum += arry[i];
            }
            res = max(res, sum);
        }
        t = res;
    }
    return t;
}
namespace UnitTest2
{
	TEST_CLASS(UnitTest2)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            int cnt = 6;
            int Array[] = { -2,11,-4,13,-5,-2 };
            Assert::AreEqual(Scan(Array,cnt), 20);

		}
        TEST_METHOD(TestMethod2)
        {
            int cnt = 6;
            int Array[] = { -2,-11,-4,-13,-5,-2 };
            Assert::AreEqual(Scan(Array,cnt), 0);
        }
        TEST_METHOD(TestMethod3)
        {
            int cnt = 7;
            int Array[] = { -2,-11,-4,-13,5,-2 ,99};
            Assert::AreEqual(Scan(Array, cnt), 102);
        }
	};
}
