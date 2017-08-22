#include <iostream>
#include <string>
#include <unordered_map>
#include <cstdlib>

using namespace std;

bool checkString (string str, int k)
{
    int len = str.length();

    if (len%k != 0)
        return false;

    unordered_map<string, int> mp;

    for(int i=0; i<len; i+=k) {
        mp[str.substr(i,k)]++;
    }

    if(mp.size() == 1)
        return true;

    if(mp.size() != 2)
        return false;

    for(auto i = mp.begin();
            i != mp.end(); i++)
        cout<<"key = "<<i->first<<", val = "<<i->second<<endl;

    if(mp.begin()->second == 1 ||
       mp.begin()->second == (len/k)-1)
    {
        return true;
    }


    return false;
}

int main(int argc, char *argv[])
{
    if(argc<3) {
        cout<<"Usage:%s <string> <k>"<<endl;
        exit(1);
    }

    if(checkString (argv[1], atoi(argv[2])))
        cout<<"Can Repitition"<<endl;
    else
        cout<<"Cannot be repitition"<<endl;
}
