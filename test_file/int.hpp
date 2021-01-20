#ifndef __INT_HPP__
#define __INT_HPP__

#include "double.hpp"

class Int{
    private:
        int x;
        int y;
        Double* dd;
    public:
        Int(int, int, Double*);
        void print();
};

#endif