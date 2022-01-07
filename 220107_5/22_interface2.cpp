#include <iostream>
using namespace std;

class Camera {
public:
    void StartRecord(){
        cout << "Start Record" << endl;
    }
    void StopRecord(){
        cout << "Stop Record" << endl;
    }
};

class HDCamera{
public:
    void StartRecord(){
        cout << "[HD]Start Record" << endl;
    }
    void StopRecord(){
        cout << "[HD]Stop Record" << endl;
    }
};

//문제점
// Car클래스는 Camera 타입에 강하게 결합되어 있다.
//  => 강한 결합 : 어떤 클래스를 사용할 때, 구체적인 타입에 의존하는 것을 의미한다.
//  => 해결방법 : 약한 결합을 만든다.

class Car{
private:
    Camera* pCamera;

public:
    Car(Camera* p) : pCamera(p) {}

    void Start() {
        //...
        pCamera -> StartRecord();
    }
    void Stop(){
        pCamera -> StopRecord();
    }
};

int main(){
    Camera cam;
    Car car(&cam);

    car.Start();
    car.Stop();
}

//OCP : 개방 폐쇄 원칙(Open Close Principle)
// - 코드는 수정에는 닫혀있고 확장에는 열려있어야 한다.
// : 새로운 코드 