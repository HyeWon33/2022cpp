#include <iostream>
using namespace std;

// operator(연산자)
// +, -, =, >>, <<, / ...

class Point{
private:
    int x;
    int y;
public:
    Point(int a, int b) : x(a), y(b){}
};

int main(){
    Point p1(1, 1);
    Point p2(1, 10);

    // Point p3 = p1 + p1; //컴파일 에러
}
