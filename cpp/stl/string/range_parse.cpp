#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
#include<map>

using namespace std;

void parse_range(string input, std::vector<int> & v)
{
    std::size_t found = input.find_first_of("-;");
    std::size_t start = 0, offset = 0;
    int prev = -1;
    static std::map< std::string, vector<int> > range_map;
    typeof(range_map.begin()) rit = range_map.find(input);

    if(rit != range_map.end()) {
        v.assign(rit->second.begin() +1, rit->second.end()-1);
        cout<<"Cache\n";
        return;
    }

    while(1) {
        offset = found - start;
        
        std::string temp = input.substr(start, offset);
        int l = atoi(temp.c_str());

        if(input[found] != '-') {
            if(prev == -1) {
                v.push_back(l);
            }
            else {
                while(prev <= l)
                    v.push_back(prev++);
                prev = -1;
            }
        }
        else {
            prev = l;
        }
        if(found == std::string::npos)
            break;

        start = found+1;
        found = input.find_first_of("-;", start);
    }
    range_map[input] = v;
}

void print_vec(vector<int> & v)
{
    cout<<"numbers :";
    for(typeof(v.begin()) it = v.begin(); it != v.end(); it++)
        cout<<*it<<" ";
    cout<<endl; 
}

int main()
{
    vector<int> v;
    string input;

    //parse_range("0;2-4;7;10-12;25", v);
    //print_vec(v);
    
    cout<<"Enter range str: ";
    cin>>input;
    v.resize(0);
    parse_range(input, v);
    print_vec(v);
}
