#include <iostream>
using namespace std;


class Animal{
    int age;

public:
    virtual ~Animal(){}
    virtual void Cry() {cout << "Animal Cry" << endl;} //<- void Cry()
};
class Dog : public Animal{
    int color;
public:
    void Cry() override {cout << "Dog Cry" << endl;}
};

int main(){
    Animal a; 
    cout << sizeof(a) << endl; //기본 : 4 -> virtual : 16
    Dog d;
    cout << sizeof(d) << endl; //8 -> 16
    //가상함수 1개라도 갖고 있으면 크기 늘어난다.   virtual ~Animal(){}이 문장 추가해도 크기 16

}