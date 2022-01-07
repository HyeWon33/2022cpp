#include <iostream>
using namespace std;

//interface2번 코드에서 이어서

// 1. 자동차에 카메라를 연결하기 위해 지켜야 하는 규칙을 먼저 설계한다.
//  => 인터페이스
//   => 아래처럼 구현이 제공되지 않는, 순수 가상 함수로만 이루어진 클래스를 "인터페이스"라고 한다.
//   => 인터페이스는 무조건 public
//   => 인터페이스는 class로 쓰기도 하지만 struct로 쓰는 사람도 있다. class로 만들면 public 써야 하고 struct로 만들면 그냥 써도 되고
//   => 다른 언어에서 프로토콜이라고도 부른다.
//   => 사용 목적은 약한 결합 구현
//   => 이점은 교체 가능하다.
//   => 상속한다가 아니라 인터페이스 구현해야 한다. 구분해야 한다.
//   => 문제점 : 성능 빼고 인터페이스 자체가 수정되기 어렵다.


#if 0
class BlackBoxCamera{
public:
    virtual ~BlackBoxCamera(){}

    virtual void StartRecord() = 0;
    virtual void StopRecord() = 0;

    // virtual void NewFeature() = 0; //추가하면 아래도 다 추가해줘야 한다. 아니면 error
};
#endif

struct BlackBoxCamera {
    virtual ~BlackBoxCamera() { }

    virtual void StartRecord() = 0;
    virtual void StopRecord() = 0;
};

// 2. BlackBoxCamera를 이용하는 코드로 작성한다. 
class Car{
private:
    BlackBoxCamera* pCamera;

public:
    Car(BlackBoxCamera* p) : pCamera(p) {}

    void Start() {
        //...
        pCamera -> StartRecord();
    }
    void Stop(){
        pCamera -> StopRecord();
    }
};

// 3. 카메라의 작성자는 반드시 BlackBoxCamera 인터페이스를 구현해야 한다.
// => BlackBoxCamera를 상속 받아서 만들어야 합니다.

class Camera {
public:
    void StartRecord(){
        cout << "Start Record" << endl;
    }
    void StopRecord(){
        cout << "Stop Record" << endl;
    }
};

class Camera : public BlackBoxCamera {
public:
    void StartRecord() override
    {
        cout << "Start Record" << endl;
    }

    void StopRecord() override
    {
        cout << "Stop Record" << endl;
    }
};

class HDCamera : public BlackBoxCamera {
public:
    void StartRecord() override
    {
        cout << "[HD]Start Record" << endl;
    }

    void StopRecord() override
    {
        cout << "[HD]Stop Record" << endl;
    }
};

int main()
{
    HDCamera cam;
    Car car(&cam);

    car.Start();
    car.Stop();
}



//장점 : 기존 코드 수정 없이 main문 조금만 고치면 HD로 수정된다.
//단점 : 코드의 양 더 많다. 복잡도 올라간다(관리의 비용 올라간다.). 동적바인딩이다(정적바인딩이 더 빠른디)
 

//설계는 양날의 칼
//