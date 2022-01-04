//c++의 표준 입출력 

//1. C언어에서는 표준 입출력을 위해 대표적으로 사용하는 함수
// : prinf, scanf

/*
#include <stdio.h>

int main(){
    int n = 0;
    scanf("%d", &n);

    printf("out: %d\n", n);
}
*/

//C++에서 제공하는 표준 입출력
#include <iostream>
using namespace std; //!

int main(){
    int n = 0;
    cin >> n;
    //scanf("%d", &n); //c
    //1. 정수 타입을 지정할 필요가 없다.
    //2. 주소를 보내지 않아도, 값이 변경된다.
    //3. std::cout, std::cin 정체는 무엇인가.?
    //4. std::endl 정체는 무엇인가?


    // cout << "out : " << n << std::endl;
    cout << "out : " << n;
    cout << std::endl;
}