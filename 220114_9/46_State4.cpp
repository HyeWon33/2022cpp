#include <iostream>
using namespace std;

// 아이템 상태에 따른 동작의 변화
// 방법3. 인터페이스 기반 클래스로 뽑아낸다.
//  => State Pattern
//   : 인터페이스 기반 클래스로 분리하는 전략 패턴과 유사하지만, 패턴의 의도가 상태에 따른 동작의 변화라면, 상태패턴이라고 한다.

struct ItemState {
    virtual ~ItemState() { }

    virtual void Run() = 0;
    virtual void Attack() = 0;
};

class Character {
    // int gold;
    // int item;
    ItemState* state = nullptr;

public:
    int gold;

    void SetState(ItemState* p) { state = p; }

    void Run()
    {
        if (state)
            state->Run();
    }
    void Attack()
    {
        if (state)
            state->Attack();
    }
};

// 다양한 아이템의 상태에 따른 동작을 정의합니다.
class FastRunState : public ItemState {
public:
    void Run() override { cout << "Fast Run" << endl; }
    void Attack() override { }
};

class SlowRunState : public ItemState {
public:
    void Run() override { cout << "Slow Run" << endl; }
    void Attack() override { }
};

int main()
{
    FastRunState fs;
    SlowRunState ss;

    Character c;
    c.gold = 100;
    c.SetState(&fs);
    c.Run();

    c.SetState(&ss);
    cout << c.gold << endl;
    c.Run();

    c.Attack();
}

//이 전의 문제는 c 객체가 변경된게 아니라서 gold그래도 출력됬었는데 이제는 제대로 전이되서 출력된다.