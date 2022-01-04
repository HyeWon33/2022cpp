#include <iostream>

//1. 전체 이름을 사용하는 방법
//  1) 이름공간과 함수의 이름을 사용한 방법
//     ex) std::cout, std::endl, std::printf

/*
int main(){
    std::cout << "Hello, cpp" << std::endl << "Hello, cpp" << std::endl;
}
*/

//2. using 선언(decl)을 사용하는 방법

/*
using std::cout;
using std::endl;
int main(){
    cout << "Hello, cpp" << endl << "Hello, cpp" << endl;
}
*/

//3. using 지시어(directive)
//단점 : 실제 제품 코드 만들 때 3번 방법 사용하면 별로다.

/*
using namespace std;

int main(){
    cout << "Hello, cpp" << endl << "Hello, cpp" << endl;
}
*/

//using namespace std 맘대로 쓰면
/*
#include <algorithm> //std::count라는 것 있다.
using namespace std;

int count; //전역분수
int main(){
    count = 10; //알고리즘의 count와 std의 count 이름 충돌...
    //std::count() 
    cout << "Hello, cpp" << endl << "Hello, cpp" << endl;
}
*/

//강사님은 std::cout, std::endl 이렇게 쓰는거 추천
