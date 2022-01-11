#include <iostream>
using namespace std;

//상수 멤버 함수
class Point{
    int x, y;
public:
    Point(int a, int b) : x(a), y(b) {}

    //멤버 함수를 만들 때 함수의 ()뒤에 const를 붙이면, 상수 멤버 함수가 된다.
    // -> 상수 멤버 함수 안에서는 모든 멤버 데이터가 상수 취급됩니다.
    // -> 상수 멤버 함수 안에서 멤버 데이터의 값을 변경하는 것이 불가능합니다.
    void print()  //<- void print() <-void print() const
    {
        //x+=1; //compile error~!
        cout << x << ", " << y << endl;
    }
    void move(int d){
        x += d;
        y += d;
    }
};

void foo(const Point &p){
    // p.move(); -> X
    p.print();
}

int main(){
    /*
    // //const 되면 값 변경 못 하니까 
    const Point p(10, 20); //<- Point p(10, 20);
    //p.move(10)
    p.print();
    */

    Point p (20, 30);
    p.move(10);
    p.print();
}

//상수 멤버 함수가 왜 필요한가?
// - 상수 객체는 상수 멤버 함수만 호출할 수 있다.
// - 객체를 함수에 전달할 때, const&를 통해서 전달한다.
// => const &를 통해 참조하는 객체는 상수 취급된다.
// => 상수 멤버 함수만 호출이 가능하다.