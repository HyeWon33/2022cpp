#include <iostream>
using namespace std;

#if 0
class Car{
public:
    ~Car() {cout << "Car 객체 파괴" << endl;}
    void Go() { cout << "Car go" << endl;;}
};

int main(){
    Car* p = new Car;
    p->Go();

    delete p;
}
#endif

//---------------------------------


class Car{
public:
    ~Car() {cout << "Car 객체 파괴" << endl;}
    void Go() { cout << "Car go" << endl;;}
};

// 스마트 포인터 : 임의의 객체가 다른 클래스의 포인터 역할을 하는 것
// 객체
//   생성자, 소멸자, 멤버 함수
//  => Proxy Pattern 프록시 패턴
//    : 대리자 패턴
//   장점 - 진짜 포인터가 아니라, 객체이다.
//          생성/소멸/대입/복사 등의 모든 과정에 대한 제어가 가능하다.
//          대표적인 활용이 소멸자에서의 자동 삭제 기능이다.

#if 0
class Ptr{
    Car* obj;
public:
    Ptr(Car* p = nullptr) : obj(p){}
    ~Ptr() {delete obj;}

    Car* operator->() { return obj; }
    Car& operator*() {return *obj;}
};

int main(){
    Ptr p = new  Car;
    
    p->Go(); //이렇게 써야 하는데 안된다.(Ptr 클래스에서 안 만들었을 때) -> 연산자 오버헤드 / 스마트 포인터를 진짜 포인터 처럼 사용 가능.
    // Car* operator->() {}
    (*p).Go();
    // Car& operator*() {}
}
#endif

//↓↓

template <typename T>
class Ptr{
    T* obj;
public:
    Ptr(T* p = nullptr) : obj(p){}
    ~Ptr() {delete obj;}

    T* operator->() { return obj; }
    T& operator*() {return *obj;}
};

int main(){
    Ptr<Car> p = new  Car;
    
    p->Go(); //이렇게 써야 하는데 안된다.(Ptr 클래스에서 안 만들었을 때) -> 연산자 오버헤드 / 스마트 포인터를 진짜 포인터 처럼 사용 가능.
    // Car* operator->() {}
    (*p).Go();
    // Car& operator*() {}
}



#if 0
//누가 질문한거 배열사용할 때 배열말고 컨테이너 리스트 벡터 이런거 쓴다...
#include <memory>
// C++이 제공하는 스마트 포인터.
// 1. unique_ptr<>
// 2. shared_ptr<>

template <typename T>
class Ptr{
    T* obj;
public:
    Ptr(T* p = nullptr) : obj(p){}
    ~Ptr() {delete obj;}

    T* operator->() { return obj; }
    T& operator*() {return *obj;}
};

int main(){
    std::unique_ptr<Car> p(new Car);
    std::shared_ptr<Car> p(new Car);

    p->Go();
    (*p).Go();
}
#endif