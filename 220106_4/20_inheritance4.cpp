#include <iostream>
using namespace std;

#if 0 //기본
class Animal{
public:
    Animal(){}

};

class Dog : public Animal{
public:
    Dog(){}
};

int main(){
    Animal a;
    Dog d;
}
#endif

//dog 객체 생성은 가능 animal의 객체생성은 불가능 그냥 관리용으로 만들고 싶다.

class Animal{
// public
protected:
    Animal(){}

};

class Dog : public Animal{
public:
    // Dog(){}
    Dog() : Animal(){}
};

int main(){
    // Animal a; //error 외부에서 protected 생성자를 접근할 수 없다.
    Dog d; //ok
            //Dog의 생성자를 먼저 호출하고, Dog의 생성자 안에서 Animal의 생성자를 호출한다.
            //파생 클래스에서는 기반 클래스의 protected멤버에 접근이 가능한다.

            //protected 생성자의 의도
            // "자신 타입의 객체는 생성할 수 없지만, 파생 클래스 타입의 객체는 생성할 수 있다."
}