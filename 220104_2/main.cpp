#include <iostream>
using namespace std;

#include "Stack.h"

헤더파일 <> 와 "" 차이
//include path
// => 헤더 파일을 탐색하는 경로
// <> - 표준 라이브러리 등의 시스템에 설치된 헤더파일을 참조할 때 사용한다.
// "" - 사용자가 작성한 시스템에 설치되지 않고, 현재 디렉토리를 기준으로 제공되는 헤더 파일을 사용할 때 사용한다.


Stack s1;
int main(){
    Stack s2(100);
    Stack s3{100};

    s1.push(10); 
    s2.push(20);

    cout << s1.pop() << endl; //<-pop(&s1), 10
    cout << s2.pop() << endl; //20
}

//g++ -c Stack.cpp - std=c++11
//g++ -c main.cpp -std=c++11


//g++ Stack.cpp main.cpp -std=c++11
