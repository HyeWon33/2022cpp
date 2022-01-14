/*
#include <iostream>
using namespace std;

#include <cstring>

#include <arpa/inet.h>
#include <netinet/in.h> // sockaddr_in
#include <sys/socket.h>
#include <sys/types.h>

#include <unistd.h>

class Address{
    sockaddr_in addr;
public:
    Address(const char* ip, short port){
        memset(&addr, 0, sizeof addr);
        addr.sin_family = AF_INET;
        addr.sin_port = htons(port);
        addr.sin_addr.s_addr = inet_addr(ip);
    }
};

class Socket{
    int csock;
public:
    Socket(int type){ csock = socket(PF_INET, type, 0); }

};

int main() {
    // 1. Socket
    int csock = socket(PF_INET, SOCK_STREAM, 0);
    // Socket sock(SOCK_STERAM);

    // 2. 주소 지정
    //  => IP / PORT
    struct sockaddr_in addr = {
        0,
    };
    addr.sin_family = AF_INET;
    addr.sin_port = htons(80); // 빅엔디안으로 지정해야 한다. host to network
    addr.sin_addr.s_addr = inet_addr("142.250.207.46");
    // Address addr("142.250.207.46", 80)

    // 3. connect
    int ret = connect(csock, (struct sockaddr*)&addr, sizeof addr);
    if(ret == -1){
        perror("connect()\n");
        return -1;
    }

    char str[] = "GET\n";
    // 4. GET 명령을 서버에 전송한다.
    write(csock, str, strlen(str));

    // 5. read를 통해서 서버로부터 전송된 데이터를 화면에 출력한다.
    char buf[128];
    int len;
    while((len = read(csock, buf, sizeof buf)) > 0){
        printf("%s", buf);
    }

    // 6. 연결을 종료한다.
    close(csock);

}

//디도스 공격은 불법.. 막힌다.. 남의 서버에 하는거 아니다.

*/

#include <iostream>
using namespace std;

#include <arpa/inet.h>
#include <netinet/in.h> // sockaddr_in
#include <sys/socket.h>
#include <sys/types.h>

#include <string.h>
#include <unistd.h>

class Address {
    sockaddr_in addr;

public:
    Address(const char* ip, short port)
    {
        memset(&addr, 0, sizeof addr);
        addr.sin_family = AF_INET;
        addr.sin_port = htons(port);
        addr.sin_addr.s_addr = inet_addr(ip);
    }

    const sockaddr* GetRawAddress() const
    {
        return reinterpret_cast<const sockaddr*>(&addr);
    }
};

class Socket {
    int csock;

public:
    Socket(int type) { csock = socket(PF_INET, type, 0); }

    ~Socket() { close(csock); }

    void Connect(const Address& addr)
    {
        connect(csock, addr.GetRawAddress(), sizeof(sockaddr_in));
    }

    int Write(const char* data, int len)
    {
        return write(csock, data, len);
    }

    int Read(char* data, int len)
    {
        return read(csock, data, len);
    }
};

// Facade Pattern
// : 프로그램을 하는데 필요한 클래스와 절차를 단순화 시켜주는 상위 개념의 클래스를 제공하자.

class HTMLDownloader {
    Socket sock;
    Address addr;

public:
    HTMLDownloader(const char* ip)
        : sock(SOCK_STREAM)
        , addr(ip, 80)
    {
    }

    void Start()
    {
        sock.Connect(addr);
        char str[] = "GET\n";
        sock.Write(str, strlen(str));

        char buf[128];
        int len;
        while ((len = sock.Read(buf, sizeof buf)) > 0)
            write(1, buf, len);
    }
};

int main()
{
    HTMLDownloader downloader("142.250.207.46");
    downloader.Start();
}

#if 0
int main()
{
    Socket sock(SOCK_STREAM);
    Address addr("142.250.207.46", 80);

    sock.Connect(addr);

    char str[] = "GET\n";
    sock.Write(str, strlen(str));

    char buf[128];
    int len;
    while ((len = sock.Read(buf, sizeof buf)) > 0)
        write(1, buf, len);
}
#endif

#if 0
int main()
{
    // 1. Socket
    int csock = socket(PF_INET, SOCK_STREAM, 0);
    // Socket sock(SOCK_STREAM);

    // 2. 주소 지정
    //  => IP / PORT
    struct sockaddr_in addr = {
        0,
    };
    addr.sin_family = AF_INET;
    addr.sin_port = htons(80); // 빅엔디안으로 지정해야 합니다.
    addr.sin_addr.s_addr = inet_addr("142.250.207.46");
    // Address addr("142.250.207.46", 80);

    // 3. connect
    int ret = connect(csock, (struct sockaddr*)&addr, sizeof addr);
    if (ret == -1) {
        perror("connect()");
        return -1;
    }
    // sock.Connect(addr);

    char str[] = "GET\n";
    // 4. GET 명령을 서버에 전송합니다.
    write(csock, str, strlen(str));

    // 5. read를 통해서 서버로부터 전송된 데이터를 화면에 출력합니다.
    char buf[128];
    int len;
    while ((len = read(csock, buf, sizeof buf)) > 0) {
        write(1, buf, len);
    }

    // 6. 연결을 종료합니다.
    close(csock);
}
#endif