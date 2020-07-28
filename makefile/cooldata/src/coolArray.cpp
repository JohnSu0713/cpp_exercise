#include <iostream>
#include <string>
#include <stdlib.h> /* srand, rand */
#include <time.h>   /* time */
#include "coolArray.h"
using namespace std;

Array::Array(/* 利用constructor Initialize */)
{
    std::cout << "Enter Array m_size: " << flush;
    cin >> this->m_size;
    m_pNode = new int[this->m_size];
    std::cout << "Enter the number of elements: " << flush;
    cin >> this->m_length;

    for (int i = 0; i < this->m_length; i++)
    {
        cout << "Enter your elements in index " << i << ": " << flush;
        cin >> m_pNode[i];
    }
}

Array::Array(int m_size, int m_length)
{
    this->m_size = m_size;
    m_pNode = new int[this->m_size];
    this->m_length = m_length;
}

//構建一個操作符重載
Array Array::operator=(const Array &arr)
{
    Array res(this->m_size + arr.m_size, this->m_length + arr.m_length);
    return res;
}

void Array::init_rand()
{
    /* initialize random seed: */
    srand(time(NULL));

    for (int i = 0; i < this->m_length; i++)
    {
        m_pNode[i] = rand() % 100 + 1;
    }
}

void Array::display()
{
    for (int i = 0; i < this->m_length; i++)
    {
        cout << m_pNode[i] << " ";
    }
    printf("\n");
}

void Array::info()
{
    std::cout << "m_length = " << this->m_length << std::endl;
    std::cout << "size = " << this->m_size << std::endl;
    std::cout << "address = " << this->m_pNode << std::endl;
}

void Array::append(int x)
{
    //check if it's full
    if (this->m_size == this->m_length)
    {
        std::cout << "Array has been full!!..." << std::endl;
        return;
    }

    //append (push_back)
    m_pNode[this->m_length] = x;
    this->m_length++;
}

void Array::insert(int pos, int data)
{
    //check if it's full
    if (this->m_size == this->m_length)
    {
        std::cout << "Array has been full!!..." << std::endl;
        return;
    }

    //insert: 把從要插入位置所有人後移（含本身）
    for (int i = this->m_length; i > pos; i--)
    {
        //後移
        m_pNode[i] = m_pNode[i - 1];
    }
    m_pNode[pos] = data;
    this->m_length++;
}
void Array::delete_index(int pos)
{
    //check if it's empty
    if (this->m_length == 0)
    {
        std::cout << "Array is Empty!..." << std::endl;
    }

    //delete: 把所有指定pos後方的data前移覆蓋
    for (int i = pos; i < this->m_length; i++)
    {
        m_pNode[i] = m_pNode[i + 1];
    }

    this->m_length--;
}
void Array::swap(int index_x, int index_y)
{
    int temp = 0;
    if (index_x > this->m_length || index_y > this->m_length)
    {
        std::cout << "Error index!!" << std::endl;
        return;
    }

    temp = m_pNode[index_x];
    m_pNode[index_x] = m_pNode[index_y];
    m_pNode[index_y] = temp;
}

int Array::linearSearch(int key)
{
    for (int i = 0; i < this->m_length; i++)
    {
        //return first elements if find.
        if (m_pNode[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int Array::linearSearch_trans(int key)
{
    for (int i = 0; i < this->m_length; i++)
    {
        //return first elements if find.
        if (m_pNode[i] == key)
        {
            this->swap(i, i - 1);
            return i;
        }
    }
    return -1;
}

int Array::linearSearch_move_to_heaven(int key)
{
    for (int i = 0; i < this->m_length; i++)
    {
        //return first elements if find.
        if (m_pNode[i] == key)
        {
            this->swap(i, 0);
            return i;
        }
    }
    return -1;
}

int Array::binarySearch(int key)
{
    int l = 0;
    int h = this->m_length - 1;

    //if l > h ->表示沒有找到
    while (l < h)
    {
        int mid = (l + h) / 2;

        if (key == m_pNode[mid])
        {
            return mid;
        }
        else if (key < m_pNode[mid])
        {
            h = mid - 1;
        }
        else if (key > m_pNode[mid])
        {
            l = mid + 1;
        }
    }
    return -1;
}

int Array::binarySearch_recursion(int l, int h, int key)
{

    if (l <= h)
    {
        int mid = (l + h) / 2;
        if (key == m_pNode[mid])
        {
            return mid;
        }
        else if (key < m_pNode[mid])
        {
            return this->binarySearch_recursion(l, mid - 1, key);
        }
        else if (key > m_pNode[mid])
        {
            return this->binarySearch_recursion(mid + 1, h, key);
        }
    }
    return -1;
}

int Array::get(int pos)
{
    //check valid
    if (pos < 0 || pos >= this->m_length)
    {
        return 0;
    }

    return m_pNode[pos];
}

void Array::set(int pos, int data)
{
    //check valid
    if (pos < 0 || pos >= this->m_length)
    {
        return;
    }

    m_pNode[pos] = data;
}

int Array::max()
{
    //Assume maximum is first element
    int max = this->m_pNode[0];

    for (int i = 0; i < this->m_length; i++)
    {
        if (m_pNode[i] > max)
        {
            max = m_pNode[i];
        }
    }
    return max;
}

int Array::min()
{
    //Assume maximum is first element
    int min = this->m_pNode[0];

    for (int i = 0; i < this->m_length; i++)
    {
        if (m_pNode[i] < min)
        {
            min = m_pNode[i];
        }
    }
    return min;
}

int Array::sum()
{
    int sum = m_pNode[0];

    for (int i = 1; i < this->m_length; i++)
    {
        sum += m_pNode[i];
    }

    return sum;
}

//ｎ要傳長度
int Array::sum_recursion(int n)
{
    // int sum = this->m_pNode[0];

    if (n < 0)
    {
        return 0;
    }
    return sum_recursion(n - 1) + m_pNode[n];
}

int Array::avg()
{
    return (this->sum()) / (this->m_length);
}

void Array::reverse_copy()
{
    Array reverse_cpy(this->m_size, this->m_length);
    //i 從左到右，j從右到左反轉assign給copy的array
    for (int i = 0, j = this->m_length - 1; i < this->m_length; i++, j--)
    {
        reverse_cpy.m_pNode[j] = this->m_pNode[i];
    }
    //重新assign給 this
    for (size_t i = 0; i < this->m_length; i++)
    {
        this->m_pNode[i] = reverse_cpy.m_pNode[i];
    }
}

void Array::Array::reverse_swap()
{
    for (size_t i = 0, j = this->m_length - 1; i < j; i++, j--)
    {
        int temp;
        temp = this->m_pNode[i];
        this->m_pNode[i] = this->m_pNode[j];
        this->m_pNode[j] = temp;
    }
}

void Array::left_shift()
{
    for (size_t i = 0; i < this->m_length; i++)
    {
        m_pNode[i] = m_pNode[i + 1];
    }
}

void Array::left_rotate()
{
    for (size_t i = 0; i < this->m_length; i++)
    {
        if (i == 0)
        {
            std::cout << "this->m_length = " << this->m_length << std::endl;
            m_pNode[this->m_length] = m_pNode[i];
        }
        m_pNode[i] = m_pNode[i + 1];
    }
}

bool Array::isSorted()
{
    //check arr[i+1] > arr[i]
    for (size_t i = 0; i < this->m_length; i++)
    {
        if (m_pNode[i] > m_pNode[i + 1])
        {
            return false;
        }
    }
    return true;
}

void Array::insert_sorted(int data)
{
    //check if it's full
    if (this->m_size == this->m_length)
    {
        std::cout << "Array has been full!!..." << std::endl;
        return;
    }

    int i = this->m_length - 1;
    while (m_pNode[i] > data)
    {
        m_pNode[i] = m_pNode[i + 1];
        i--;
    }
    m_pNode[i + 1] = data;
    this->m_length++;
}

void Array::negative_shift_left()
{
    int i = 0;
    int j = this->m_length - 1;

    while (i < j)
    {
        while (m_pNode[i] < 0)
        {
            i++; //keep searching
        }
        while (m_pNode[j] >= 0)
        {
            j--;
        }
        //swap()
        int temp = m_pNode[i];
        m_pNode[i] = m_pNode[j];
        m_pNode[j] = temp;
    }
}

Array Array::merge_arr(Array &array)
{
    //將自己和其他Array 合併
    int i = 0; //本身index
    int j = 0; //傳入的arr之index
    int k = 0; //回傳array之index

    int merge_m_size = this->m_size + array.m_size;
    int merge_m_length = this->m_length + array.m_length;

    Array mergeArr(merge_m_size, merge_m_length);

    //先把兩者共用的記憶體大小空間依順序填滿
    while (i < this->m_length && j < array.m_length)
    {
        if (this->m_pNode[i] < array.m_pNode[j])
        {
            mergeArr.m_pNode[k++] = this->m_pNode[i++];
        }
        else
        {
            mergeArr.m_pNode[k++] = array.m_pNode[j++];
        }
    }
    //再把剩下的放入剩下空間
    for (; i < this->m_length; i++)
    {
        mergeArr.m_pNode[k++] = this->m_pNode[i];
    }
    for (; j < array.m_length; j++)
    {
        mergeArr.m_pNode[k++] = array.m_pNode[j];
    }
    return mergeArr;
}

//Set operation

//Union: 和merge唯一不同為當兩者相同時，只copy其一
Array Array::union_unsorted(const Array &arr)
{
    //將自己和其他Array 合併
    // int i = 0; //本身index
    // int j = 0; //傳入的arr之index
    int k = 0; //回傳array之index

    //Creat return Array
    int merge_m_size = this->m_size + arr.m_size;
    int merge_m_length = this->m_length;
    Array mergeArr(merge_m_size, merge_m_length);

    //先將A copy到final array
    for (int i = 0; i < this->m_length; i++)
    {
        mergeArr.m_pNode[k++] = this->m_pNode[i];
    }

    for (int j = 0; j < arr.m_length; j++)
    {
        k = 0;
        int flag = 0;
        while (k < mergeArr.m_length)
        {
            if (arr.m_pNode[j] == mergeArr.m_pNode[k])
            {
                //利用flag標誌有重複
                flag++;
                break;
            }
            k++;
        }
        if (!flag)
        {
            mergeArr.append(arr.m_pNode[j]);
            mergeArr.m_length++;
        }
    }
    return mergeArr;
}

Array Array::union_sorted(const Array &arr)
{
    // 將自己和其他Array 合併
    int i = 0; //本身index
    int j = 0; //傳入的arr之index
    int k = 0; //回傳array之index

    //Creat return Array
    int merge_m_size = this->m_size + arr.m_size;
    int merge_m_length = this->m_length;
    Array mergeArr(merge_m_size, merge_m_length);

    int final_m_length = 0;

    //兩者個數交集範圍內
    while (i < this->m_length && j < arr.m_length)
    {
        if (this->m_pNode[i] < arr.m_pNode[j])
        {
            mergeArr.m_pNode[k++] = this->m_pNode[i++];
            final_m_length++;
        }
        else if (this->m_pNode[i] > arr.m_pNode[j])
        {
            mergeArr.m_pNode[k++] = this->m_pNode[j++];
            final_m_length++;
        }
        else
        {
            mergeArr.m_pNode[k++] = this->m_pNode[i++];
            final_m_length++;

            j++;
        }
    }

    //過長的Array直接全部加入
    for (; i < this->m_length; i++)
    {
        mergeArr.m_pNode[k++] = this->m_pNode[i];
        final_m_length++;
    }
    for (; j < arr.m_length; j++)
    {
        mergeArr.m_pNode[k++] = arr.m_pNode[j];
        final_m_length++;
    }
    mergeArr.m_length = final_m_length;

    return mergeArr;
}

//intersection_unsorted: O(n**2)
Array Array::intersection_unsorted(Array const &arr)
{
    int merge_m_size = this->m_size + arr.m_size;
    int merge_m_length = this->m_length + arr.m_length;
    int final_m_length = 0; // 用來計算最終長度

    // int i = 0; //本身index
    // int j = 0; //傳入的arr之index
    int k = 0; //回傳array之index

    Array mergeArr(merge_m_size, merge_m_length);

    for (int i = 0; i < this->m_length; i++)
    {
        for (int j = 0; j < arr.m_length; j++)
        {
            if (this->m_pNode[i] == arr.m_pNode[j])
            {
                mergeArr.m_pNode[k++] = this->m_pNode[i];
                final_m_length++;
            }
        }
    }
    mergeArr.m_length = final_m_length;
    return mergeArr;
}

//intersection_sorted: O(n)
Array Array::intersection_sorted(Array const &arr)
{
    int merge_m_size = this->m_size + arr.m_size;
    int merge_m_length = this->m_length + arr.m_length;
    int final_m_length = 0; // 用來計算最終長度

    int i = 0; //本身index
    int j = 0; //傳入的arr之index
    int k = 0; //回傳array之index

    Array mergeArr(merge_m_size, merge_m_length);

    while (i < this->m_length && j < arr.m_length)
    {
        //若兩者相同
        if (this->m_pNode[i] == arr.m_pNode[j])
        {
            //加到target Array中
            mergeArr.m_pNode[k++] = this->m_pNode[i++];
            j++;
            final_m_length++;
        }
        else if (this->m_pNode[i] < arr.m_pNode[j])
        {
            i++;
        }
        else if (arr.m_pNode[j] < this->m_pNode[i])
        {
            j++;
        }
    }

    mergeArr.m_length = final_m_length;
    return mergeArr;
}

Array Array::difference_unsorted(Array const &arr)
{
    int merge_m_size = this->m_size + arr.m_size;
    int merge_m_length = this->m_length;
    int final_m_length = 0; // 用來計算最終長度

    // int i = 0; //本身index
    // int j = 0; //傳入的arr之index
    int k = 0; //回傳array之index

    Array mergeArr(merge_m_size, merge_m_length);
    int flag = 0;

    for (int i = 0; i < this->m_length; i++)
    {
        for (int j = 0; j < arr.m_length; j++)
        {
            if (this->m_pNode[i] == arr.m_pNode[j])
            {
                flag++;
            }
        }
        if (!flag)
        {
            mergeArr.m_pNode[k++] = this->m_pNode[i];
            final_m_length++;
        }
    }
    mergeArr.m_length = final_m_length;
    return mergeArr;
}

Array Array::difference_sorted(Array const &arr)
{
    int merge_m_size = this->m_size + arr.m_size;
    int merge_m_length = this->m_length;
    int final_m_length = 0; // 用來計算最終長度

    int i = 0; //本身index
    int j = 0; //傳入的arr之index
    int k = 0; //回傳array之index

    Array mergeArr(merge_m_size, merge_m_length);

    while (i < this->m_length && j < arr.m_length)
    {
        //若兩者相同
        if (this->m_pNode[i] == arr.m_pNode[j])
        {
            //不copy
            i++;
            j++;
        }
        //若欲減去的Array的元素較大
        else if (this->m_pNode[i] < arr.m_pNode[j])
        {
            mergeArr.m_pNode[k++] = this->m_pNode[i++];
            final_m_length++;
            //j不變
        }
        //若this的Array的元素較大
        else if (arr.m_pNode[j] < this->m_pNode[i])
        {
            j++;
        }
    }

    mergeArr.m_length = final_m_length;
    return mergeArr;
}

void Array::find_missing()
{
    int diff = this->m_pNode[0] - 0;
    for (int i = 0; i < this->m_length; i++)
    {
        if (this->m_pNode[i] - i != diff)
        {
            std::cout << "find missing elem: " << diff + i << std::endl;
            std::cout << "index should be: " << i << std::endl;
            diff = this->m_pNode[i] - i;
        }
    }
}

void Array::multiple_finding()
{
    int diff = this->m_pNode[0] - 0;

    for (int i = 0; i < this->m_length; i++)
    {
        if (diff != (this->m_pNode[i] - i))
        {
            while (diff < (this->m_pNode[i] - i))
            {
                std::cout << "find missing elem: " << diff + i << std::endl;
                diff++;
            }
        }
    }
}

void Array::hashTable_finding()
{

    int mp_m_length = this->max();
    int mp_m_size = this->m_size;
    Array res(mp_m_size, mp_m_length);

    for (int i = 0; i < this->m_length; i++)
    {
        res.m_pNode[this->m_pNode[i]]++;
    }
    for (int i = 1; i < res.m_length; i++)
    {
        if (res.m_pNode[i] == 0)
        {
            std::cout << "find missing elem: " << i << std::endl;
        }
    }
}

void Array::find_duplicated() //必須sorted
{
    for (int i = 0; i < this->m_length - 1; i++)
    {
        int j = i + 1;
        // int cnt = 1;
        if (this->m_pNode[i] == this->m_pNode[i + 1])
        {

            while (this->m_pNode[j] == this->m_pNode[j + 1])
            {
                j++;
            }
            std::cout << "find_duplicated: " << this->m_pNode[i] << std::endl;
            std::cout << "duplicated_times: " << j - i << std::endl;
            i = j - 1; //i 在if中：要跟在j後面
        }
    }
}

void Array::find_duplicated_unsorted()
{

    for (int i = 0; i < this->m_length; i++)
    {
        int cnt = 1; //數到的當下那一次
        for (int j = i + 1; j < this->m_length; j++)
        {
            if (this->m_pNode[i] == this->m_pNode[j] && this->m_pNode[i] != -1)
            {
                cnt++;
                this->m_pNode[j] = -1; //數過的標誌
            }
        }
        if (cnt > 1)
        {
            std::cout << "find_duplicated: " << this->m_pNode[i] << std::endl;
            std::cout << "duplicated_times: " << cnt << std::endl;
        }
    }
}

void Array::find_duplicated_hashTable() //必須sorted
{
    int mp_m_length = this->max();
    int mp_m_size = this->m_size;
    Array res(mp_m_size, mp_m_length);
    for (int i = 0; i < res.m_length; i++)
    {
        res.m_pNode[i] = 0;
    }

    for (int i = 0; i < this->m_length; i++)
    {
        res.m_pNode[this->m_pNode[i]]++;
    }
    for (int i = 0; i <= res.m_length; i++) //因為i可能為maximum number
    {
        if (res.m_pNode[i] > 1)
        {
            std::cout << "find_duplicated: " << i << std::endl;
            std::cout << "duplicated_times: " << res.m_pNode[i] - 1 << std::endl;
        }
    }
}

Array::~Array()
{
    if (this->m_pNode != NULL)
    {
        delete[] this->m_pNode; //釋放連續記憶體
        this->m_pNode = NULL;
    }
}