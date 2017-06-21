#include<iostream>
#include<string>
#include<thread>
#include<unistd.h>

using namespace std;

void message1() { sleep(100); cout<<"Message1"<<endl;}

int main()
{
    thread foo([]() {cout<<"Hello World\n";});

    thread th1(message1);

    foo.join();
    th1.join();
}
