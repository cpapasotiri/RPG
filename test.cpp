// vector assignment -> i will use it to grid->market->items vector
#include <iostream>
#include <vector>
using namespace std;

int main (int argc, char* argv[]){
    vector<int> foo;
    foo.push_back(1);
    foo.push_back(2);
    foo.push_back(3);
    foo.push_back(4);
    foo.push_back(5);
    vector<int> bar;


    bar = foo;
    foo = vector<int>();        // this line make foo vector empty

    cout << "Size of foo: " << int(foo.size()) << '\n';
    cout << "Size of bar: " << int(bar.size()) << '\n';
    return 0;
}