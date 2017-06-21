#include<iostream>
#include<array>

using namespace std;

int main()
{
    try
    {
        array<int , 5> A = {1,2,3,4,5};

        for(i:A)
            cout<<i<<" ";
        cout<<endl;

        for(auto it=A.rbegin(); it!= A.rend(); it++)
            cout<<*it<<" ";
        cout<<endl;

        cout<<A[4]<<endl;
        cout<<A.at(5)<<endl;
    }
    catch(const out_of_range &r)
    {
        cout<<"Something wrong: "<<r.what()<<endl;
    }

    return 0;
    
}
