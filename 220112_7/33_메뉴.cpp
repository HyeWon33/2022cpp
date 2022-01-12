#include <iostream>
#include <string>
using namespace std;


// MenuItem과 PopupMenu의 공통의 부모다.
//  > MenuItem과 PopupMenu가 제공하는 공통의 기능이 반드시 부모 클래스로부터 비롯되어야 한다.
class BaseMenu {
    std::string title;
public: 
    BaseMenu(const std::string& s) : title(s){}
};

class MenuItem : public BaseMenu{
public:
    MenuItem(const std::string& s) : BaseMenu(s){}
};

// PopupMenu는 MenuItem도 가지고 있고, PopupMenu도 가지고 있다.
//  > 
class PopupMenu : public BaseMenu{
public:
    PopupMenu(const std::string& s) : BaseMenu(s){}

};