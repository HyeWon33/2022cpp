#include <iostream>
using namespace std;

// Template 기반의 정책 교체

template <typename T, typename ThreadModel>
class List : public ThreadModel{
public:
    void push_front(const T& a){
        ThreadModel::Lock();
        cout << "데이터 삽입" << endl;
        ThreadModel::Unlock();
    }
};

// 스레드의 정책을 가지는 정책 클래스를 만든다.
class SingleThread{
public:
    inline void Lock(){}
    inline void Unlock(){}
};

class MultiThread{
public:
    inline void Lock(){cout << "동기화 시작" << endl;}
    inline void Unlock() {cout << "동기화 종료" << endl;}
};

List<int, MultiThread> s1;

int main(){
    List<int, SingleThread> s2;
    s1.push_front(10);

    s2.push_front(20);
}