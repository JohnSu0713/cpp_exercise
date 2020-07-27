#include <iostream>
#include <string>
#include <vector>
#include <iterator>

//ADD_iType
#define PushFront 0
#define PushBack 1
#define ByIndex 2
//REVERSE_iTYPE
#define ReverseByElement 0
#define ReverseByLink 1

using namespace std;

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
    int getSum();
    int getMax();
    int getValue(int iIndex);
    int addNode(int iData, int iType = PushBack, int iIndex = 0);
    int deleteNode(int iIndex);
    int removeDuplicate();
    int reverse(int REVERSE_iTYPE);
    vector<int> searchByValue(int iData);
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
    m_iLength++;
}
LinkedList::~LinkedList() //Delete Heap
{
    if (isEmpty())
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
    std::cout << "Heap空間完成釋放。" << std::endl;
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
    //check Empty
    if (isEmpty())
    {
        std::cout << "List is Empty..." << std::endl;
        return false;
    }

    //check if only single element
    if (m_pHead->m_pNext == NULL)
    {
        std::cout << "Only Single elements..." << std::endl;
        return true;
    }

    ListNode *pCurr = m_pHead->m_pNext;
    ListNode *pPrev = m_pHead;

    //moving condition
    while (pCurr->m_iData >= pPrev->m_iData && pCurr->m_pNext != NULL)
    {
        pPrev = pCurr;
        pCurr = pCurr->m_pNext;
    }

    //if reach end of List: sorted
    if (pCurr->m_pNext == NULL)
    {
        std::cout << "List is sorted." << std::endl;
        return true;
    }
    std::cout << "List is unsorted!" << std::endl;
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

void LinkedList::printList()
{
    //check validation
    if (isEmpty())
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

void LinkedList::showInfo()
{
    std::cout << "====List_info====" << std::endl;
    std::cout << "size = " << this->sizeofList() << std::endl;
    std::cout << "sum = " << this->getSum() << std::endl;
    std::cout << "max = " << this->getMax() << std::endl;

    std::cout << "====List_info====" << std::endl;
}

int LinkedList::sizeofList()
{
    //check validation
    if (isEmpty())
    {
        std::cout << "List is Empty..." << std::endl;
        return 0;
    }
    ListNode *pCurr = m_pHead;
    int cnt = 1;

    while (pCurr->m_pNext != NULL)
    {
        pCurr = pCurr->m_pNext;
        cnt++;
    }
    return cnt;
}
int LinkedList::getSum()
{
    //check validation
    if (isEmpty())
    {
        std::cout << "List is Empty..." << std::endl;
        return 0;
    }
    //getSum
    ListNode *pCurr = m_pHead;
    int sum = 0;
    while (pCurr != NULL)
    {
        sum += pCurr->m_iData;
        pCurr = pCurr->m_pNext;
    }
    return sum;
}
int LinkedList::getMax()
{
    //check validation
    if (isEmpty())
    {
        std::cout << "List is Empty..." << std::endl;
        return 0;
    }
    //getMax
    ListNode *pCurr = m_pHead;
    int max = m_pHead->m_iData;
    while (pCurr->m_pNext != NULL)
    {
        if (pCurr->m_iData > max)
            max = pCurr->m_iData;
        pCurr = pCurr->m_pNext;
    }
    return max;
}
int LinkedList::getValue(int iIndex)
{
    //check validation
    if (isEmpty())
    {
        std::cout << "List is Empty..." << std::endl;
        return -1;
    }
    if (!(this->isValidIndex(iIndex)))
    {
        std::cout << "Input wrong index." << std::endl;
        return -1;
    }

    //get value from index
    ListNode *pCurr = m_pHead;
    for (size_t i = 0; i < iIndex; i++)
    {
        pCurr = pCurr->m_pNext;
    }
    std::cout << "get_value = " << pCurr->m_iData << std::endl;
    return pCurr->m_iData;
}
vector<int> LinkedList::searchByValue(int iData)
{
    vector<int> mySearch;

    //check validation
    if (isEmpty())
    {
        mySearch.push_back(-1);
        std::cout << "List is Empty..." << std::endl;
        return mySearch;
    }

    //searching
    int pos = 0;
    ListNode *pCurr = m_pHead;
    while (pCurr->m_pNext != NULL)
    {

        if (pCurr->m_iData == iData)
        {
            mySearch.push_back(pos);
        }
        pos++;
        pCurr = pCurr->m_pNext;
    }

    std::cout << "searching index = " << std::flush;
    for (vector<int>::iterator it = mySearch.begin(); it != mySearch.end(); it++)
    {
        std::cout << (*it) << " " << std::flush;
    }
    std::cout << std::endl;
    return mySearch;
}
int LinkedList::addNode(int iData, int ADD_iType, int iIndex)
{
    ListNode *newNode = new ListNode(iData);

    if (ADD_iType == PushFront)
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
    else if (ADD_iType == PushBack)
    {
        //check validation
        if (isEmpty())
        {
            return -1;
        }

        m_pTail->m_pNext = newNode;
        m_pTail = m_pTail->m_pNext;
        m_iLength++;
    }
    else if (ADD_iType == ByIndex)
    {
        //check validation
        if (isEmpty())
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
    //check validation
    if (this->isEmpty())
    {
        std::cout << "List is Empty..." << std::endl;
        return -1;
    }
    if (!(this->isValidIndex(iIndex)))
    {
        std::cout << "Input wrong index." << std::endl;
        return -1;
    }

    if (iIndex == 0)
    {
        ListNode *pTmp = m_pHead;
        m_pHead = m_pHead->m_pNext;
        int tmp = pTmp->m_iData;
        delete pTmp;
        m_iLength--;
        //std::cout << "Original Head has been delete." << std::endl;
        return tmp;
    }

    else if (iIndex == m_iLength - 1)
    {
        ListNode *pNewTail = m_pHead;
        ListNode *pTmp = m_pTail;
        while (pNewTail->m_pNext != m_pTail)
        {
            pNewTail = pNewTail->m_pNext;
        }

        m_pTail = pNewTail;
        pNewTail->m_pNext = NULL;
        int tmp = pTmp->m_iData;
        std::cout << tmp << std::endl;
        delete pTmp;

        //std::cout << "Tail has been deleted." << std::endl;
        m_iLength--;
        return tmp;
    }
    else
    {
        ListNode *pCurr = m_pHead;
        ListNode *pPrev = NULL;
        for (size_t i = 0; i < iIndex; i++)
        {
            pPrev = pCurr;
            pCurr = pCurr->m_pNext;
        }
        pPrev->m_pNext = pCurr->m_pNext;
        int tmp = pCurr->m_iData;
        delete pCurr;
        m_iLength--;
        return tmp;
    }
}
int LinkedList::removeDuplicate()
{
    //check validation
    if (isEmpty())
    {
        std::cout << "List is Empty..." << std::endl;
        return -1;
    }

    // check is sorted List
    if (isSorted() == false)
    {
        std::cout << "This function need input sorted List!" << std::endl;
        return -1;
    }

    ListNode *pCurr = m_pHead->m_pNext;
    ListNode *pPrev = m_pHead;

    while (pCurr != NULL)
    {
        if (pCurr->m_iData != pPrev->m_iData)
        {
            pPrev = pCurr;
            pCurr = pCurr->m_pNext;
        }
        else
        {
            pPrev->m_pNext = pCurr->m_pNext;
            delete pCurr;
            m_iLength--;
            pCurr = pPrev->m_pNext;
        }
    }
    this->printList();
    return 0; //還沒想到
}

int LinkedList::reverse(int REVERSE_iTYPE)
{
    //check validation
    if (this->isEmpty())
    {
        std::cout << "List is Empty..." << std::endl;
        return -1;
    }

    ListNode *pFirst = m_pHead;
    ListNode *pMid = NULL;
    ListNode *pLast = NULL;

    if (REVERSE_iTYPE == ReverseByElement)
    {
        int n = m_iLength;
        vector<int> myElement;
        int i = 0;

        ListNode *pCurr = m_pHead;
        while (pCurr != NULL)
        {
            myElement.push_back(pCurr->m_iData);
            pCurr = pCurr->m_pNext;
        }

        //把pCurr指回頭部
        pCurr = m_pHead;
        vector<int>::iterator it;
        it = myElement.end() - 1;

        while (pCurr != NULL)
        {
            pCurr->m_iData = (*it);
            it--;
            pCurr = pCurr->m_pNext;
        }
        return 0;
    }
    else if (REVERSE_iTYPE == ReverseByLink)
    {
        std::cout << m_pHead->m_iData << std::endl;
        printList();

        while (pFirst != NULL)
        {
            //sliding three pointer 先移動三個指標
            pLast = pMid;
            pMid = pFirst;
            pFirst = pFirst->m_pNext;

            //把中間的 m_pNext 指向pLast
            pMid->m_pNext = pLast;
        }
        //要把m_pHead 指派給最末位
        m_pHead = pMid;
    }
    printList();
    return 0;
}

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
