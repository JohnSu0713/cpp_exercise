#include <iostream>
#include <string>
#include "coolArray.h"
#include "coolData.h"

int main(int argc, char const *argv[])
{
    coolData my_data;
    my_data.show();
    my_data.info();

    Array myArr;
    cout << "Array average = " << myArr.avg() << endl;
    myArr.info();

    return 0;
}
