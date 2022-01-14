#include <iostream>
using namespace std;

// 반복자
// : Iterator Pattern 
// : 컨테이너 요소를 순회하는 객체
// > 중요하다.


template <typename T>
struct Node {
    T data;
    Node* next;

    Node(const T& a, Node* n)
        : data(a)
        , next(n)
    {
    }
};

template <typename T>
class SlistIterator{
    Node<T>* current;

public:
    SlistIterator(Node<T>* p = nullptr) : current(p){}

    inline SlistIterator& operator++(){
        current = current->next;
        return *this;
    }

    inline T& operator*(){ return current->data; }

    inline bool operator==(const SlistIterator& t){ return current == t.current; }
    inline bool operator!=(const SlistIterator& t){ return current != t.current; }
};

// 모든 컨테이너의 설계자는 자신의 처음과 끝 다음을 가르키는 반복자를 꺼내는연산을 제공해야 한다.
//  => begin() / end()
//  => 자신이 이터레이터 타입을 컨테이너 내부 타입의 이름을 통해 알려야 한다.
template <typename T>
class Slist {
    Node<T>* head;

public:
    using iterator = SlistIterator<T>;

    Slist()
        : head(nullptr)
    {
    }

    SlistIterator<T> begin() { return SlistIterator<T>(head); }
    SlistIterator<T> end() { return SlistIterator<T>(); }

    void push_front(const T& a) { head = new Node<T>(a, head); }

    const T& front() { return head->data; }
};

#include <list>

template <typename T1, typename T2>
T1 xfind(T1 first, T1 last, T2 value)
{
    while (first != last && *first != value)
        ++first;

    return first;
}

int main()
{
    Slist<int> s;
    s.push_front(10);
    s.push_front(20);
    s.push_front(30);

    // Slist<int>::iterator p = xfind(s.begin(), s.end(), 20);
    auto p = xfind(s.begin(), s.end(), 20); //auto
    if (p != s.end()) {
        cout << *p << endl;
    }
}

#if 0
int main()
{
    list<int> s;
    s.push_front(10);
    s.push_front(20);
    s.push_front(30);

    // SlistIterator<int> sp = s.begin();
    list<int>::iterator sp = s.begin();
    cout << *sp << endl;

    ++sp;
    cout << *sp << endl;

    int x[5] = { 1, 2, 3, 4, 5 };
    int* p = x;
    int* p2 = x + 1;

    ++p;
    if (p == p2) {
        cout << "같은 위치" << endl;
    }

    cout << *p << endl;
}
#endif

//여기 부분 밀렸다.

//auto는 많이 사용한다. 타입이 중요한 부분은 명시적으로 쓰고 나머지는 그냥 auto쓴다.