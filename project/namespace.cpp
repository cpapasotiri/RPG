// File namespace.cpp
#include <iostream>
#include "namespace.h"
using namespace std;
//int Example::myInt = 8;
void Example::printValues()
{
cout << "Printing from printValues" << endl;
cout << myInt << endl;
cout << E << endl;
}
