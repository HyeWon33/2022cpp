// #include <iostream>
// using namespace std;


#include "Stack.h"



//디폴트 파라미터는 선언부에 들어가야 한다.    
Stack::Stack(int sz /*= 10*/){
    idx = 0;
    buff = new int[sz]; //사용자가 전달한 크기 만큼 버퍼를 할당한다.
}

Stack::~Stack(){
    delete[] buff;
}
void Stack::push(int v){
    buff[idx++] = v;
}
int Stack::pop(){
    return buff[--idx];
}

//파일을 나누는건 속도는 동일한데 다 관리적인 이슈이다.
//백만줄 코드 구분해서 관리하려고