#include <iostream>
#include <iomanip> //setw, setfill

using namespace std;

int main(){
    int n = 42;

    cout << n << endl;
    cout << hex << n << endl; //16진수 //2a
    cout << uppercase << n << endl; //대문자 //2A

    //printf("%4d")
    cout << setw(4) << n << endl; //  2A
    cout << setw(4) << setfill('0') << n << endl; //002A


    cout << oct << n << endl; //8진수
    cout << dec << n << endl; //10진수
    //한 번 사용하면, 다시 변경하기 까지 *상태가 유지*됩니다.
    
}





