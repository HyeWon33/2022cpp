#include <iostream>
using namespace std;

class Point{
private:
    int x;
    int y;

public:
    //this : 멤버 함수를 호출한 객체의 주소가 전달된다.
    // >  객체 주속값
    void set(int a, int b){ //컴파일러는 set(Point *this, int a, int b){this->x = a; this->y = b;} 이렇게 만든다.
        x = a;              //void set(Point* const this, int a, int b) //this 다른 값을 못바꾸는 상수포인터 된다.
        y = b;              //  this->x = a;
    }                       //  this->y = b;

    void foo() { // void foo (Point* const this)
        cout << this << endl;
    } 

    //객체가 생성되지 않아도 호출될 수 있다.
    // > 멤버 변수와 멤버 함수를 사용할 수 없다.
    // - this가 전달되지 않습니다.
    static void goo(){} //goo 는 thish가 전달될 필요 없다.

    static int add(int a, int b){ return a + b;}

    int hoo(int a, int b){ return a + b;}
    //hoo의 타입은 int(int, int)?? => X
    //컴파일러 : int hoo(Point* this, int a, int b){}
    //멤버함수에 가르키는 함수 포인터는 완전히 다르게 생각해야 한다.

    //객체가 각각 멤버함수 갖고있는거 ㄴ 내부적으로 1개의 this로 구분
    //멤버함수 시그니쳐는... 
    //정적은 객체 생성 전 사용 가능 멤버변수 함수 사용ㄴ -> this사용불가
};

int sub(int a, int b){
    return a - b;
}


int main(){
    Point p1;
    Point p2;

    p1.set(10, 20); // --> 컴파일러는 set(&p1, 10, 20); 이렇게 해석 //Point::Set(&p1, 10, 20);
    p1.set(20, 30); // --> 컴파일러는 set(&p1, 20, 30); 이렇게 해석 //Point::Set(&p2, 20, 30);

    cout << &p1 << endl;
    p1.foo();
    cout << &p2 << endl;
    p2.foo();

    //static은 타입에 ㄴㄴ
    //Point::add의 타입은 int(int, int)
    int(*fp)(int, int) = &Point::add;
    fp = &sub;
}