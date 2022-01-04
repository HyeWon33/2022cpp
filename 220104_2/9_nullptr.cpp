#include <iostream>
using namespace std;

//C언어에서 0은 int 타입이지만, 컴파일러에 의해서 특별하게 처리됩니다.

int main(){
    // int *p = 10; //암묵적.. 허용 X error
    // int *p = 0; //ok! 
                //0은 정수이지만 포인터로 암묵적 형변환이 됩니다.


    int *p = nullptr; //C++11에서는 포인터 0을 나타내는 nullptr를 제공한다.
    // int a = nullptr; // error

    //bool b = nullptr; // error
    bool b (nullptr); //직접 초기화서 nullptor을 bool에 암묵적 변환이 허용된다.
    
}
