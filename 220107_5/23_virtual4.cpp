#include <iostream>
using namespace std;


// 가상함수 : 실행 시간에 동작
// 디폴트 인자 : 컴파일 시간에 동작
//  > 가상 함수에 되도록이면 기본 인자를 사용하지 말자. 사용했다면, 오버라이딩 할 때 변경하지 말자.



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

//컴파일 타입 런타임 타입? 구분