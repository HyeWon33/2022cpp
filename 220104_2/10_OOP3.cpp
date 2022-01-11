#include <iostream>
using namespace std;

//클래스도 템플릿으로 만들 수 있습니다.
// => 타입에 독립적인 스택을 만들 수 있습니다.
template <typename T>
//타입에 독립적인 자료구조

class Stack{
private:
    //멤버 변수(데이터)
    T *buff;
    int idx;

public:
    Stack(int sz = 10){
        idx = 0;
        buff = new T[sz]; //사용자가 전달한 크기 만큼 버퍼를 할당한다.
    }

    ~Stack(){
        delete[] buff;
    }

    //push
    void push(const T &v){ //복사 비용 줄이고 성능 이슈 없고...
        buff[idx++] = v;
    }
    //pop
    T pop(){
        return buff[--idx];
}
};

Stack<Complex> s4;
//클래스 템플릿은 타입 추론이 불가능 한다.
// => 명시적으로 타입을 지정해주어야 한다.
Stack<int> s1; //T -> int
int main(){
    Stack<long> s2(100); //T -> long
    Stack<double> s3{100}; //T -> double

    s1.push(10); 
    s2.push(20);

    cout << s1.pop() << endl; //<-pop(&s1), 10
    cout << s2.pop() << endl; //20
}

//스택을 템플릿 기반으로..