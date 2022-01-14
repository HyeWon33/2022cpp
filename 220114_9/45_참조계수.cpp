#include <iostream>
using namespace std;

// 객체의 수명을 참조 계수로 관리하는 경우가 매우 많다.
//  => new를 통해 객체를 생성한다.

class Image{
    int mCount;
public:
    Image() : mCount(0) { }
    ~Image() { cout << "Image 파괴" << endl; }

    void AddRef() { ++mCount; }
    void Release(){
        if(--mCount == 0) delete this;
    }
};

// 위의 클래스처럼 참조 계수 기반의 코드를 사용하는 규칙

int main(){
    Image* p1 = new Image;
    p1->AddRef(); // 규칙1. 객체를 만들면 참조 계수 증가해야 한다.

    Image* p2 = p1;
    p2->AddRef(); // 규칙2. 객체 표인터를 복사하면 참조 계수 증가해야 한다.

    // 규칙3. 포인터를 더 이상 사용하지 않을 때, 참조 계수 감소
    p1->Release();
    p2->Release();
}

//제대로 안 하면 누수 발생