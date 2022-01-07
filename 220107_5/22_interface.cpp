#include <iostream>
#include <vector>
using namespace std;

// 1. 자식 클래스의 공통의 기능을 부모 타입 포인터를 통해 이용하기 위해서는, 해단 기능이 반드시 부모 클래스에서 비롯되어야 한다.
// 2. 부모 클래스가 제공하는 함수를 자식 클래스가 오버라이팅 할 경우, 해당 함수는 반드시 가상이어야 한다.
// 3. 가상 함수가 존재하는 모든 부모 클래스는 반드시 가상 소멸자이어야 한다.
class Shape{
public:

    virtual ~Shap() {}

    // Shape의 객체를 생성하지 않는다면, 아래 함수는 호출되지 않는다.
    // 4. 부모 입장에서 구현을 제공할 필요가 없고, 자식이 반드시 재정의를 해야 한다면, "순수 가상 함수"를 이용해야 한다.

    virtual void Draw() = 0

    #if 0
    virtual void Draw(){
        cout << "Shap Draw" << endl;
    }
    #endif
};

class Rect : public Shap{
public:
    void Draw() override{
        cout << "Rect draw" << endl;
    }
};

class Circle : public Shap {
public:

    ~Rect(){cout << "~Rect" << endl;}
    void Draw() override{
        cout << "Circle draw" << endl;
    }
};

// 부모 타입을 통해 Rect 와 Circle을 동시에 다룰 수 있다.

int main(){
    vector<Shape*> v;

    v.push_back(new Rect);
    v.push_back(new Circle);
    v.push_back(new Rect);
    v.push_back(new Circle);
    v.push_back(new Rect);
    v.push_back(new Circle);

    /*
    for (int i = 0; i < v.size(); ++i){
        v[i]->Draw()
    }
    */

   for(Shap* p : v){
       p->Draw();
   }
   for (Shape* p : v) {
        delete p;
    }
}