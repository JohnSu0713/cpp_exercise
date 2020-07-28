#ifndef __COOLARRAY_
#define __COOLARRAY_

#include <iostream>
#include <string>
#include <stdlib.h> /* srand, rand */
#include <time.h>   /* time */
#include "coolArray.h"
using namespace std;

class Array
{

private:
    int m_size;
    int m_length;
    int *m_pNode;

public:
    Array(/* 利用constructor Initialize */);

    Array(int size, int length);

    //構建一個操作符重載
    Array operator=(const Array &arr);

    void init_rand();

    void display();

    void info();

    void append(int x);

    void insert(int pos, int data);

    void delete_index(int pos);

    void swap(int index_x, int index_y);

    int linearSearch(int key);

    int linearSearch_trans(int key);

    int linearSearch_move_to_heaven(int key);

    int binarySearch(int key);

    int binarySearch_recursion(int l, int h, int key);

    int get(int pos);

    void set(int pos, int data);

    int max();

    int min();

    int sum();

    //ｎ要傳長度
    int sum_recursion(int n);

    int avg();

    void reverse_copy();

    void reverse_swap();

    void left_shift();

    void left_rotate();

    bool isSorted();

    void insert_sorted(int data);

    void negative_shift_left();

    Array merge_arr(Array &array);

    //Set operation
    //Union: 和merge唯一不同為當兩者相同時，只copy其一
    Array union_unsorted(const Array &arr);

    Array union_sorted(const Array &arr);

    //intersection_unsorted: O(n**2)
    Array intersection_unsorted(Array const &arr);

    //intersection_sorted: O(n)
    Array intersection_sorted(Array const &arr);

    Array difference_unsorted(Array const &arr);

    Array difference_sorted(Array const &arr);

    void find_missing();

    void multiple_finding();

    void hashTable_finding();

    void find_duplicated(); //必須sorted

    void find_duplicated_unsorted();

    void find_duplicated_hashTable(); //必須sorted

    ~Array();
};

#endif // !__COOLARRAY_
