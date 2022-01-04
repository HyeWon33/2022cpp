#include <iostream>
using namespace std;

//함수의 목적 : 모듈화, 재사용성

// 1) Default parameter
// : 함수에서 전달되는 인자가 없는 경우 기본값을 사용합니다.
// > 기본값을 지정할 때 뒤에서부터 지정해야 합니다. //void foo(int a = 10, int b, int c, int d) => X
                                                //void foo(int a, int b, int c = 5, int d = 20) => foo(10, 20)이렇게만 사용가능
//함수 선언부
//함수를 선언과 구현으로 분리할 때는 선언부에만 기본값을 표기해야 합니다.
//void foo(int a, int b, int c = 5, int d = 20)

void foo(int a, int b, int c, int d){  
    cout << a << ", " << b << ", " << c << ", " << d << endl;
}

int main(){
    foo(10, 20, 30, 40);
    //foo(20, 30) //선언부 디폴트 값 없는데 이렇게 숫자 다 안 넣어주면 컴파일 오류 발생
}

// void foo(int a, int b, int c /* = 10*/, int d ?* = 30 */) //가독성을 위해 이렇게 표시해주는 경우도 있다.

//함수 구현부 //구현부에서 d = 10 이런식으로 숫자 넣지 말자 선언부와 구현부 다르면 선언부의 기본 값을 따라간다.
//선언부와 구현부에 모두 디폴트값을 표기하면 컴파일 오류 발생한다.
// void foo(int a, int b, int c, int d){  
//     cout << a << ", " << b << ", " << c << ", " << d << endl;
// }