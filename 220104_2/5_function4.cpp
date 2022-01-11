#include <iostream>
using namespace std;

// int square(int a){ return a*a; }
// double square(double a){return a*a;}


//리턴 타입과 파라미터 타입을 제외하면 구현이 완전히 동일하다.
// (그래서 템플릿을 사용)
// => 사용자가 템플릿을 제공하면 컴파일러가 코드를 컴파일 할 때 어떤 타입의 함수가 필요한지 
//    조사해서 실제 함수를 생성해줍니다.
// => C++은 Tempalte [템플릿], Java, Kotlin, C#, Swift... 는 Generics [제너릭] 이라고 부른다.

//템플릿
template <typename T>
template <class T> //typename 대신 class 사용해도 된다.
T square(T a) {return a*a;}

int main(){
    cout << square(3) << endl;
    cout << square(3.14) << endl;
}

