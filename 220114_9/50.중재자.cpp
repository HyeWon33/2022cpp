#include <iostream>
#include <vector>
using namespace std;


//세 개중 하나 선택이야 그럼 서로서로 알아야 한다. 점점 많아지만 알아야 하는 것이 많아져서 복잡도 증가한다.
//그래서 중재자. 중재자에만 연결되어있는거야. 서로서로 알 필요 없어. 새로운거 추가되어도 중재자에만 연결시켜주면 된다.

#if 0
class CheckBox{
    bool isChecked = false;
    MediatorCheckBox* mediator = nullptr;
public:
    void SetMediator(MediatorCheckBox* p){
        mediator = p;
        mediator->AddCheckBox(this);
    }
    void SetChecked(bool b) { 
        isChecked = b; 

        // 자신의 상태 변화를 중재자에게 알려주어야 한다.
        if(isChecked) { mediator->OnChanged(this); }
    }

    bool IsChecked() const { return isChecked; }
};

//중재자
class MediatorCheckBox{
    std::vector<CheckBox*> v;
public:
    void AddCheckBox(CheckBox* p) { v.push_back(p); }
    void OnChanged(CheckBox* p) {
        for(auto e : v){
            if(e != p) e->SetChecked(false);
        }
     }

     void Print(){
         for(auto e: v) cout << e << ":  " << e->IsChecked() << endl;
     }
};

int main(){
    CheckBox c1, c2, c3;
    MediatorCheckBox m;

    c1.SetMediator(&m);
    c2.SetMediator(&m);
    c3.SetMediator(&m);

    c1.SetChecked(true);
    getchar();
    m.Print();

    c2.SetChecked(true);
    getchar();
    m.Print();

    c3.SetChecked(true);
    getchar();
    m.Print();
}
#endif

//-----------------------------------------------------
//위에서 에러 난다. 그래서 분리 해줘야 한다고 한다.

// 중재자 패턴
// : 복잡한 객체의 관계(M:N)를 중재자와 객체의 1:1 관계로 처리한다.
// = 객체간의 관계가 복잡할 때 중재하는 객체를 만들어서 상호 관계를 캡슐화 한다.

class CheckBox;
class MediatorCheckBox {
    std::vector<CheckBox*> v;

public:
    void AddCheckBox(CheckBox* p) { v.push_back(p); }
    void OnChanged(CheckBox* p);
    void Print();
};

class CheckBox {
    bool isChecked = false;
    MediatorCheckBox* mediator = nullptr;

public:
    void SetMediator(MediatorCheckBox* p)
    {
        mediator = p;
        mediator->AddCheckBox(this);
    }

    void SetChecked(bool b)
    {
        isChecked = b;

        // 자신의 상태 변화를 중재자에게 알려주어야 한다.
        if (isChecked) {
            mediator->OnChanged(this);
        }
    }

    bool IsChecked() const { return isChecked; }
};

void MediatorCheckBox::OnChanged(CheckBox* p)
{
    for (auto e : v) {
        if (e != p) {
            e->SetChecked(false);
        }
    }
}

void MediatorCheckBox::Print()
{
    for (auto e : v) {
        cout << e << ": " << e->IsChecked() << endl;
    }
}

int main(){
    CheckBox c1, c2, c3, c4;
    MediatorCheckBox m;

    c1.SetMediator(&m);
    c2.SetMediator(&m);
    c3.SetMediator(&m);
    c4.SetMediator(&m);

    c1.SetChecked(true);
    getchar();
    m.Print();

    c2.SetChecked(true);
    getchar();
    m.Print();

    c3.SetChecked(true);
    getchar();
    m.Print();
}