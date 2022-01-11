#include <stdio.h>

#if 0
struct AAA
{
};
struct BBB
{
};

int main(){
    printf("%ld\n", sizeof(struct AAA));
    printf("%ld\n", sizeof(struct BBB));
}
#endif

//구조체는 데이터 중심
//C에서 구조체에 데이터 없어서 크기 출력하면 0이다. 
//C++은 존재한다고 1출력된다.

//구조체 얼라이언트 패딩
// 구조체 정렬 크기 조절..?

#if 0
struct AAA
{
    int a;
    char b;
    double c;
};
struct BBB
{
    char a;
    double b;
    int c;
};

int main(){
    printf("%ld\n", sizeof(struct AAA)); //16 데이터를 4바이트 단위로 접근
    printf("%ld\n", sizeof(struct BBB)); //24
}
#endif


struct AAA
{
    int a;
    char b;
    double c;
};

// ex) 보내고 싶은거 : 0x123456
// 빅엔디안 : [0x12][0x34][0x56]
// 리틀엔디안 : [0x56][0x34][0x12]
// 보잘 것 없는 일로 싸우는 애들 : 엔디안
// 네트워트 통해 데이터 보낼 때 빅엔디안으로 보내자는 약속~

struct BBB
{
    char a;
    double b;
    int c;
} __attribute__((aligned(1), packed));//특별한 목적 아니면 안 쓴다. c

int main(){
    printf("%ld\n", sizeof(struct AAA)); 
    printf("%ld\n", sizeof(struct BBB)); 
}



//gcc 23_virtual2.c
