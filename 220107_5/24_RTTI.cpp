#include <iostream>
using namespace std;

// RTTI(Run-Time Type Information)
// 개념 : 실행 시간에 타입을 조사하는 기술

class Car{
public:
    int color;
};

class Sedan : public Car {
public :
    int speed = 100;    
};

void Go(Car* p){
    //p가 Sedan이면 speed를 출력하고 싶다.
    //체크 없이 사용할 경우
    Sedan* s = static_cast<Sedan*>(p);
    cout << "Speed : " << s->speed << endl;
}

int main(){
    Car c;
    Sedan s;

    Go(&c);
    Go(&s);
}