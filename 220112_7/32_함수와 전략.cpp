#include <iostream>
using namespace std;

void Sort(int* x, int n){ //x배열 오름차순으로 만들고 싶다.

    for (int i = 0; i < n - 1; ++i){
        for(int j = i+1; j < n; ++j){
            if(x[i] > x[j])
                swap(x[i], x[j]);
        }
    }
}

int main(){
    int x[10] = {1,3,5,7,9,2,4,6,8,10};
    Sort(x, 10);

    for (int e : x){
        cout << e << endl;
    }
}
