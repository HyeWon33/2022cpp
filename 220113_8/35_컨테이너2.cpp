//범용적으로 만들기

#include <iostream>
using namespace std;

// 1. Object* 기반 컨테이너
//  - 모든 클래스는 Object의 자식이어야 한다.

class Object{
public:
    virtual ~Object(){}
};


//오브젝트 포인터는 모든 클래스 객체 참조 가능

struct Node{
    Object* data;
    Node* next;

    Node(Object* a, Node* n) : data(a), next(n){}
};

class Slist{
    Node* head;

public:
    Slist() : head(nullptr){}

    void push_front(Object* a){ head = new Node(a, head); }

    Object* front(){ return head->data;}
};

// 프로그램 내의 모든 클래스는 반드시 Object의 자식 클래스 이어야 한다.
//  => Java, C#에서는 자동으로 Object의 자식으로 생성된다.
class Dialog : public Object{
};
class Rect : public Object{
};

// 문제점
//  1) 컨테이너에 일반적으로 하나의 타입을 지정하는 것이 좋다.
//   => 다른 종류의 타입을 넣어도 컴파일 오류가 발생하지 않는다.
//     : 타입 안정성이 떨어진다
//  2) 객체가 아닌 표준 타입(primitive type, built-in type)은 저장할 수 없다.
//    int, char, double, float, long ...
//   => 래퍼 클래스가 필요하다.
//    : Java, c#에서 제공하는 개념
//  3) 데이터를 꺼내올 때마다 다운 캐스팅이 필요하다.

// 장점
//  : 템플릿 기반이 아니기 때문에 메모리 사용량이 효율적이다.

class Integer : public Object{ //래퍼클래스
    int value;
public:
    Integer(int n) : value(n) {}

    int GetValue() const { return value;}
};

int main(){
    Slist s;

    s.push_front(new Dialog); //문제점 1
    s.push_front(new Rect);   //문제점 1

    s.push_front(new Integer(42));

    // Integer* p = s.push_front(); // 반드시 다운 캐스팅이 필요하다.
    // ↓↓↓
    Integer* p = dynamic_cast<Integer*>(s.front());
    if (p) {cout << p->GetValue() << endl;}   
}