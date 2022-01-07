#include <iostream>
using namespace std;

// operator(연산자)
// +, -, =, >>, <<, / ...


//연산자 오버로딩
class Point{
private:
    int x;
    int y;
public:
    Point(int a, int b) : x(a), y(b){}

    // 1. 값을 읽는 함수를 제공한다.
    /*
    int GetX() const {return x;}
    int GetY() const {return y;}
    */

    // 2. friend
    //  > friend로 선언된 함수나 클래스는 private접근이 가능하다.
    friend Point operator+(const Point& lhs, const Point& rhs);

#if 0
    Point operator+(const Point& rhs) const{ //<-Point Add(const Point& rhs) const
        return Point(x + rhs.x, y + rhs.y);
    }
#endif
    
    void Print() const{
        cout << x << ", " << y << endl;
    }
};

Point operator+(const Point& lhs, const Point& rhs){
    // return Point(lhs.x + rhs.x, lhs.y + rhs.y);
    //외부에서 접근 불가
    //해결 방법
    //1. x, y값 읽는 함수 만들기
    // return Point(lhs.GetX() + rhs.GetX(), lhs.GetY() + rhs.GetY());

    //2. 클래스 내부에서 선언하고 앞에 friend 붙이기
    return Point(lhs.x + rhs.x, lhs.y + rhs.y);
}

// 연산자 오버로딩
//  : 연산자를 객체에 대해서 사용할 때, 약속된 함수가 호출된다.

int main(){
    Point p1(1, 1);
    Point p2(1, 10);

    // Point p3 = p1 + p1; //컴파일 에러 근데 위의 Add함수를 operator+로 바꾸면 에러 없다.
    // ↓↓↓↓↓ 컴파일러가 아래의 형태로 번역한다.
    // Point p3 = p1.operator+(p2);
    // Point p3 = operator+(p1, p2);

    // Point p3 = p1.Add(p2);
    // p3.Print();
}


//friend는 정보 은낵 깨트린다! 쓰지말자! 였지만 지금은 아니다잉
//내 상태를 많이 공유하지 마라 그게 중요한게 아니다.