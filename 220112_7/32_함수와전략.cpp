#include <iostream>
using namespace std;

// 핵심 : 변하지 않는 전체 알고리즘에서 변해야 하는 정책 코든느 분리되어야 한다.
//  > 일반 함수에서는 변하는 것을 함수 인자(함수 포인터)로 뽑아내면 된다.

bool cmp1(int a, int b){ return a > b;} // 오름차순
bool cmp2(int a, int b){ return a < b;} // 내림차순

// inline bool cmp1(int a, int b){ return a > b;} 수행 할 수 없다...


void Sort(int* x, int n, bool (*cmp)(int a, int b)){

    for (int i = 0; i < n - 1; ++i){
        for(int j = i+1; j < n; ++j){
            // if(x[i] > x[j]) //if(x[i] < x[j]) 내림차순이 된다.   -> 공통성과 가변성의 분리
            if(cmp(x[i], x[j]))
                swap(x[i], x[j]);
        }
    }
} //버블sort 별로다. 

int main(){
    int x[10] = {1,3,5,7,9,2,4,6,8,10};
    // Sort(x, 10);

    // Sort(x, 10, &cmp1); //오름차순
    Sort(x, 10, &cmp2); //내림차순

    for (int e : x){
        cout << e << endl;
    }
}



//조금 빠진  부 분 있다..