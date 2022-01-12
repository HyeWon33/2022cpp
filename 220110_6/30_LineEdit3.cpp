// 30_LineEdit.cpp
#include <iostream>
#include <string>
using namespace std;

#include <stdio.h>
#include <termios.h>
#include <unistd.h>


int getch(void)
{
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}
//--------

// 공통성과 가변성 분리 방법 2번째
//  - 변하는 것을 다른 클래스로 뽑아낸다.
//  => 교체 가능한 인터페이스 기반 클래스로 뽑아낸다. (인터페이스 기반 클래스로 뽑아내는 이유가 교체 가능하기 위해서)
//   : Sterategy Pattern(전략 패턴)
//    1) 실행 시간에 정책을 변경하는 것이 가능하다.
//      - LineEdit.SetValidator(...)
//    2) Validator의 정책을 다른 클래스에서도 재사용 가능하다.

// Validation 정책에 관한 인터페이스를 설계한다.

struct Validator { 
    virtual ~Validator() { }

    virtual bool Validate(const std::string& s, char c)
        = 0;

    virtual bool IsComplete(const std::string& s) = 0;
};

class LineEdit {
    std::string data;

    //-----
    Validator* pValidator;

public:
    LineEdit()
        : pValidator(nullptr)
    {
    }

    void SetValidator(Validator* p) { pValidator = p; }
    //-----

    std::string GetData()
    {
        data.clear();

        while (1) {
            char c = getch();

            if (c == '\n' && (pValidator == nullptr || pValidator->IsComplete(data)))
                break;

            if (pValidator == nullptr || pValidator->Validate(data, c)) {
                data.push_back(c);
                cout << c;
            }
        }

        cout << endl;
        return data;
    }
};

// 새로운 정책의 LineEdit가 필요하면, 정책 클래스를 Validator의 인터페이스를 기반으로 만들어주면 된다.

class LimitDigitValidator : public Validator {
    int limit;

public:
    LimitDigitValidator(int n)
        : limit(n)
    {
    }

    bool Validate(const std::string& s, char c) override
    {
        return s.size() < limit && isdigit(c);
    }

    bool IsComplete(const std::string& s) override
    {
        return s.size() == limit;
    }
};

int main()
{
    LineEdit edit;

    LimitDigitValidator v(5);
    edit.SetValidator(&v);

    while (1) {
        string s = edit.GetData();
        cout << "out: " << s << endl;
    }
}



//패턴처럼 많이 사용되는 코드.. 이해 잘 하기