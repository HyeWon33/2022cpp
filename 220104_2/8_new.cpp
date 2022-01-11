#include <iostream>
using namespace std;


//동적 메모리 할당
//  - malloc / free

//전역변수 프로그램 시작할 때 초기화 해서 프로그램 끝날 때 까지 유지
// 장 : 누구나 쉽게 언제 어디서나 접근 가능. 단 : 의존성이 생긴다.
int add(int a, int b){
    return a + b + g; //add라는 함수 동작하기 위해서는 g 필요.. 
                      //재사용성 떨어진다. 의존성 생긴다. 
}
int g [100000] = {1, 3, 4};
//초기값 으로 초기화 된다. 실행 파일에 그 내용 다 저장되어 있어서 실행파일 용량에 영향
//전역변수는 수명이 프로그램 시작에서 끝까지 존재
//장점 : 언제 어디서든 쉽게 접근이 가능하다. 
//         - 복잡도를 낮출 수 있다.
//단점 : 함수가 전역 변수에 의존할 경우,
//          함수의 재사용성이 떨어진다.

void foo(){
    int a;
    //지역변수(auto 변수) 
    // - stack에 저장된다.
    // - foo함수가 실행될 때 생성되고, foo함수가 끝날 때 해지된다.
    //지역변수는 오버헤드 0
    // > 메모리 할당 해지의 비용이 거의 없다.

    static int b;
    //내부 정적 변수
    // - 전역 변수와 동일한 영역으로 관리됩니다.(데이터 영역)
    // > 할당된느 시점은 foo 함수가 처음 실행될 때 생성되고, 프로그램이 종료할 때까지 유지된다.
    // : 함수가 상태를 가져야 할때 사용한다.
}

#include <string.h>

//동적 메모리 할당
// - 힙(자유 영역)에 생성되는 변수 입니다.
//    > 개발자가 원하는 시점에 생성할 수 있고, 개발자가 원하는 시점에 파괴할 수 있습니다.
//   1) 메모리 누수의 위험성이 있다.
//   2) 성능 오버헤드가 있다.

/*
int main(){
    char str[] = "hello world show me the money";

    // strtok(str, " ");
    // printf("%s\n", p);

    for(char *p = strtok(str, " "); p != NULL; p = strtok(NULL, " "))
        printf("%s\n", p);

}
*/

//C언어 동적 메모리 할당 
/*
int main(){
    int *p = static_cast<int *>(malloc(sizeof(int)));
    *p = 20;
    cout << *p << endl;

    free(p);
}
*/

//C++은 동적 메모리 관련 연산자를 제공한다.
// new / delete

int main(){
    int *p = new int;
    
    delete p;
}


//1. malloc / free는 함수이지만, new / delete는 연산자 입니다.
//2. malloc은 메모리 크기를 인자로 전달하지만, new는 타입을 전달한다.
// 3. malloc은 void*를 반환하기 때문에, 캐스팅이 필요하지만, 
//    new는 전달 받은 타입의 주소로 반환하기 때문에 별도의 캐스팅이 필요하지 않다.
// 4. malloc은 free로 해지하지만, new는 delete를 통해 해지해야 합니다.

int main(){
    int *p = new int;
    
    delete p;

    int *arr = static_cast<int *>(malloc(sizeof(int) * 5));
    arr[0] = 10;
    cout << arr[0] << endl;
    free(arr);

    //int arr[5];
    arr = new int[5];
    //주의
    // - 연속된 메모리를 할당한 경우, delete에 대해서 배열 형태의 해지 연산을 사용해야 한다.
    delete[] arr;
}
