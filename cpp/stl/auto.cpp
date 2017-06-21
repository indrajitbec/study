#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int data[5] = {0,1,2,3,4};

    vector<int> v(data, data+5);

    for(i:v)
        cout<<i<<" ";
    cout<<endl;
}
