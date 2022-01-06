//C++11부터 스레드를 표준 라이브러리를 통해 지원한다.

#include <iostream>
#include <mutex>
#include <thread>

#if 0
void foo(){
    std::cout << "foo" << std::endl;
}

int main(){
    std::cout << "main thread" << std::endl;
    std::thread t1(&foo);

    t1.join();
}
#endif

#if 0
void thread_routine(const char* name){
    std::cout << name << std::endl;
}

int main(){
    std::thread t1(&thread_routine, "A");
    std::thread t2(&thread_routine, "B");

    t1.join();
    t2.join();
}
//강사님 결과는
//A
//B 인데
//왜 나는 AB?
#endif


//g++ 18_thread3.cpp -lpthread -std=c++11

//보통 코드 만들 때 밖에서 안으로 만들어라.
//아래서 위로 만들면 끼워 맞춰서 만들게 된다.

int sum = 0;
std::mutex m;

void thread_routine(const char* name){
    std::cout << name << std::endl;

    for(int i = 0; i < 1000000; ++i){
        m.lock();
        sum += 1;
        m.unlock();
    }
}

int main(){
    std::thread t1(&thread_routine, "A");
    std::thread t2(&thread_routine, "B");

    t1.join();
    t2.join();

    std::cout << "sum : " << sum << std::endl;
}
