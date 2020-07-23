#include <iostream>
#include <string>

#define PushFront 0
#define PushBack 1
#define ByIndex 2
#define IterPrint 0

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
    bool isEmpty();
    bool isValidIndex(int iIndex);

public:
    LinkedList();
    LinkedList(int iData);
    ~LinkedList();

    bool isSorted();
    void printList(int iMode = IterPrint);
    int sizeofList();
    int getSum();
    int getMax();
    int getValue(int iIndex);
    int searchByValue(int iIndex);
    int addNode(int iData, int iType = PushBack, int iIndex = 0);
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
    std::cout << "Heap空間完成釋放..." << std::endl;
    return;
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

bool LinkedList::isSorted()
{
    if (this->isEmpty())
    {
        std::cout << "List is Empty..." << std::endl;
        return false;
    }

    if (m_pHead->m_pNext == NULL)
    {
        std::cout << "Only Single elements..." << std::endl;
        return true;
    }

    ListNode *pCurr = m_pHead->m_pNext;
    ListNode *pPrev = m_pHead;

    while (pCurr->m_iData >= pPrev->m_iData && pCurr != NULL)
    {
        pPrev = pCurr;
        pCurr = pCurr->m_pNext;
    }

    if (pCurr == NULL)
    {
        return true;
    }
    return false;
}
bool LinkedList::isValidIndex(int iIndex)
{
    if (iIndex > m_iLength || iIndex < 0)
    {
        return false;
    }
    return true;
}
void LinkedList::printList(int iMode)
{
    //check validation
    if (this->isEmpty())
    {
        std::cout << "List is Empty..." << std::endl;
        return;
    }

    ListNode *pCurr = m_pHead;
    while (pCurr)
    {
        std::cout << pCurr->m_iData << " ";
        pCurr = pCurr->m_pNext;
    }
    std::cout << std::endl;
}
int LinkedList::sizeofList()
{
    return -1;
}
int LinkedList::getSum()
{
    return -1;
}
int LinkedList::getMax()
{
    return -1;
}
int LinkedList::getValue(int iIndex)
{
    return -1;
}
int LinkedList::searchByValue(int iIndex)
{
    return -1;
}
int LinkedList::addNode(int iData, int iType, int iIndex)
{
    ListNode *newNode = new ListNode(iData);

    if (iType == PushFront)
    {
        //check validation
        if (this->isEmpty())
        {
            return -1;
        }
        newNode->m_pNext = m_pHead;
        m_pHead = newNode;
        m_iLength++;
    }
    else if (iType == PushBack)
    {
        //check validation
        if (this->isEmpty())
        {
            return -1;
        }

        m_pTail->m_pNext = newNode;
        m_pTail = m_pTail->m_pNext;
        m_iLength++;
    }
    else if (iType == ByIndex)
    {
        //check validation
        if (this->isEmpty())
        {
            return -1;
        }
        ListNode *pPrev;
        ListNode *pCurr;
        pCurr = pPrev = m_pHead;

        while (iIndex > 0)
        {
            pPrev = pCurr;
            pCurr = pCurr->m_pNext;
            iIndex--;
        }
        newNode->m_pNext = pCurr;
        pCurr = newNode;
        pPrev->m_pNext = newNode;
        m_iLength++;
    }
    return 0;
}
int LinkedList::deleteNode(int iIndex)
{
    return -1;
}
int LinkedList::removeDuplicate()
{
    return -1;
}

int main(int argc, char const *argv[])
{
    LinkedList myList(10);
    myList.addNode(20);
    myList.addNode(30);
    myList.addNode(40, PushFront);
    myList.addNode(50, PushFront);
    myList.addNode(713, ByIndex, 3);
    myList.printList();
    return 0;
}
