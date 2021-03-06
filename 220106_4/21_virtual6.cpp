#include <iostream>
using namespace std;

#if 0
class Test{
public:
    Test() { cout << "자원 획득" << endl; }
    ~Test() {cout << "자원 반납" << endl;}
};

int main(){
    // Test t;
    Test *t = new Test;
    delete t;
}
#endif

#if 0

// 가상 함수를 한 개라도 가지고 있는 클래스는 반드시 소멸자도 가상 소멸자 이어야 한다. (중요하다잉)

class Base{
public:
    Base(){cout << "Base()" << endl;}
    virtual ~Base(){cout << "~Base()" << endl;} // <- ~Base(){cout << "~Base()" << endl;}
};

class Derived : public Base{
public:
    Derived() {cout << "Derived()" << endl;}
    virtual ~Derived() {cout << "~Derived()" << endl;} // <- ~Derived() {cout << "~Derived()" << endl;}
};

int main(){
    //Derived d;

    Base* p = new Derived; //이 경우 결과가 자식의 소멸자 제대로 호출되지 않았다. 정적 바인딩이라서
    delete p; //소멸자 호출 시점
}
#endif

//부모의 소멸자가 virtual이여야 한다?! 글면 자식도 가상 소멸자가 되징

// 소멸자도 함수이다.
// 일반적인 소멸자는 정적 바인딩 기반으로 동작한다.
// 업캐스팅을 기반으로 코드를 작성할 경우, 반드시 소멸자가 가상소멸자이어야한다.
