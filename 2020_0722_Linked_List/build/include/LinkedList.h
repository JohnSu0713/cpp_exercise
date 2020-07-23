#ifndef __LINKEDLIST_
#define __LINKEDLIST_

#include <iostream>

class ListNode
{
    friend class LinkedList;

private:
    int m_data;
    ListNode *next; //Node don't have "first" Node

public:
    //constructor of ListNode
    ListNode();
    ListNode(int data);

    ~ListNode();
};

//class of entire Linked List
class LinkedList
{
private:
    int m_length;   //record size of List
    ListNode *head; //use to record first node address
public:
    //constrctor
    LinkedList();

    //member funtion of ListNode
    void printList();
    void pushFront(int pushData);
    void pushBack(int pushData);

    ~LinkedList() {}
};

#endif //
