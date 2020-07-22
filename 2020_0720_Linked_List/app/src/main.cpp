#include <iostream>
#include <string>
#include "LinkedList.h"

int main(int argc, char const *argv[])
{

    LinkedList myList;
    int arr[] = {5, 3, 20, 13, 16, 1, 15, 11, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = n - 1; i >= 0; i--)
    {
        myList.pushFront(arr[i]);
    }
    myList.printList();
    std::cout << "================" << std::endl;

    myList.searchByValue(16);
    myList.printList();
    std::cout << "================" << std::endl;

    myList.insertNodeByIndex(4, 99);
    myList.printList();
    std::cout << "================" << std::endl;

    LinkedList myList_02;
    int arr02[] = {5, 3, 20, 13, 16, 1, 15, 11, 7};

    for (int i = n - 1; i >= 0; i--)
    {
        myList_02.insertBySorted(arr02[i]);
    }
    myList_02.printList();
    std::cout << "================" << std::endl;

    myList_02.info();
    return 0;
}
