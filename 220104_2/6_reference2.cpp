#include <iostream>
using namespace std;


//1. call by value
void inc(int x){
    ++x;
}

//2. call by pointer (C에서는 call by reference)
void inc2(int *x){
    ++(*x);
}

//3. call by reference
void inc3(int &x){
    ++x;
}

/*
int main(){
    int n = 10;
    inc(n);// n은 10이다. inc()에서의 x와 main 에서의 n은 다르다.
    inc2(&n); //11이 나온다.
    inc3(n); //11 나온다.

    cout << n << endl;  
}
*/
//decay 배웠잖아. 배열의 이름이 decay된다.
//reference는 decay가 안된다.

/* //foo = 8바이트
void foo(int x[5]){ 
    printf("foo : sizeof(%ld)\n", sizeof(x));
}
*/

void foo(int *x, int n){ 
    printf("foo : sizeof(%ld)\n", sizeof(x));
}

void goo(int (&x)[5]){ 
    printf("goo : sizeof(%ld)\n", sizeof(x));
}

int main(){
    int x[5];
    printf("main : sizeof(%ld)\n", sizeof(x));

    foo(x); //배열의 첫번째 원소의 시작 주소로 전답된다. - 디케이
    goo(x); //참조 타입은 디케이가 발생하지 않는다.
            //정확한 타입이 명시되어야 한다.
}

//원래 배열 길이도 보냈는데 reference로 쓰면 안 보내도 된다....
//배열의 이름은 배열의 첫 번째 원소의 주소로 해석된다는 deacy룰 예외로 해석도니다.
//1. reference 2. sizeof 3. n%d연산



// 2_iostream.cpp에서 궁금증 해결되었다.
// 1. *함수 오버로딩*으로 구현 되었다. 정확한 함수 찾아 간다.
// 2. 포인터가 아닌 *레퍼런스*로 되어 있다.









//++++++강사님 설명 조금 빼먹었다.