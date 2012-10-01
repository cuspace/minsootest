#include "CppUTest/TestHarness.h"
extern "C" {
    extern void rotate_right(int arr[], int s, int t);
    extern void rotate_left(int arr[], int s, int t);
    extern int get_rotated_right_idx(int cur_idx, int s, int t, int k);
    extern void last_k_backup(int arr[], int last[], int s, int t, int k);
    extern void rotate_rightk(int arr[], int s, int t, int k);
}

TEST_GROUP(rotate)
{
    void setup()
    {
    }
    void teardown()
    {
    }
};

TEST(rotate, rotateFunctions)
{
    int arr[6] = {10, -1, 3, 0, 400, 500};
    rotate_right(arr, 1, 4);
    LONGS_EQUAL(10, arr[0]);
    LONGS_EQUAL(400, arr[1]);
    LONGS_EQUAL(-1, arr[2]);
    LONGS_EQUAL(3, arr[3]);
    LONGS_EQUAL(0, arr[4]);
    LONGS_EQUAL(500, arr[5]);

    int arr2[6] = {10, -1, 3, 0, 400, 500};
    rotate_left(arr2, 1, 4);
    LONGS_EQUAL(10, arr2[0]);
    LONGS_EQUAL(3, arr2[1]);
    LONGS_EQUAL(0, arr2[2]);
    LONGS_EQUAL(400, arr2[3]);
    LONGS_EQUAL(-1, arr2[4]);
    LONGS_EQUAL(500, arr2[5]);
    
    int arr3[6] = {0, 1, 2, 3, 4, 5};
    LONGS_EQUAL(3, get_rotated_right_idx(1, 1, 4, 2));
    LONGS_EQUAL(4, get_rotated_right_idx(2, 1, 4, 2));
    LONGS_EQUAL(1, get_rotated_right_idx(3, 1, 4, 2));
    LONGS_EQUAL(2, get_rotated_right_idx(4, 1, 4, 2));
    LONGS_EQUAL(1, get_rotated_right_idx(2, 1, 4, 3));
    LONGS_EQUAL(2, get_rotated_right_idx(3, 1, 4, 3));
    LONGS_EQUAL(3, get_rotated_right_idx(4, 1, 4, 3));

    int last[4] = {99, 99, 99, 99};
    last_k_backup(arr3, last, 1, 4, 2);
    LONGS_EQUAL(3, last[0]);
    LONGS_EQUAL(4, last[1]);
    last_k_backup(arr3, last, 2, 5, 3);
    LONGS_EQUAL(3, last[0]);
    LONGS_EQUAL(4, last[1]);
    LONGS_EQUAL(5, last[2]);

    rotate_rightk(arr3, 1, 4, 2);
    LONGS_EQUAL(0, arr3[0]);
    LONGS_EQUAL(3, arr3[1]);
    LONGS_EQUAL(4, arr3[2]);
    LONGS_EQUAL(1, arr3[3]);
    LONGS_EQUAL(2, arr3[4]);
    
    int arr4[8] = {1,2,3,4,5,6,7,8};
    rotate_rightk(arr4, 2, 7, 4);//3,4,5,6,7,8
    LONGS_EQUAL(1, arr4[0]);
    LONGS_EQUAL(2, arr4[1]);
    LONGS_EQUAL(5, arr4[2]);
    LONGS_EQUAL(6, arr4[3]);
    LONGS_EQUAL(7, arr4[4]);
    LONGS_EQUAL(8, arr4[5]);
    LONGS_EQUAL(3, arr4[6]);
    LONGS_EQUAL(4, arr4[7]);
}
