#include <iostream>
using namespace std;

//int a; a 타입 => int
//int x[10]; x 타입 => int[10] 인트 열개짜리 배열 타입
//int y[3]; y 타입 => int[3] 인트 세개짜리 배열 타입
//x와 y는 다른 타입

//C++ / C++함수는 배열을 인자로 전달받을 때 decay(부식)[디케이]를 수행합니다.
// > 배열의 첫 번째 원소의 시작 주소가 전달됩니다.
// : 배열을 전달받는 함수는 반드시 길이에 대한 추가정보를 인자를 통해 전달해야 합니다.

void foo(int *x, int n){ //void foo(int *x)였다.
    for (int i = 0; i < 10; i++){
        cout << x[i] << endl;
    }
}

// goo(z) 입력받고 싶으면
void goo(int (*p)[5]){

}

/*
int main(){

    int z[3][5];
    //z의 타입 : int[3][5] 인테져 세개짜리 배열이 5개 있다. z는 3개짜리 배열
    //[ int[5] ][ int[5] ][ int[5] ]. 이거 가르키는 포인터 : int(*p)[3]
    //int*p[5] vs int(*p)[5] 
    //int*p[5] : 포인터 배열(40바이트) => 배열   [int*][int*][int*][int*][int*]
    //int(*p)[5] : int[5]을 가르키는 포인터 => 배열 포인터(8바이트) => 포인터
    goo(z);

    int y[3] = {1,2,3};
    foo(y, 3);

    // int a = y[0]; => auto a = y[0];
    //auto를 사용하면, 우항의 타입과 동일한 타입으로 컴파일 타임에 결정됩니다.
    auto a = y[0];
    auto p = &y[0];
    //g++ 3_variable.cpp -std=c++11
    // auto xx; => X 
    //반드시 우항 필요 


    //x타입 : int 배열 10개짜리
    int x[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
    foo(x, 10);
}

*/

//typedef
// : 기존 타입의 별칭을 만들어서 사용할 수 있습니다.
// > 복잡한 타입을 간결하게 사용할 수 있습니다.
typedef int (*POINTER)[3];

void hoo(int (*p)[3]){ //==>void hoo(POINTER p){

}

void goo(POINTER p){

}

//C++11에서는 typedef 말고, *using*을 통해서 타입의 별칭을 만들 수 있습니다.
//장점
//1. 가독성이 좋다.
//2. typedef는 '템플릿'의 문법에서는 사용할 수 없습니다.
using POINTER2 = int (*)[3];
void xoo(POINTER2 p){

}

int main(){
    int x[2][3]; //x : [int[3]][int[3]]
    hoo(x);
    goo(x);
}
//g++ 3_variable3.cpp -std=c++11