//이름충돌 피하기 위해서 약속하면서 작성하는 스타일 -> C
//문법적으로 namespce 만든 거 -> C++

#include <iostream>

namespace Audio{
    void init() {std::cout << "Audio::init" << std::endl;}
}

namespace Video{
    void init() {std::cout << "Video::init" << std::endl;}

}

//namespace 장점
//1) 이름 충돌 해결
//2) 프로그램의 각 요소를 관련된 요소끼리 그룹화 할 수 있습니다.
//3) C++표준에서 제공하는 모든 요소들은 std의 이름공간안에 존재합니다.

//문제를 이해하고 c는 어떻게 해결 했는지 생각하는 것이 공부하는... c는 접두사 같은거 붙인다 C++에서는 접두사 붙이면 잘 해결하지 못하는거 namespce 써야지

void init(){
    std::cout << "Global init" << std::endl;
}

int main(){

    Audio::init(); //Audio init 안에 내용 수행
    Video::init();
    init();
}

//