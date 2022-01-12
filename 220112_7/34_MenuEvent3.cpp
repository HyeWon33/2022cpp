#include <iostream>
using namespace std;

#include <string>

// 2. 함수 포인터 기반의 이벤트 처리 방법
//  > 자바를 제외한 모든 플렛폼에서 사용한다.
//    iOS Target-Action / C# Delegate / MFC MessageMap
//  > 핸들러 기반 이벤트 처리 방법이라고 한다.
//    : 일반 함수와 멤버 함수를 묶어서 관리할 수 있는 범용 함수 포인터 개념을 제공한다.

class Dialog{
public:
    void Open() { cout << "Dialog Open" << endl;}
    void Close() { cout << "Dialog Close" << endl;}
};
//멤버함수 단독호출 불가능 객체 필요하다..?!



// 문제점
// 1. Dialog 멤버 함수만 사용할 수 있다.
// 2. 일반 함수도 사용할 수 없다.

class MenuItem{
    std::string title;

    // 멤버 함수 포인터
    void (Dialog::*handler)(); //void (Dialog::*handler)() = nullptr; //여기서 초기화 하면 아래서 하지말고 여기서 안 하면 여기서 해
    Dialog* object; //Dialog* object = nullptr; nullptr로 초기화 해야 안정

public:
    void SetHandler(void (Dialog::*h)(), Dialog* obj){
        handler = h;
        object = obj;
    }
    MenuItem(const std::string& s) : title(s), handler{}
    virtual void Command(){
        cout << title << "메뉴가 선택됨" << endl;

        if(object == nullptr || handler == nullptr)
        return;
        (object->*handler)();        
    }
    
};

int main(){

#if 0
    //멤버함수포인터 문법
    Dialog dlg;
    Dialog* p = &dlg;

    void (Dialog::*fp)() = &Dialog::Open;
    fp = &Dialog::Close;

    (dlg.*fp)();
    (p->*fp)();
#endif

    MenuItem m1("저장");
    MenuItem m2("불러오기");

    m1.SetHandler

    m1.Command();
    m2.Command();
}