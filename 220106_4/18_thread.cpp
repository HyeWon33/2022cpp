//#include <thread> //c++11
#include <pthread.h>
#include <unistd.h> //usleep
#include <iostream>
using namespace std;

void *foo(void *foo){
    for(int i = 0; i < 10000000; i++){
        usleep(200000);
        cout << "foo" << endl;
    }
    return nullptr;
}
    

int main(){
    pthread_t thread;
    pthread_create(&thread, nullptr, &foo, nullptr);
    
    for(int i = 0; i < 10000000; i++){
        usleep(100000);
        cout << i << endl;
    }
}

//원래는 main흐름만 있었는데 pthread로 스레드 만들어서 위 코드 돌려보면 숫자 올라가는거랑 foo 같이 출력된다.
//htop성능 확인

//라이브러리 연결해서 해야 한다.
//g++ 18_thread.cpp -lpthread