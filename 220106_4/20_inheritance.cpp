#include <iostream>
using namespace std;

//상속
//서로 연관되어 객체지향

#include <string>

#if 0
class Student{
private:
    string name;
    int age;
    int id;
};

class Professor{
private:
    string name;
    int age;
    int major;
};
#endif

// 상속 문법을 이용하면 공통의 속성을 관리하는 것이 편하다.
// > 공통의 속성을 가진 타입을 설계한다.

//User : Base / Super 클래스라고 부른다.
//Student, Professor : Derived / Sub 클래스라고 부른다.

class User{
private:
    string name;
    int age;
};

class Student : public User{
private:
    int id;
};
class Professor : public User{
private:
    int major;
};