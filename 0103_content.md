# 2022cpp

# 20220103 수업


1. vscode 설치

2. clang 설치

   - 2번째 체크
   - cmd -> clang++ 입력 ->clang++: error: no input files 나오면 잘~ 설치된거다.

3. 윈도우 -> 제어판 -> 프로그램 및 기능 -> windows 기능 켜기/끄기 -> Linux용 Windows 하위 시스템 체크 -> 확인 -> 재부팅

4. Microsoft Store -> ubuntu 20.04 LTS 다운 -> 실행

   - 입력 명령어

   - sudo apt update

   - sudo apt install g++ -y (윈도우 clang 리눅스 g++) (✔개발환경 잘 정리하고 쓰고)

   - g++ 입력 -> g++: error: no input files 나오면 잘~ 설치된거다.

   - mkdir 220103

   - cd 220103

   - touch 1.cpp

   - code 1.cpp

   - C/C++ Extension 설치 

   - ~~~c++
     #include <stdio.h>
     
     int main(){
         printf("Hello, C");
     }
     ~~~

   - Terminal -> New Terminal

     - 만약에 터미널이 remote(우분투) 아니고 C 면 vscode 끄고 code 1.cpp쳐서 켜서 해보기

5. 실행

   1. 컴파일 방법
   2. g++ 1.cpp
   3. clang++ 1.cpp
   4. 실행방법 
   5. ./a.out : a.out으로 이름 지정하지 않은 컴파일 파일 저장된다. a.out그냥 이렇게 실행 놉! 현재 디렉토리 path에 들어있지 않아서 현재 디렉토리 의미인 ./를 앞에 쓴다.
   6. ./a.exe




https://github.com/yoondev-classroom/cpp_220103.git



22년 01월 03일 파일 만든 순서

1. 1.cpp
2. 1_namespace.cpp
3. 1_namespace2.cpp
4. 1_namespace3.cpp
5. 2_iostream.cpp
6. 2_iostream2.cpp
7. 3_variable.cpp
8. 3_variable2.cpp
9. 3_variable3.cpp
10. 4_string.cpp
11. 5_function.cpp
12. 5_function2.cpp
13. 5_function3.cpp





