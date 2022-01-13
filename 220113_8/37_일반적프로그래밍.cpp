#include <iostream>
using namespace std;

// C++의 표준 라이브러리를 이해하기 위해서는 일반화(Generic)를 이해해햐 한다.
// C++ = 객체 지향 + 일반화(Generic)

//C언어에 문자열 안에서 한 글자 찾가 : 선형 검색
#if 0
char* xstrchr(char* s, char c){
    while(*s != '\0' && *s != c)
        s++;
    return *s == c ? s : NULL;
}

int main(){
    char s[] = "abcdefg";

    char *p = xstrchr(s, 'c');

    if(p)
        cout << *p << endl;
}
#endif

//C++에서는 일반적이지 않다.
//특정한 구간 탐생은 char* xstrchr에서는 불가능
//C++에서는 범용적으로 만들자.


// 1. 검색 구간의 일반화
//  : 전체 구간에서 부분 구간에 대한 검색이 가능해야 한다.
//  > 검색할 구간의 시작과 검색할 구간의 마지막 다음 위치를 인자로 전달받도록 해야한다.

// first : x
// |
// abcdefg
//        |
//        last : x + 7
//last의 위치가 마지막 다음 위치인 이유 : 로직이 제일 깔끔.  last - first는 로직의 개수
//[first, last] : 반개구간

#if 0
char* xstrchr(char* first, char* last, char value){
    while(first != last && *first != value)
        ++first;

    return first == last ? nullptr : first;
}

int main(){
    char s[] = "abcdefg";

    char *p = xstrchr(s+2, s+7, 'c'); //부분 문자열에서 탐색도 가능하다. => 구간에 대한 일반화

    if(p)
        cout << *p << endl;
}
#endif

//실패처리는 문제 있다.
//실패를 nullptr로 표현하는 것은 일반적이지 않다. 
//마지막 다음 위치에 도달했다. => 요소 검색 실패했다.

#if 0
char* xstrchr(char* first, char* last, char value){
    while(first != last && *first != value)
        ++first;

    return first;
}

int main(){
    char s[] = "abcdefg";

    char *p = xstrchr(s+2, s+7, 'c'); //부분 문자열에서 탐색도 가능하다. => 구간에 대한 일반화

    if(p  != s+7)
        cout << *p << endl;
}
#endif

// 2. 검색 대상 타입의 일반화 => Template 도입

// T* xfind(T* first, T* last, T value)의 문제점
//  - T* 라고 하면, 포인터 타입만 가능하다. 스마트 포인터 사용 불가?

#if 0
template <typename T>
T* xfind(T* first, T* last, T value){
    while(first != last && *first != value)
        ++first;

    return first;
}


//↓↓↓

template <typename T1, typename T2>
T1* xfind(T1* first, T1* last, T2 value){
    while(first != last && *first != value)
        ++first;

    return first;
}

int main(){
    char s[] = "abcdefg";

    char *p = xstrchr(s+2, s+7, 'c');

    if(p  != s+7)
        cout << *p << endl;
}

#endif

//  - 구간의 타입과 요소의 타입을 분리하는 것은 double배열 안에서 int 타입을 찾는 것도 가능하다.

template <typename T1, typename T2>
T1* xfind(T1* first, T1* last, T2 value){
    while(first != last && *first != value)
        ++first;

    return first;
}

#include <vector>

int main(){

    vector<int> v = {1,2,3,4,5}; // C++11

    auto p2 = xfind(v.begin(), v.end(), 3);
    if(p2 != v.end())
        cout << *p2 << endl;

    //선형구간안에서 원한느 부분 차즌ㄴ 것은 문자열에서 찾는 로직과 벡터 안에서 찾는 것 똑같아. 
    //선형 타입 모든 함수 가능하게 마들어줄 필요 있다.

    char s[] = "abcdefg";

    char *p = xfind(s+2, s+7, 'c'); //부분 문자열에서 탐색도 가능하다. => 구간에 대한 일반화

    if(p  != s+7)
        cout << *p << endl;
}


//마지막 추가해야 한다.
// char* p = find(s + 2, s + 5, 'c');