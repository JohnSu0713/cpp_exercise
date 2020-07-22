#include <iostream>
#include <string>
#include <stdlib.h> /* srand, rand */
#include <time.h>   /* time */
#include "LinkedList.h"
using namespace std;
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

void LinkedList::printList()
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