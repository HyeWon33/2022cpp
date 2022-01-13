#include <iostream>
using namespace std;

// 단일 연결 리스트 기반 컨테이너를 만들어 본다.

//원래 c++은 앞이 소문자
struct Node{
    int data;
    Node* next;

    Node(int a, Node* n) : data(a), next(n){}
};

class Slist{
    Node* head;

public:
    Slist() : head(nullptr){}

    void push_front(int a){ head = new Node(a, head); }

    int front(){ return head->data;}
};

int main(){
    Slist s;
    s.push_front(10);
    s.push_front(20);
    s.push_front(30);

    int n = s.front();
    cout << n << endl;
}