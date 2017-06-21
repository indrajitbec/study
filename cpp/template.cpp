#include<iostream>
using namespace std;

class A {
	public:
    int a;
    void print() const {cout<<a<<endl;};
};
bool operator > (const A &a, const A &b) { return (a.a > b.a);}

template <typename T>
const T& get_max(const T& a, const T& b)
{
    return (a>b)? a:b;
}

int main()
{
    A a,b;
    a.a = 5;
    b.a = 3;

    a.print();
    b.print();
    get_max(a,b).print();
}
