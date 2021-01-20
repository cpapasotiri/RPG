#include "point.hpp"
#include <iostream>

using namespace std;

Point::Point(Double* d, Int* i){
    x = d;
    y = i;
}

void Point::print(){
    cout << "Point:" << endl;
    x->print();
    y->print();
    cout << endl;
}
