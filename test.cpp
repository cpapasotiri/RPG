// vector assignment -> i will use it to grid->market->items vector
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class Point{
    private:
        int x;
        int y;

    public:
        Point(int a, int b){
            cout << "Constructor" << endl;
            x = a;
            y = b;
        }

        ~Point(){
            cout << "Destructor" << endl;
        }

        int getX()const{
            return x;
        }

        int getY()const{
            return y;
        }
};


int main (int argc, char* argv[]){
    // grid example with integers
    int arr[8][8];
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            arr[i][j] = i*j;
        }
    }

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            cout << "arr[" << i << "][" << j << "]" << " = " << arr[i][j] << endl;
        }
    }
    // int row = 2;
    // int col = 2;
    // Point** point = new Point[row];
    // for(int i = 0; i < row; i++){
        // point[i][j].
    // }




    // v1 = v2;
    // vector<int> foo;
    // foo.push_back(1);
    // foo.push_back(2);
    // foo.push_back(3);
    // foo.push_back(4);
    // foo.push_back(5);
    // vector<int> bar;


    // bar = foo;
    // foo = vector<int>();        // this line make foo vector empty

    // cout << "Size of foo: " << int(foo.size()) << endl;
    // cout << "Size of bar: " << int(bar.size()) << endl;

    // input 1 int
    // cout << "Give me an integer number" << endl;
    // int x = 0;
    // cin >> x;
    // cout << "You gave x = " << x << endl;

    // /// input many ints
    // int x = -1;
    // cout << "Give me an integer number" << endl;
    // cin >> x;
    // while(x > 0){
    //     cout << "LOOP: Give me an integer number" << endl;
    //     cin >> x;
    // }

    // input string
    // cout << "Give me a string: " << endl;
    // string s = " ";
    // cin >> s;
    // cout << "You gave me:" << s << endl;

    // input many strings
    // string s = " ";
    // cout << "Give me a string: " << endl;
    // cin >> s;
    // while(s.compare("exit") != 0){
    //     cout << "You gave me:" << s << endl;
    //     if(s.compare("buy") != 0 && s.compare("sell") != 0){
    //         cout << "Wrong input! Please give me buy/sell/exit" << endl;
    //     }
    //     cout << "Give me a string: " << endl;
    //     cin >> s;
    // }

    return 0;
}


// int index = 0;
    // vector <Hero*> :: iterator h;
    // for(h = items.begin(); h != items.end(); h++){
        // index++;
        // cout << "Press " << item << " to select: ";
        // (*h)->print();
    // }
    // vector <Monster*> :: iterator m;
    // for(m = items.begin(); m != items.end(); m++){
        // index++;
        // cout << "Press " << item << " to select: ";
        // (*m)->print();
    // }