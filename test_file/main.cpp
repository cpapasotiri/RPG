#include "point.hpp"
#include "int.hpp"
#include "double.hpp"

int main(int argc, char* argv[]){ 
    Double* di = new Double(1, 1);
    Double* dj = new Double(2, 2);
    Int* ii = new Int(1, 1, di);
    Int* ij = new Int(2, 2, dj);
    // di->getInt(ii);
    // di->getInt(ij);
    // dj->getInt(ii);
    // dj->getInt(ij);

    Point* p1 = new Point(di, ii);
    Point* p2 = new Point(dj, ij);
    p1->print();
    p2->print();
    
    return 0;
}