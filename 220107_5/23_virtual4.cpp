#include <iostream>
using namespace std;


//A, B 상속 관계
class A{
public:
    virtual void foo(int a = 10) {
        cout << "A : " << a << endl;
    }
};

class B : public A{
public:
    void foo(int a = 20) override{
        cout << "B : " << a << endl;
    }
};

int main(){
    A* p = new B;
    p->foo(); // B : 1o

}