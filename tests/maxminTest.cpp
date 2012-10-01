#include "CppUTest/TestHarness.h"
extern "C" {
//#include "max3int.h"
    extern int max3int(int a, int b, int c);
    extern int maxarr(int arr[], int length);
}

TEST_GROUP(maxalgo)
{
    int arr1[3];
    
    void setup()
    {
        arr1[0] = -65535;
        arr1[1] = -65536;
        arr1[2] = -65537;
    }
    void teardown()
    {
    }
};

TEST(maxalgo, max3int)
{
    LONGS_EQUAL(3, max3int(1, 2, 3));
    LONGS_EQUAL(2, max3int(-5, 2, -200));
    LONGS_EQUAL(32768, max3int(32768, 2, 3));
    LONGS_EQUAL(65536, max3int(-65536, 65536, 3));
    LONGS_EQUAL(1, max3int(1, 1, 1));
    LONGS_EQUAL(-1, max3int(-1, -2, -3));
}

TEST(maxalgo, maxarr)
{
    LONGS_EQUAL(-65535, maxarr(arr1, 3));
}
