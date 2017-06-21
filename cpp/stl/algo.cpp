#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>

using namespace std;

#define tr(container,it) \
    for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

int main()
{
    vector<int> v1;
    vector<string> perm;
    for(int i=1;i <=4;i++)
        v1.push_back(i);

    do {
        ostringstream S;
        tr(v1,it)
            S<<*it<<" ";
        perm.push_back(S.str());
    } while(next_permutation(v1.begin(), v1.end()));

    tr(perm, it) {
        cout<<*it<<endl;
    }
}
