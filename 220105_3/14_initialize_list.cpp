//14_initialize_list.cpp
// : 초기화 리스트

#include <iostream>
using namespace std;

class Point{
    int x, y;
    const int c;
    int &ra;
public:
//아래 처럼 사용하는 것은 대입이다.
    /*
    Point(int a, int b){
        x = a;
        y = b;
    }
    */
    //초기화 리스트 : 멤버 데이터의 값을 초기화하는 문법
    Point(int a, int b) : x(a), y(b), c(30), ra(a) {}
    //c = 10 상수는 반드시 초기화 되어야 한다. - 초기화 리스트를 사용해야 합니다.
    //ra = a

    //ra(a), y(b), c(30), x(a)이렇게 적어도
    //선언부 선언된 순서대로 초기화 된다.


    //(정수타입이 아니라 사용자정의타입 사용하면 생성하고 대입하는 것 자체가 더복잡하다. 초기화하는 것이 더 빠른 경우도 있다.)
    //초기화 리스트 무조건 써야 하는 경우 있다. - 상수, 참조타입, 기본 생성자가 제공되지 않는 멤더 데이터 초기ㅗ하

};
class Rect{
    Point p1;
public:
    //기본 생성자가 제공되지 않은 멤버 데이터에 대한 초기화가 필요하다.
    Rect() : p1(10, 20){}
};


int main(){
    /*
    const int c; //상수는 반드시 초기화가 되어야 한다.
    int &r; //참조 타입도 반드시 초기화가 필요하다.
    */

    int a = 10;

    int b;
    b = 10;
}