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

class Car{
private:
    Camera* pCamera;

public:
    Car(Camer* p) : pCamera(p) {}

    void start() {
        //...
        pCamera -> StartRecord();
    }
    void stop(){
        pCamera -> StropRecord();
    }
};

int main(){

}