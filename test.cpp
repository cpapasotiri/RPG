#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class SuperTest{
    private:
        int s;
    public:
        SuperTest(int);
        ~SuperTest();

        virtual void print()const=0;
        int getS();
};

SuperTest::SuperTest(int x){
    cout << "A New SuperTest has been created" << endl;
    s = x;
}

SuperTest::~SuperTest(){
    cout <<"A SuperTest to be destroyed" << endl;
}

void SuperTest::print()const{
    cout << "s = " << s << endl;
}

int SuperTest::getS(){
    return s;
}


class Test : public SuperTest{
// class Test{
    private:
        int x;
        int y;
        int z;
    public: 
        Test(int, int, int);
        ~Test();

        void print()const;
        int getX()const;
        int getY()const;
        int getZ()const;
};

Test::Test(int a, int b, int c)
: SuperTest(0){
    cout << "A New Test has been created" << endl;
    x = a;
    y = b;
    z = c;
}

Test::~Test(){
    cout <<"A Test to be destroyed" << endl;
}

void Test::print()const{
    cout << "x = " << x << " y = " << y << " z = " << z << endl;
}

int Test::getX()const{
    return x;
}

int Test::getY()const{
    return y;
}

int Test::getZ()const{
    return z;
}


int main(int argc, char* argv[]){
    Test* t1 = new Test(1, 2, 3);
    Test* t2 = new Test(4, 5, 6);
    Test* t3 = new Test(7, 8, 9);

    vector <Test*> v;
    v.push_back(t1);
    v.push_back(t2);
    v.push_back(t3);
 
    vector <Test*> :: iterator i;
    for(i = v.begin(); i != v.end(); i++){
        (*i)->print();
    }
    
    v.clear();
    delete t1;
    delete t2;
    delete t3;

    return 0;
}