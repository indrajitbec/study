#include<iostream>
#include<set>
#include<vector>

using namespace std;
#define tr(container,it) \
    for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

int main()
{
/*
    set<int> s;
    for(int i =1; i <= 100;i++)
        s.insert(i);
    cout<<s.size()<<endl;

    s.insert(43);

    cout<<s.size()<<endl;

    for(int i=1;i<=100;i+=2)
        s.erase(i);

    cout<<s.size()<<endl;

    tr(s,it)
        cout<<*it<<endl;

    if(s.find(42) != s.end())
        cout<<"Present\n";
    else
        cout<<"Not Present\n";

    s.erase(s.find(18), s.find(90));

    tr(s,it)
        cout<<*it<<endl;
*/

    int data[10]= {5,2,3,4,3,6,4,2,1,10};
    set<int> s(data, data +10);
    vector<int> v1(s.begin(), s.end());

    tr(v1,it)
        cout<<*it<<endl;
}
