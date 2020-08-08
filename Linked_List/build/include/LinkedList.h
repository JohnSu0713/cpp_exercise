#ifndef __LINKEDLIST_
#define __LINKEDLIST_

//ADD_iType
#define PushFront 0
#define PushBack 1
#define ByIndex 2

//REVERSE_iTYPE
#define ReverseByElement 0
#define ReverseByLink 1
#include <vector>

class LinkedList;
class ListNode
{
    friend class LinkedList;

private:
    int m_iData;
    ListNode *m_pNext;

public:
    ListNode(/* args */);
    ListNode(int iData);
    ~ListNode(){};
};

class LinkedList
{
    friend class ListNode;

private:
    int m_iLength;
    ListNode *m_pHead;
    ListNode *m_pTail;

    bool isEmpty();
    bool isValidIndex(int iIndex);

public:
    LinkedList();
    LinkedList(int iData);
    ~LinkedList();

    bool isSorted();
    void printList();
    void showInfo();
    int sizeofList();
    int getSum() const; //可以加const
    int getMax();
    int getValue(int iIndex);
    int addNode(int iData, int iType = PushBack, int iIndex = 0);
    int deleteNode(int iIndex);
    int removeDuplicate();
    int reverse(int REVERSE_iTYPE);
    std::vector<int> searchByValue(int iData); //
    //int getSearchResult(vector<int>* DataVector)
};

#endif //
