#include <iostream>
using namespace std;

//이벤트를 처리하는 방법(설계)

#include <string>

class MenuItem{
    std::string title;
public:
    MenuItem(const std::string& s) : title(s){}
    virtual void Command(){
        cout << title << "메뉴가 선택됨" << endl;
        // 핵심 : 메뉴가 선택된 사실을 다시 외부에 알려야 한다.
        //  "객체가 외부로 이벤트를 발생한다." 라고 표현해야 한다.
    }
};

int main(){
    MenuItem m1("저장");
    MenuItem m2("불러오기");

    m1.Command();
    m2.Command();
}