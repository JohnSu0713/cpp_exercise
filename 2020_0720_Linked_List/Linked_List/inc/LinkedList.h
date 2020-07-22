#ifndef __LINKEDLIST_
#define __LINKEDLIST_

#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

class ListNode
{
    friend class LinkedList;

private:
    int m_data;
    ListNode *next; //Node don't have "first" Node

public:
    //constructor of ListNode
    ListNode() : m_data(0), next(NULL){};
    ListNode(int data) : m_data(data), next(NULL){};
    ~ListNode(){};
};

//class of entire Linked List
class LinkedList
{
private:
    int m_length;   //record size of List
    ListNode *head; //use to record first node address
    ListNode *tail; //use to record first node address
public:
    //constrctor
    LinkedList() : m_length(0), head(NULL), tail(NULL){};

    //member funtion of ListNode
    void initByArray(const int arr[]); //尚未實現
    void printList();
    void pushFront(int pushData);
    void pushBack(int pushData);
    void info();
    int sumValue();
    int maxValue();
    ListNode *searchByValue(int target);
    ListNode *searchByValue_trans(int target); //這是我想要加入searchByValue的一個模式
    void insertNodeByIndex(int pos, int data);
    void insertBySorted(int data);

    ~LinkedList(){};
};

#endif //
