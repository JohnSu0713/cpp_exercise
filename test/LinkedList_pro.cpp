#include <iostream>
#include <string>

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

    void debugInfo();

public:
    LinkedList();
    LinkedList(int iData);
    ~LinkedList();

    bool isEmpty();
    bool isSorted();
    void printList(int iMode);
    int sizeofList();
    int getSum();
    int getMax();
    int getValue(int iIndex);
    int searchByValue(int iIndex);
    int addNode(int iData, int iType);
    int deleteNode(int iIndex);
    int removeDuplicate();
};

//constructor and destructor
ListNode::ListNode() : m_iData(0), m_pNext(NULL){};
ListNode::ListNode(int iData) : m_iData(iData), m_pNext(NULL){};
LinkedList::LinkedList() : m_pHead(NULL), m_pTail(NULL), m_iLength(0){};
LinkedList::LinkedList(int iData)
{
    ListNode *firstNode = new ListNode(iData);
    m_pHead = firstNode;
    m_pTail = firstNode;
}

LinkedList::~LinkedList() //Delete Heap
{
    if (this->isEmpty())
    {
        m_pHead = NULL;
        m_pTail = NULL;
        return;
    }

    while (m_pHead != NULL)
    {
        ListNode *pTmp = m_pHead;
        m_pHead = m_pHead->m_pNext;
        delete pTmp;
    }
    std::cout << "Heap空間完成釋放.." << std::endl;
}

//Method
bool LinkedList::isEmpty()
{
    if (m_pHead == NULL)
    {
        return true;
    }
    return false;
}

bool isSorted()
{

    return false;
}
void printList(int iMode)
{
    return;
}
int sizeofList()
{
    return -1;
}
int getSum()
{
    return -1;
}
int getMax()
{
    return -1;
}
int getValue(int iIndex)
{
    return -1;
}
int searchByValue(int iIndex)
{
    return -1;
}
int addNode(int iData, int iType)
{
    return -1;
}
int deleteNode(int iIndex)
{
    return -1;
}
int removeDuplicate()
{
    return -1;
}



int main(int argc, char const *argv[])
{

    return 0;
}
