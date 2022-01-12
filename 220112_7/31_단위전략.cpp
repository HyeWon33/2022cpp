 #include <iostream>
 using namespace std;


#if 0
template <typename T>
class List {
public:
    void push_front(const T& a){}
 };

 List<int> st;
 // 전역 변수
 //  : 스레드 안전하게 접근할 수 있어야 한다.
#endif

// 1. 동기화 여부를 인터페이스 기반 다른 클래스로 분리하자.
//  => 전략 패턴

struct Sync{
    virtual ~Sync(){}

    virtual void Lock() = 0;
    virtual void Unlock() = 0;
};

template <typename T>
class List {
    Sync* pSync = nullptr;
public:
    void SetSync(Sync* p){pSync = p;}
    void push_front(const T& a){
        pSync->Lock();
        cout << "데이터 삽입" << endl;
        pSync->Unlock();
    }
};

// 동기화 정책의 인터페이스를 구현하는 클래스를 만든다.
class MultiThread : public Sync{
public:
    void Lock() override{
        // mutex.lock();
        cout << "동기화 시작" << endl;
    }

    void Unlock() override{
        // mutex.unlock();
        cout << "종기화 종료" << endl;
    }
};

class SingleThread : public Sync {
public:
    void Lock() override { }
    void Unlock() override { }
};

List<int> st;

MultiThread t;


int main()
{
    // st.SetSync(new MultiThread);
    // st.SetSync(new SingleThread);
    st.SetSync(&t);

    st.push_front(10);
}

//동기화 정책은 런타임에 변할 필요 없다???
//pushfront 한번 호출 하니라 수백번 수만번 호출될 수 있다.