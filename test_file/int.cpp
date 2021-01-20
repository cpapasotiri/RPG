#include "int.hpp"
#include <iostream>

using namespace std;

Int::Int(int i, int j, Double* d){
    x = i;
    y = j;
    dd = d;
}

void Int::print(){
    cout << "Int x = " << x << ", y = " << y << endl;
    dd->print();
    cout << "   -----   " << endl;
}
