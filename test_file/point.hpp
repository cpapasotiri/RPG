#include "double.hpp"
#include "int.hpp"

class Point{
    private:
        Double* x;
        Int* y;

    public:
        Point(Double*, Int*);
        void print();
};
