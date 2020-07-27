#include <iostream>
#include <string>
#include <stdlib.h> /* srand, rand */
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
    friend class ListNode;

private:
    int m_length;   //record size of List
    ListNode *head; //use to record first node address
    ListNode *tail; //use to record first node address

    // void debuginfo()

public:
    //constrctor
    LinkedList() : m_length(0), head(NULL), tail(NULL){};

    //member funtion of ListNode
    void initByArray(const int arr[]); //尚未實現
    void printList(string mode);
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

//------------------------

//Constructor

//member funtion

void LinkedList::pushFront(int pushData)
{
    //creat new node
    ListNode *newNode = new ListNode(pushData);

    //check if new LinkedList
    if (head == NULL)
    {
        newNode->next = head;
        head = tail = newNode;
        m_length++;
        return;
    }

    //connection
    newNode->next = head;
    head = newNode;
    m_length++;
}

void LinkedList::pushBack(int pushData)
{

    //creat new node
    ListNode *newNode = new ListNode(pushData);

    //確認head是否是空的
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    tail->next = newNode;
    tail = tail->next;
    m_length++;
}

void LinkedList::printList(string mode = "i")
{
    if (head == 0) //如果first node指向NULL, 表示list沒有資料
    {
        cout << "List is empty.\n";
        return;
    }

    ListNode *pCurr = head; //用pointer *current在list中移動

    // Traversal printing
    while (pCurr)
    {
        cout << pCurr->m_data << " ";
        pCurr = pCurr->next;
    }
    cout << endl;
}

void LinkedList::info()
{
    //Edge_case
    if (head == NULL)
    {
        std::cout << "List is empty..." << std::endl;
        return;
    }
    std::cout << "Length = " << m_length << std::endl;
    std::cout << "Sum = " << this->sumValue() << std::endl;
    std::cout << "Max = " << this->maxValue() << std::endl;
    std::cout << "Head = " << head->m_data << std::endl;
    std::cout << "Tail = " << tail->m_data << std::endl;
    return;
}

int LinkedList::sumValue()
{
    //Edge_case
    if (head == NULL)
    {
        std::cout << "List is empty..." << std::endl;
        return 0;
    }

    ListNode *pCurr = head;
    int sum = 0;

    while (pCurr->next != NULL)
    {
        sum += pCurr->m_data;
        pCurr = pCurr->next;
    }
    return sum;
}

int LinkedList::maxValue()
{
    //Edge_case
    if (head == NULL)
    {
        std::cout << "List is empty..." << std::endl;
        return 0;
    }

    //creat pCurr
    ListNode *pCurr = head;
    int max = pCurr->m_data;

    //Use pCurr to iterate
    while (pCurr->next != NULL)
    {
        if (pCurr->m_data > max)
        {
            max = pCurr->m_data;
            pCurr = pCurr->next;
            continue;
        }
        pCurr = pCurr->next;
    }
    return max;
}

ListNode *LinkedList::searchByValue(int target)
{
    //Edge_case
    if (head == NULL)
    {
        std::cout << "List is empty..." << std::endl;
        return 0;
    }

    int pos = 0;
    ListNode *pCurr = head;

    while (pCurr->next != NULL)
    {
        if (pCurr->m_data == target)
        {
            std::cout << "Target Index = " << pos << std::endl;
            return pCurr;
        }
        else
        {
            pCurr = pCurr->next;
        }
        pos++;
    }

    std::cout << "Not Found..." << std::endl;
    return NULL;
}

////Imrove_method_of_search_linkedList
ListNode *LinkedList::searchByValue_trans(int target)
{
    //Edge_case
    if (head == NULL)
    {
        std::cout << "List is empty..." << std::endl;
        return 0;
    }

    //Initialization of pCurr & pPrev
    ListNode *pCurr = head;
    ListNode *pPrev = pCurr;
    int pos = 0;

    while (pCurr->next != NULL)
    {
        if (pCurr->m_data == target)
        {
            std::cout << "Find target index = " << pos << std::endl;
            pPrev->next = pCurr->next;
            pCurr->next = head->next;
            head = pCurr;
            return pCurr;
        }
        else
        {
            pPrev = pCurr;
            pCurr = pCurr->next;
            pos++;
        }
    }
    std::cout << "Not Found..." << std::endl;
    return NULL;
}

void LinkedList::insertNodeByIndex(int pos, int insertData)
{
    //Creat newNode
    ListNode *newNode = new ListNode(insertData);

    //check if need new LinkedList
    if (head == NULL)
    {
        newNode->next = head;
        head = tail = newNode;
        m_length++;
        return;
    }

    //先確認是否要插入於index = 0;
    if (pos == 0)
    {
        pushFront(insertData);
        return;
    }

    ListNode *pCurr = head;

    //Accessing target node
    for (int i = 0; i < pos - 1; i++)
    {
        pCurr = pCurr->next;
    }

    newNode->next = pCurr->next;
    pCurr->next = newNode;
    m_length++;
}

void LinkedList::insertBySorted(int data)
{
    //creat new node
    ListNode *newNode = new ListNode(data);

    //check if new LinkedList
    if (head == NULL)
    {
        head = tail = newNode;
        m_length++;
        return;
    }
    ListNode *pCurr = head;
    ListNode *pPrev = NULL;

    while (pCurr != NULL && pCurr->m_data < data)
    {
        pPrev = pCurr;
        pCurr = pCurr->next;
    }

    //在while 結束才確認是否PushFront
    if (pCurr == head)
    {
        pushFront(data);
        return;
    }
    newNode->next = pPrev->next;
    pPrev->next = newNode;
}

// int main(int argc, char const *argv[])
// {

//     LinkedList myList;
//     int arr[] = {5, 3, 20, 13, 16, 1, 15, 11, 7};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     for (int i = n - 1; i >= 0; i--)
//     {
//         myList.pushFront(arr[i]);
//     }
//     myList.printList();
//     std::cout << "================" << std::endl;

//     myList.searchByValue(16);
//     myList.printList();
//     std::cout << "================" << std::endl;

//     myList.insertNodeByIndex(4, 99);
//     myList.printList();
//     std::cout << "================" << std::endl;

//     LinkedList myList_02;
//     int arr02[] = {5, 3, 20, 13, 16, 1, 15, 11, 7};

//     for (int i = n - 1; i >= 0; i--)
//     {
//         myList_02.insertBySorted(arr02[i]);
//     }
//     myList_02.printList();
//     std::cout << "================" << std::endl;

//     myList_02.info();
//     return 0;
// }
