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

//----------------------------------------
//모든 직접해결하면 잘 안된다. 간접하자ㅎ
//교제에 업는 내용

// Image*를 바로 사용하면 참조 계수를 직접 관리해야 한다.
// 블편하므로, 참조 계수를 자동으로 관리하는 클래스를 만들자.
class ImageProxy{
    Image* image;
public:
    // 규칙1. 객체를 만들면 참조 계수 증가
    ImageProxy(Image* p) : image(p){
        image->AddRef();
    }

    // 규칙2. 객체 포인터를 복사하면 참조 계수 증가
    ImageProxy(const ImageProxy& rhs) : image(rhs.image){
        image->AddRef();
    }
    // 복사 생성자와 대입 연산자도 같이 제공해야 한다.
    ImageProxy& operator=(const ImageProxy& rhs){
        if(image != rhs.image){
            image->Release();
            image  rhs.image;
            image->AddRef();
        }
    }

    // 규칙 3. 포인터를 더 이상 사용하지 않을 때, 참조 계수 감소
    ~ImageProxy() { image->Release(); }

    // 진짜 Image* 처럼 동작해야 한다.
    //  => 연산자 오버로딩을 통해 ->, * 연산을 제공한다.
    inline Image* operator->() {return image;}
    inline Image& operator*() {return *image;}

};
//--------------------------------------------

// 위의 클래스처럼 참조 계수 기반의 코드를 사용하는 규칙

int main(){

    ImageProxy p1 = new Image;
    ImageProxy p2 = p1;

    p1->Draw();
    p2->Draw();
    // Image* p1 = new Image;
    // p1->AddRef(); // 규칙1. 객체를 만들면 참조 계수 증가해야 한다.

    // Image* p2 = p1;
    // p2->AddRef(); // 규칙2. 객체 표인터를 복사하면 참조 계수 증가해야 한다.

    // // 규칙3. 포인터를 더 이상 사용하지 않을 때, 참조 계수 감소
    // p1->Release();
    // p2->Release();
}

//제대로 안 하면 누수 발생

//어디..누락...