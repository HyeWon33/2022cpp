#include <iostream>
using namespace std;

// 1. 부모의 멤버 함수가 virtual 이면 자식 멤버 함수도 virtual이 된다.

class Animal{
public:
    virtual void Cry() { cout << "Animal cry" << endl;}

};
class Dog : public Animal{
public:
    // virtual void Cry(){cout << "Dog cry" << endl;} 

    // virtual은 선언과 구현을 분리할 때 선언에만 사용된다. 
    // 아래 함수가, 부모의 함수를 오버라이딩 한 것인지 아닌 것인지 확인이 어렵다.
    virtual void Cry();
    // : C++11에서는 부모로부터 오버라이딩 한 함수라는 표시를 할 수 있다.  
    // virtual void Cry() override;
    void Cry() override; //요즘 심플하게 이렇게 쓴다고 한다. 그런데 virtual보기 좋으라고 붙인거 아닌가? 빼면 똑같은거 아닌가?
};

// Dog.cpp
// virtual, static, override : 선언부에만 사용한다.
void Dog::Cry(){  //virtual void Dog::Cry() => XX오류
    cout << "Dog Cry" << endl;
}


int main(){
    Animal* p = new Dog;
    p->Cry();
}