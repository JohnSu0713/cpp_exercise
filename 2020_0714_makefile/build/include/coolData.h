#ifndef __COOLDATA_H
#define __COOLDATA_H

#include <iostream>
#include <string>

class coolData
{
private:
    /* data */
public:
    coolData();
    coolData(int size);

    int m_size;
    int *m_pNode;
    int m_length;

    void show();
    void info();

    ~coolData();
};

#endif // __COOLDATA_H
