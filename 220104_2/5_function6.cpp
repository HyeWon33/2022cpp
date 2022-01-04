#include <iostream>
using namespace std;

//함수포인터 중요
//함수 포인터
// => 함수의 주소를 참조하는 포인터
// => 함수의 포인터를 통해 함수를 호출할 수 있습니다.

//함수의 타입은 함수의 파라미터와 반환타입에 의해 결정된다.
// => 함수의 파라미터와 반환 타입이 동일하면 동일한 타입이다.

int sub(int a, int b){ return a - b;} //int(int, int)
// int add(int a, int b){ return a + b;} //int(int, int)
//add 와 sub은 같은 타입.

int add(int a, int b) { return a + b;} //add의 타입은 int(int a, int b)



int (*foo())(int a, int b){    //foo는 함수인데 포인터고 (int a, int b)를 받고 int를 반환?      
    return &add;
}

//↓

using FP = int (*)(int a, int b)

FP foo(){

}


//C++11 Trailing return type
// => 함수를 만드는 새로운 문법을 제공한다.
auto sub1(int a, int b) -> int{
    return a - b;
}
auto foo2() -> int (*)(int a, int b){
    return &add;
}

/*
int main(){
    int a;

    add(10, 20); //이러면 그냥 add call

    int *p = &a;

    // add => int(int a, int b)
    // int(int a, int b) *p2 = &add;  => X
    // int (*p2)(int a, int b) //p2는 포인터 (int a, int b) 받고 int를 반환하는
    int (*p2)(int a, int b) = &add;

    //p2 = &sub; //cout << (*p2)(10, 20) << endl; => -10
    cout << (*p2)(10, 20) << endl; //30
}

*/

//한 줄에서 뒤가 우선순위 높다.



int main(){
    int x[10] = {1,2,3,4,5,6,7,8,9,10};

    //일반적으로
    for (int i = 0; i < 10; ++i) 
        cout << x[i] << endl;
    
    //C++11 - ranged for 기능
    for (int n : x)
        cout << n << endl;

}


//++++++강사님 설명 조금 빼먹었다.