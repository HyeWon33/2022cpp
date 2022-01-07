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
    // p가 Sedan이면 speed를 출력하고 싶다.
    // 체크 없이 사용할 경우
    // Sedan* s = static_cast<Sedan*>(p);
    cout << "Speed : " << s->speed << endl;

    // RTTI사용방법
    //  - 모든 타입은 자신의 타입의 정보를 가지고 있는 type_info 구조체가 있다.
    //   : typeid 연산자를 통해 얻어올 수 있다.
    //   1) 객체를 통해서 얻을 수 있습니다.
    const type_info& t1 = typeid(*p);
    //   2) 클래스 타입을 통해서 얻을 수 있습니다.
    const type_info& t2 = typeid(Sedan);

    // => 만약 동일한 타입이면, t1과 t2는 동일합니다.
    if(t1 == t2){
        cout << "p는 Sedan 타입입니다." << endl;
    }
    else{
        cout << "p는 Sedan 타입이 아닙니다. " << endl;
    }
    
    // cout << t.name() << endl;
    // // 문제점 : type_info를 통해 얻을 수 있는 문자열 이름이 표준화에 포함되지 않았다.
    //  > 컴파일러마다 다른 결과가 나온다.
}

int main(){
    Car c;
    Sedan s;

    Go(&c);
    Go(&s);
}