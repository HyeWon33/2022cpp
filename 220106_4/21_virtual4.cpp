#include <iostream>
using namespace std;

//함수 오버라이딩(중요한 문법)

class Animal{
public: 
    virtual void Cry(){ cout << "Animal cry" << endl;} //1번 <-void Cry(){ cout << "Animal cry" << endl;} 
};

class Dog : public Animal {
public:
    // 기반 클래스의 멤버 함수를 자식 클래스에서 다시 재정의할 수 있다.
    // => 함수 오버라이딩 (오버로딩과 다르다.) 
    //함수 오버라이딩은 부모가 제공하는 함수와 동일한 이름으로 자식이 정의 하는 것.
    virtual void Cry() { cout << "Dog cry" << endl;} //2번 <- void Cry() { cout << "Dog cry" << endl;} 
    // 자식이 재정의하는 부모의 멤버 함수는 반드시 가상 함수 이어야 한다.
};

//c++에서는 함수 바인딩이라는 개념 이해하는 것이 중요
//C++ 함수 바인딩
// - 어떤 함수를 호출할 지 결정하는 것

// p -> Cry()

//  * Animal::Cry()
// 정적 바인딩
// - 컴파일러 p의 타입(Animal*)을 보고 Animal의 함수를 호출하도록 기계어를 생성한다.

//  * Dog::Cry()
// 동적 바인딩
// - 컴파일러가 실행 시간에 p가 어떤 타입인지 조사해서, 해당 타입의 함수를 호출하도록 하는 기계어를 생성한다.
// - 실행 시간에 결정되는 p의 타입에 따라 호출되는 함수가 달라진다.

//정적 바인딩이 빠르다. 근데 이성적으로 생각하면 동적 바인딩이 합리적이다....
//정적 바인딩과 동적 바인딩으 개념 이해 중요 

//정적 바인딩을 동적 바인딩으로 바꾸는 키워드 : virtual
//업 캐스팅 기반으로 특정한 함수 호출하면 이것이 실제 함수 호출 키워드


int main() {
    Animal a;
    Dog d;

    a.Cry(); //Animal cry 1
    d.Cry(); //Dog cry 2

    //Upcasting
    Animal* p = &d;
    p->Cry() //1?2? => 2
}

//부모꺼만 virtual써도 괜찮은데 자식도 써주자는 약속