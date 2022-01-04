//헤더 파일과 소스 파일을 분리하는 방법
// - internal linkage(내부 연결)
//  : 같은 파일에서만 접근이 가능
//    => 헤더 파일은 반드시 내부 연결에 대해서만 가지고 있어야 한다.

// - external linkage(외부 연결)
//  : 다른 파일에서 접근이 가능
//    => 내부 연결/ 외부 연결을 가지는 부분을 모두 가질 수 있다.

//헤더파일은 컴파일 대상이 아니다.
//소스코드와 같이 돌아간다?
//심볼 충돌 가능하다.

/*
//a.cpp
int a = 10;

//b.cpp
int a; //a라는 전역 변수 존재한다고 선언해주는거
void foo(){
    a = 10;
}
*/

class Stack{
private:
    int *buff;
    int idx;

public:
    
    Stack(int sz = 10);

    ~Stack();

    void push(int v);
    int pop();
};