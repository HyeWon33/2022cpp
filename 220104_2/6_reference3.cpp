#include <iostream>
#include <string>
using namespace std;

struct User{
    std::string name;
    int age;
};

// void prinUser(User user){
//     cout << user.name << ", " << user.age << endl;
// } //구조체나 배열같이 함수에 대한 인자 전달할 때 성능 고려하면 call by reference 사용해라
//   //구조체 길면 성능 떨어지는거야

//↓↓↓↓↓↓↓↓↓

//복사에 의한 오버헤드를 없앨 수 있습니다.
// => call by value
//   : 함수를 통해서 전달받은 파라미터의 값을 변경하지 않습니다.
//    void printUser(User user)
//    문제점 : 구조체 등의 크기가 큰 타입이 전달될 경우 복사에 의한 오버헤드가 있습니다.

//해결
// => call by reference
// => void printUser(User &user)
// : 복사에 의한 오버헤드를 없앨 수 있습니다.
// 함수에서 파라미터의 값을 변경하지 않아야 합니다.
// const &를 사용해야 합니다.
// => void printUser(const User &user)

void prinUser(User &user){
    cout << user.name << ", " << user.age << endl;

    //user.age += 10; //컴파일 에러 user는 읽기 전용 수정 ㄴ 읽기 ㅇ
}

//g++ 6_regerence3.cpp -std=c++11
int main(){
    User user{"Tom, 42"};
    printUser(user);
}