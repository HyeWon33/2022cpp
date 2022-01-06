#include <iostream>
using namespace std;

//상속과 생성자 / 소멸자

#if 0
class Base{
public:
    Base(){cout << "Base()" << endl;}
    ~Base(){ cout << "~Base()" << endl;}
};

class Derived : public Base{
public:
    Derived(){cout << "Derived()" << endl;}
    ~Derived(){cout << "~Derived()" << endl;}
}

//코드 결과
//Base()
//Derived()
//~Derived()
//Base()
#endif


class Base{
public:
    Base(){cout << "Base()" << endl;}
    Base(int a) { cout << "Base(int)" << endl;}

    ~Base(){ cout << "~Base()" << endl;}
};

class Derived : public Base{
public:
    Derived() : Base() {cout << "Derived()" << endl;}
    //기본 생성자 Base()
    //원리 : 컴파일러는 자식 클래스의 생성자에 초기화 리스트를 통해 부모의 기본 생성자를 호출하는 코드 삽입한다.
    // > 부모가 기본 생성자를 제공하지 않을 경우, 명시적으로 부모의 생성자를 호출해야 한다.

    Derived() : Base(42) {cout << "Derived()" << endl;}
    //Base(int)

    ~Derived() {
        cout << "~Derived()" << endl;
        //~Base()
        //컴파일러가 자동으로 삽입해서 호출해준다.

    }
};

int main(){
    Derived d;

}