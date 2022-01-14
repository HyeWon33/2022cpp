#include <iostream>
using namespace std;

// 아이템 상태에 따른 동작의 변화
// 방법2. 변하는 것을 가상함수로 만든다.
//  => Item에 따라 동작은 변한다.


class Character {

    int item;

public:
    int gold;

    virtual void Run() { cout << "Run" << endl; }
    virtual void Attack() { cout << "Attack" << endl; }
};

// 아이템의 획득에 따라 동작을 변경하기 위해,
// 상속을 사용합니다.
class FastRunCharacter : public Character {
public:
    void Run() override { cout << "Fast Run" << endl; }
};

class SlowRunCharacter : public Character {
public:
    void Run() override { cout << "Slow Run" << endl; }
};

int main()
{
    Character* current;

    Character c;

    current = &c;
    current->gold = 100;
    current->Run();

    FastRunCharacter fc;
    current = &fc;
    cout << current->gold << endl;
    // 동작 뿐 아니라 상태도 변경된다. Gold는 공유되어야 합니다.

    current->Run();

    SlowRunCharacter sc;
    current = &sc;
    current->Run();
}
//문제점.. 기존 캐릭터 상ㅌㅐ 변경된게 아니라 다른 객체 사용되고 있다?