#include <iostream>
using namespace std;

int gcd(int a, int b){
    return b != 0 ? gcd(b, a%b) : a; ////////이거 뭐냐...홀뤼
}
//gcd 함수를 double에 대해서 사용할 수 없도록 하고싶다.
    //1) 의도적으로 함수의 선언부만 제공
    // double gcd(double a, double b); //핵심: 선언만 한다.
    // => 링킹 오류를 통해 실행 파일 생성이 금지된다.
    // => 링킹 오류는 분석이 어렵다.
    //2} C++11 - delete function
    // => 함수를 삭제하는 문법
    // => 컴파일 오류가 발생한다.
    double gcd(double a, double b) = delete; //이러면 아래서 gcd(2.2, 4.3) 호출하면 내가 삭제한 함수
                                             //사용했다고 오류 알려준다 
                                             // 작성자의 의도적인 삭제 나타낸다.

int main(){
    cout << gcd(2, 10) << endl;
    cout << gcd(2.2, 4.3) << endl; //2.2 -> 2 4.3 -> 4
    //double이 int로 암묵적인 형변환되서 동작한다.
    // => 동작하면 안되는 코드.
}

/*
// 컴파일 단위는 파일 하나다. 그래서 아래 main에서 foo 없으니까 컴파일 에러
// 그래서 void foo();처럼 선언 (어딘가에 있다고 알려준거)

// main.cpp - complie - > main.o - linker - > main.o + foo.o => a.out

// main.cpp

void foo();
int main(){
    foo();
}

// foo.cpp
void foo(){
    print("foo\n")
}
*/