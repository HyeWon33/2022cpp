#include <iostream>
using namespace std;

#if 0
class Cursor {
private:
    Cursor() { }
    Cursor(const Cursor&) = delete;
    Cursor& operator=(const Cursor&) = delete;

    static Cursor* sInstance;

public:
    static Cursor& GetInstance()
    {
        if (sInstance == nullptr)
            sInstance = new Cursor;

        return *sInstance;
    }
};

// 정적 멤버 변수는 반드시 외부 선언이 필요합니다.
Cursor* Cursor::sInstance = nullptr;

int main()
{
    Cursor& c1 = Cursor::GetInstance();
    Cursor& c2 = Cursor::GetInstance();

    cout << &c1 << endl;
    cout << &c2 << endl;
}
#endif

//문제점 
//커서라는 객체데 대한 부분을 싱글톤은 전역객체 모든 스레드가 공유 그래서 getinstance 가 스레드 안전하지 않다.
//그래서 스레드 안전하게 만들어야 한다. 그래서 mutex.

#if 0
#include <mutex>

class Cursor{
private:
    Cursor() {}
    Cursor(const Cursor&) = delete;
    Cursor& operaotr=(const Cursor&) = delete;
    
    static Cursor* sInstance;
    static std::mutex sLock;
public:
    // 임계 영역 안에서 예외가 발생하면, unlock이 호출되지 않는다.
    // > 데드락의 위험성이 있다.
    //  => 예외 안정하게 사용하기 위해, RAII를 이용해야 ㅎ나다.
    //   RAII(Resource Acqusion is Initialize)
    static Cursor& GetInstance;{
        sLock.lock();
        if (sInstatnce == nullptr) sInstance = new Cursor;
        sLock.unlock();
        return *sInstance;
    }
};

// 정적 멤버 변수는 반드시 외부 선언이 필요합니다.
Cursor* Cursor::sInstance = nullptr;
std::mutex Cursor::sLock;

int main()
{
    Cursor& c1 = Cursor::GetInstance();
    Cursor& c2 = Cursor::GetInstance();

    cout << &c1 << endl;
    cout << &c2 << endl;
}
#endif

//new 메모리 부족하면 예외. 다음 문장 실행하지 않고 빠져나와 버린다.
//빠져나오지 못하고 무한정 기다리고 있을 수도 있다.(데드락? 배드락?) 반드시 나오게 보장 해야? 그걸 어떻게 하는지 이해해야


#if 0
#include <mutex>

class AutoLock{
    std::mutex& mLock;
public:
    inline AutoLock(std::mutex& m) : mLock(m){ mLock.lock(); }

    inline ~AutoLock() { mLock.unlock(); }
};

class Cursor{
private:
    Cursor() {}
    Cursor(const Cursor&) = delete;
    Cursor& operaotr=(const Cursor&) = delete;
    
    static Cursor* sInstance;
    static std::mutex sLock;
public:
    // 임계 영역 안에서 예외가 발생하면, unlock이 호출되지 않는다.
    // > 데드락의 위험성이 있다.
    //  => 예외 안정하게 사용하기 위해, RAII를 이용해야 ㅎ나다.
    //   RAII(Resource Acqusion is Initialize)
    /*
    static Cursor& GetInstance;{
        sLock.lock();
        if (sInstatnce == nullptr) sInstance = new Cursor;
        sLock.unlock();
        return *sInstance;
    }
    */

    static Cursor& GetInstance;{
        AutoLock al(sLock);
        
        if (sInstatnce == nullptr) sInstance = new Cursor;
        
        return *sInstance;
    }
};

// 정적 멤버 변수는 반드시 외부 선언이 필요합니다.
Cursor* Cursor::sInstance = nullptr;
std::mutex Cursor::sLock;

int main()
{
    Cursor& c1 = Cursor::GetInstance();
    Cursor& c2 = Cursor::GetInstance();

    cout << &c1 << endl;
    cout << &c2 << endl;
}
#endif


//이미 표준라이브러리에 있다고??
//std::lock_guard<std::mutex> al(sLock);
//오토 락 만들어 쓸 필요 없다.


#include <mutex>



class AutoLock{
    std::mutex& mLock;
public:
    inline AutoLock(std::mutex& m) : mLock(m){ mLock.lock(); }

    inline ~AutoLock() { mLock.unlock(); }
};

class Cursor{
private:
    Cursor() {}
    Cursor(const Cursor&) = delete;
    Cursor& operaotr=(const Cursor&) = delete;
    
    static Cursor* sInstance;
    static std::mutex sLock;
public:
    // 임계 영역 안에서 예외가 발생하면, unlock이 호출되지 않는다.
    // > 데드락의 위험성이 있다.
    //  => 예외 안정하게 사용하기 위해, RAII를 이용해야 ㅎ나다.
    //   RAII(Resource Acqusion is Initialize)
    
    //------
    // C++11 /14
    static Cursor& GetInstance(){
        static Cursor* instance = new Cursor;
        return *instance;
    }
    //------

    static Cursor& GetInstance(){
        std::lock_guard<std::mutex> al(sLock);
        
        if (sInstatnce == nullptr) sInstance = new Cursor;
        
        return *sInstance;
    }
};

// 정적 멤버 변수는 반드시 외부 선언이 필요합니다.
Cursor* Cursor::sInstance = nullptr;
std::mutex Cursor::sLock;

int main()
{
    Cursor& c1 = Cursor::GetInstance();
    Cursor& c2 = Cursor::GetInstance();

    cout << &c1 << endl;
    cout << &c2 << endl;
}


//고민할 필요 없이 규칙 2번 사용?
