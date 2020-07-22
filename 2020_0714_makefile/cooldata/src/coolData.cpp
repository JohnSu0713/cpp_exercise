#include <iostream>
#include <string>
#include "coolData.h"

coolData::coolData()
{
    std::cout << "Creat a coolData!!..." << std::endl;
    this->m_size = 1024;
    m_pNode = new int[m_size];
    this->m_length = this->m_size / 2;
};

coolData::coolData(int size)
{
    std::cout << "Creat a coolData!!..." << std::endl;
    this->m_size = size;
    m_pNode = new int[this->m_size];
    this->m_length = this->m_size / 2;
};

void coolData::show()
{
    std::cout << "Hello! My coolData!!" << std::endl;
};
void coolData::info()
{
    std::cout << "size = " << this->m_size << std::endl;
    std::cout << "Length = " << this->m_length << std::endl;
};

coolData::~coolData()
{
    if (this->m_pNode != NULL)
    {
        delete[] m_pNode;
        m_pNode = NULL;
        std::cout << "coolData has been destructed!" << std::endl;
    }
}

//Array_class
