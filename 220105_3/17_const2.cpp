#include <iostream>
using namespace std;

//주의 사항
class Test{
    int x;
public:
    Test() {} //이거 없으니까 main에 t2가 빨간줄
    //1. 모든 멤버 데이터를 상수 취급한다.
    const int* getAddress() const{ //<- int* getAddress() const
        //x의 타입은 const int 타입으로 취급한다.
        return &x;
    }
    //2. const 함수는 오버로딩이 가능하다.
    void foo(){
        cout << "foo" << endl;

    }
    void foo() const {
        cout << "const foo" << endl;
    }

    void goo() const;   
};

//3. 선언과 정의를 분리할 때, 모두 const가 명시되어야 한다.
void Test::goo() const{}

int main(){
    Test t1;
    const Test t2;

    t1.foo();
    t2.foo();

}


//멤버함수에만 const???

//특정한 타입앞 const -> 그거 상수..
//멤버함수 뒤에 const -> 그 안에서 값을 수정하지 않겠다. 멤버 데이터 값을 그 의미로 표시