#include <iostream>
using namespace std;

//C++에서는 파라미터의 타입이나 개수가 다르면, 동일한 이름의 함수를 여러개 만들 수 있습니다.
// => "함수 오버로딩"이라고 부릅니다.
// => 컴파일러가 함수의 파라미터 정보를 통해 이름을 생성합니다.
//    > 파라미터의 개수와 타입이 다르면 다른 이름이 생성됩니다.
//      "네임 맹글링"
//주의사항
//1. 반환 타입은 함수 이름에 영향을 미치지 않는다.
// int foo(){} void foo(){} 심볼충돌
// > 파라미터가 동일하고 반환타입이 다른 함수는 오버로딩이 불가능 합니다.

//void goo(int a){}, void goo(int a, int b){} 는 오버로딩
//void goo(int a){}, void goo(int a, int b=100){} 컴파일 타입 오류 발생
    //goo(10); //컴파일러는 어떤 함수를 호출할지 결정할 수 없다. -> 컴파일 오류


//C에서는 함수 이름 같으면 컴파일 오류 그래서 이름 다르게 만든다.
//매크로 함수를 통해서 #define SQUARE(x) x*x
//int main(){ SQUARE(3); }
//매크로 함수의 문제점
//1. 치환이기 때문에 우선순위에 대한 주의가 필요 ex) int main(){ SQUARE(3+3); } 나오는 답 : 3+3*3+3 원하는 답: (3+3)*(3+3)
//>괄호를 통해서 매크로 함수의 우선순위 문제를 해결할 수 있습니다.#define SQUARE(x) ((x)*(x))
//한 식에 ++2개 있으면 컴파일마다 다른 답이 나온다. ex) ((++x)*(++x))


int squre(int x){
    return x * x;
}
double squre(double x){
    return x * x;
}
char squre(char c){
    return c * c;
}

int main(){

}