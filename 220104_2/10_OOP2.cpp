#include <iostream>
using namespace std;

//Stack을 만들어 보자.
// - 우선순위 큐
//   : 데이터가 들어간 순서 상관 없이 데이터가 큰 것 부터 나온다.
//   : 스택 - LIFO 
//     큐 - FIFO

// 1. 전역 변수 / 함수를 이용한 스택
/*
int buff[10];
int  idx = 0; 
//스택에 데이터 넣는거 psuh 꺼내는거 pop

//push
void push(int v){
    buff[idx++] = v;
}
//pop
int pop(){
    return buff[--idx];
}

int main(){
    push(10);
    push(20);

    cout << pop() << endl; //20
    cout << pop() << endl; //10
}
*/

//2. Stack 타입을 설계해봅시다.
/*
struct Stack{
    int buff[10];
    int idx;
};

//push
void push(Stack *s, int v){
    s->buff[(s->idx)++] = v;
}
//pop
int pop(Stack *s){
    return s->buff[--(s->idx)];
}

Stack s1;
int main(){
    Stack s2;
    //초기화 필요
    s1.idx = 0;
    s2.idx = 0;

    push(&s1, 10);
    push(&s2, 20);

    cout << pop(&s1) << endl; //10
    cout << pop(&s2) << endl; //20
}
*/

//3. 상태를 나타내는 데이터와 상태를 조작하는 함수를 묶자.
/*
struct Stack{
    //멤버 변수(데이터)
    int buff[10];
    int idx;

    //멤버 함수
    // - 멤버 데이터에 접근하는 함수
    // > 명시적인 함수 인자로 Stack*을 받을 필요가 없습니다.
    void init(){
        idx = 0;
    }

    //push
    void push(int v){
        buff[idx++] = v;
    }
    //pop
    int pop(){
        return buff[--idx];
}
};

Stack s1;
int main(){
    Stack s2;
    //초기화 필요
    // s1.idx = 0;
    // s2.idx = 0;
    s1.init();
    s2.init();

    s1.push(10); //<- push(&s1, 10);
    s2.push(20);

    // s1.idx = 10; //외부에서 함부로 조작되면 stack 망한다.

    cout << s1.pop() << endl; //<-pop(&s1), 10
    cout << s2.pop() << endl; //20
}
*/

//4. 구조체 내부의 데이터를 외부에서 함부로 조작할 수 없도록 정보 은닉이 필요.
// => 접근 지정자
/*
struct Stack{
private:
    //멤버 변수(데이터)
    int buff[10];
    int idx;

public:
    //멤버 함수
    // - 멤버 데이터에 접근하는 함수
    // > 명시적인 함수 인자로 Stack*을 받을 필요가 없습니다.
    void init(){
        idx = 0;
    }

    //push
    void push(int v){
        buff[idx++] = v;
    }
    //pop
    int pop(){
        return buff[--idx];
}
};

//private는 구조체 내부에서만 수정 가능
//구조체는 접근 지정자 사용하지 않을 경우, 기본적으로 public이 된다.
// => class
//     기본 접근 지정이 private 입니다.

//struct와 class의 차이점은 기본 접근지정자가 다르다.
//class는 정보 은닉 목적

Stack s1;
int main(){
    Stack s2;
    //초기화 필요
    // s1.idx = 0;
    // s2.idx = 0;
    s1.init();
    s2.init();

    s1.push(10); //<- push(&s1, 10);
    s2.push(20);

    // s1.idx = 10; //외부에서 함부로 조작되면 stack 망한다.

    cout << s1.pop() << endl; //<-pop(&s1), 10
    cout << s2.pop() << endl; //20
}
*/


//5. 생성자 함수를 도입한다.
// 생성자(Constructor)
//   - 함수 이름이 클래스 이름과 동이랗고, 반환 타입을 표기하지 않습니다.
//    > 객체가 생성되면 자동으로 호출한다.

/*
class Stack{
private:
    //멤버 변수(데이터)
    int buff[10];
    int idx;

public:
    Stack(){
        cout << "Stack()" << endl;
        idx = 0;
    }

    void init(){
        idx = 0;
    }

    //push
    void push(int v){
        buff[idx++] = v;
    }
    //pop
    int pop(){
        return buff[--idx];
}
};

//private는 구조체 내부에서만 수정 가능
//구조체는 접근 지정자 사용하지 않을 경우, 기본적으로 public이 된다.
// => class
//     기본 접근 지정이 private 입니다.

//struct와 class의 차이점은 기본 접근지정자가 다르다.
//class는 정보 은닉 목적

Stack s1;
int main(){
    Stack s2;
    //초기화 필요
    // s1.idx = 0;
    // s2.idx = 0;
    // s1.init();
    // s2.init();
    //생성자 만들어서 여기서 초기화 필요없다.

    s1.push(10); //<- push(&s1, 10);
    s2.push(20);

    // s1.idx = 10; //외부에서 함부로 조작되면 stack 망한다.

    cout << s1.pop() << endl; //<-pop(&s1), 10
    cout << s2.pop() << endl; //20
}
*/

//6. 사용자가 Stack의 크기를 결정할 수 있도록 한다.
// > 생성자는 인자를 가져도 되고, 인자를 가지지 않아도 된다.
// 생성자는 오버로딩이 가능하다.
//7. 더이상 객체를 사용하지 않을 때, 객체가 파괴되는 시점에 호출되는 함수 있다.
// > 소멸자(Destructor)
// - 함수 이름은 ~클래스 이름() 입니다.
// - 반환 타입을 표기하지 않습니다.
// - 인자를 가질 수 없습니다.
// - 객체가 파괴되는 시점에 수행됩니다.
class Stack{
private:
    //멤버 변수(데이터)
    int *buff;
    int idx;

public:
    //Stack s1;
    
    //인자 없는 생성자
    /*
    Stack(){
        cout << "Stack()" << endl;
        idx = 0;
    }
    */

    //Stack s2{10}
    //Stack s2(10)
    //Stack s1;
    Stack(int sz = 10){
        idx = 0;
        buff = new int[sz]; //사용자가 전달한 크기 만큼 버퍼를 할당한다.
    }

    ~Stack(){
        delete[] buff;
    }

    void init(){
        idx = 0;
    }

    //push
    void push(int v){
        buff[idx++] = v;
    }
    //pop
    int pop(){
        return buff[--idx];
}
};

Stack s1;
int main(){
    Stack s2(100);
    Stack s3{100};

    s1.push(10); 
    s2.push(20);

    cout << s1.pop() << endl; //<-pop(&s1), 10
    cout << s2.pop() << endl; //20
}







//g++ 10_OOP2.cpp c++12