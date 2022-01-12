#include <iostream>
using namespace std;

#include <algorithm>

// 함수 사용
bool cmp(int a, int b){return a > b;}

struct Less
{
    bool operator()(int a, int b) const {return a > b;}
};

int main(){
    int x[] = {1,3,5,7,2,4,6,8,10};

    sort(x, x+10, &cmp);

    Less less;
    sort(x, x+10, less);

    // 함수 객체를 쉽게 만드는 문법
    //  => *람다(Lambda)* : 코드 블록을 참조하는 기술 
    //   : C++11 문법으로 지원한다.
    //   - c++에서는 익명의 함수객체를 생성하는 기술
    sort(x, x+10, [](int a, int b){return a > b;});

}
