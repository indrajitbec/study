#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define all(c) c.begin(),c.end()
#define tr(container, it)	\
                for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

template<typename T>
void print_container(T& c, string desc = "") 
{
    cout<<desc<<endl;
    tr(c,it) {
        cout<<*it<<" ";
    }
    cout<<endl;
}

int main()
{
    int data[10]= {2,4,5,3,8,9,7,6,1,10};
    vector<int> v1(data, data + (sizeof(data)/sizeof(data[0])));

    print_container(v1, "Unsorted");

    cout<<v1.size()<<endl;
    v1.push_back(-3);
    cout<<v1.size()<<endl;

    print_container(v1, "push_back");

    reverse(all(v1));
    print_container(v1, "reverse");

    sort(all(v1));
    print_container(v1, "sorted");

    vector<int> v2(v1.begin() + 3, v1.begin() + 7);

    print_container(v2, "sorted");
}
