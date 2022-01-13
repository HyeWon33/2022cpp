#include <iostream>
using namespace std;

// 싱글톤
// Singleton Pattern
//전역객체 같은거 근데 이 문제점은 컴파일의 단위는 파일인데 전역객체에 대한 호출 보장받지 못하고 객체 파괴 정의되어있지 않다. 하지만 싱글톤 사용하면 내부 ㄱ정적객체 처믕 호출되는 시점에 호출되고 소멸자더는 더 호출되 지 않으면 소멸자 이렇게 정의되어이싿.
//싱글톤은 논쟁 많다. 전역객체 모델링 한건데 전역객체의 장단점 다 여기에 나타난다. 복잡도 낮춘다. 전역객체에 의존하면 재사용성 떨어진다. 프로그램의 유지보수 떨어지낟. 쓰지 말란건 아니고 많이 쓰고 있는데 난무하지 마라. 

//내부 정적 개채 기반으로 싱글톤 만들고 마이어스의 싱글톤이라고도 부른다. 보통 정적메모리에 안 하고 힙 에서도 한다. 정적메모리는 한번에 크기 정해져있다.

// 의도 : 오직 한개의 객체만 만들 수 있고, 어디에서든 동일한 방법으로 객체를 얻을 수 있게 하는 패턴

class Cursor{
private:
    Cursor(){} // 규칙 1. private 생성자

    //규칙 3. 복사와 대입 금지
    Cursor(const Cursor&) = delete;
    Cursor& operator=(const Cursor&) = delete;

public:
    // 규칙 2. 오직 한 개만 만드는 정적 멤버 함수
    static Cursor& GetInstance(){
        static Cursor instance;
        return instance;
    }
};

int main(){
    // Cursor c; // error!
    // Cursor* p = new Cursor; // error!

    Cursor& c1 = Cursor::GetInstance();
    Cursor& c2 = Cursor::GetInstance();

    // Cursor c3 = Cursor::GetInstance(); // 복사
    // c3 = Cursor::GetInstance(); // 대입

    cout << &c1 << endl;
    cout << &c2 << endl;
}
