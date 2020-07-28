#include <iostream>
#include <string>
#include "LinkedList.h"

int main(int argc, char const *argv[])
{
    LinkedList myList(10);
    myList.addNode(20);
    myList.addNode(30);
    myList.addNode(40);
    myList.addNode(40);
    myList.addNode(40);
    myList.addNode(50);
    myList.addNode(60);
    myList.addNode(60);
    myList.addNode(60);
    myList.printList();

    myList.removeDuplicate();
    myList.reverse(ReverseByLink);

    return 0;
}
