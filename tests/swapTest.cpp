#include "CppUTest/TestHarness.h"
extern "C" {
    extern void swap2int(int *a, int *b);
    extern void swapArrWithIdx(int arr[], int i, int j);
}

TEST_GROUP(swap)
{
    void setup()
    {
    }
    void teardown()
    {
    }
};

TEST(swap, swapFunctions)
{
	int a = 3, b = -1;
	swap2int(&a, &b);
    LONGS_EQUAL(-1, a);
    LONGS_EQUAL(3, b);
    swap2int(&a, &b);
    LONGS_EQUAL(3, a);
    LONGS_EQUAL(-1, b);
    
    int arr[4] = {10, -1, 3, 0};
    LONGS_EQUAL(10, arr[0]);
    LONGS_EQUAL(-1, arr[1]);
    LONGS_EQUAL(3, arr[2]);
    LONGS_EQUAL(0, arr[3]);
    swapArrWithIdx(arr, 3, 0);
    LONGS_EQUAL(0, arr[0]);
    LONGS_EQUAL(10, arr[3]);
}
