#include <iostream>
using namespace std;


class Animal{
public:
    int age;
};

class Dog : public Animal{
public:
    int color;
};

class Cat : public Animal{};

int main(){
    Animal* p1 = new Dog;

    Dog d;
    Animal* p2 = &d;

    Dog* pDog = p1;
    //부모의 포인터 타입을 자식의 포인터 타입으로의 암묵적 변환은 허용되지 않는다.
    // => 명시적인 캐스팅이 필요하다.

    Dog* pDog = static_cast<Dog*>(p1);
}