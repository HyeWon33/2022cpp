#include <iostream>
using namespace std;

class A{
    int a;
public:
    virtual void foo(){cout << "foo" << endl;} // 1
};

//A, B 상속 관계 아니다.

class B{
    int b;
public:
    virtual void goo() {cout << "goo" << endl;} //2
};

int main(){
    A aaa;
    B* p = reinterpret_cast<B*>(&aaa);

    p->goo(); //2 -> virtual -> p가 가르키는 가상함수테이블 타고 들어가서 첫 번째 위치에 있는 함수 호출 -> 1
}