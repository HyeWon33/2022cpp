//18_thread2.cpp
//스레드의 특성
// 1. pthread_create
// : 스레드를 생성하고, 스레드가 만들어져서 시작할 함수를 지정한다.
// 2. 스레드는 자신만의 스택을 가지고 있다
// 3. 모든 스레드는 같은 프로세스 내에서 동작하기 때문에 *데이터를 쉽게 공유*할 수 있다.

#include <iostream>
#include <pthread.h>
using namespace std;

//FILE* fp = fopen("a.txt", "r");

int sum = 0;

pthread_mutex_t g_mutex = PTHREAD_MUTEX_INITIALIZER;


// 원래 코드
/*
void *thread_routine(void *arg){
    printf("%s\n", (char *)arg);

    for (int i = 0; i < 1000000; ++i) {
        sum += 1;
    }

    return nullptr;
}
*/

//오직 한 개의 스레드만 메모리에 접근 가능하게 만듦
/*
void *thread_routine(void *arg){
    printf("%s\n", (char *)arg);

    for (int i = 0; i < 1000000; ++i) {
        

        //----------
        pthread_mutex_lock(&g_mutex);
        sum += 1;
        pthread_mutex_unlock(&g_mutex);
        //----------
        //임계 영역(Critical Section)
        // : 오직 한 개의 스레드만 접근 가능하도록 해야 한다.
        // - 상호 배제 (MuTual EXclusiton) : Mutex

    //값 제대로 안 나온 원인
    // : 두 개 이상의 스레드가 sum이라는 메모리에 연산을 동시에 수행할 경우, 레이스 컨디션이 발생한다.
    // > sum에 +1을 하는 연산은 원자적이지 않다.
    }

    return nullptr;
}
*/

//최대한 동기화 없이 수행 좋은 성능
void *thread_routine(void *arg){
    printf("%s\n", (char *)arg);

    int local = 0;
    for (int i = 0; i < 1000000; ++i) {
        local += 1;
    }
    //최종 결과에만 lock
    pthread_mutex_lock(&g_mutex);
    sum+=local;
    pthread_mutex_unlock(&g_mutex);

    return nullptr;
}
    
// 4. 프로세스가 처음 만들어졌을 때, main 함수를 실행하는 흐름을 '메일 스레드' 라고 부른다.
// 5. 메인 함수가 반환하면, 프로세스가 종료한다.
//   - 메인 함수의 반환은 프로세스 내의 모든 스레드가 종료된다.
// 6. pthread_hoin 함수를 통해 스레드의 종료까지 대기할 수 있다.

int main(){
    cout << "main thread start" << endl;
    pthread_t thread[2]; //스레드 핸들
    
    for(int i = 0; i < 2; ++i){
        // void* arg = static_cast<void *>((i==0) ? "A" : "B");

        const char* arg = i == 0 ? "A" : "B";

        pthread_create(&thread[i], nullptr, &thread_routine, (void *)arg);
    }

    // getchar(); //엔터 치면 종료?
    for(int i = 0; i < 2; ++i){
        pthread_join(thread[i], nullptr);
    }

    printf("sum : %d\n", sum);
    // 결과가 제대로 나오지 않는 이유를 이해하는 것이 중요하다.

}


//스레드는 프로세스 안에서 돈다. 그래서 서로의 메모리 영역 접근 가능
//동시에 여려 연산 같은 메모리에서 수행하면 원하지 않은 결과 나온다. - 하이젠 버그



//g++ 18_thread2.cpp -lpthread
