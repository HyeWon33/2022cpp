#include <iostream>
using namespace std;

//C++에는 레퍼런스라는 새로운 형태의 타입을 제공한다.
// => 새로운 메모리를 할당하는 것이 아니라, 기존 메모리에 새로운 이름을 부여한다.

int main(){
    int n = 0; // 이 순간 4바이트의 메모리가 할당된다.

    int &r = n; //새로운 메모리 할당이 아니라 기존 메모리에 새로운 이름을 부여한다. 
    // int &r2; //컴파일 오류  
    //          // 레퍼런스 변수는 기존 변수의 별칭이므로, 반드시 초기값이 있어야 한다.


    r = 10;

    cout << n << endl;
}

//기존 변수와 동일한 메모리이고 이름만 바뀌는 것 
//그래서 반드시 초기화가 진행되어야 한다.