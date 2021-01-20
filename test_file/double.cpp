#include "double.hpp"
#include <iostream>

using namespace std;

Double::Double(double i, double j){
    x = i;
    y = j;
}

void Double::print(){
    cout << "Double x = " << x << ", y = " << y << endl;
}

// Int* Double::getInt(Int* i){
//     i->print();
//     return i;
// }