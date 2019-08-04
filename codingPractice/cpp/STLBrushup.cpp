#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;
void vectorDemo()
{
        vector<int> A = {11, 2, 3, 14};

    std::cout << A[1] << endl;

    sort(A.begin(), A.end()); // O(NlogN)

    // 2,3, 11, 14
    bool present = binary_search(A.begin(), A.end(), 3); // O(logN) true 
    present = binary_search(A.begin(), A.end(), 4); // false

    A.push_back(100);
    present = binary_search(A.begin(), A.end(), 100);

    A.push_back(100);
    A.push_back(100);
    A.push_back(100);
    A.push_back(100);
    A.push_back(123);

    // 2,3,11,14, 100, 100,100,100,100,123

    auto it1 = lower_bound(A.begin(), A.end(), 100); // >=
    vector<int>::iterator it2 = upper_bound(A.begin(), A.end(), 100); // >

    cout << *it1 << " " << *it2 << endl;

    cout << it2 - it1 << endl; // 4

    sort(A.begin(), A.end(), [](const int &x, const int &y){ return x > y;});

    for(auto x : A) {
        cout <<x<<" ";
    }
    cout<<endl;

    for(auto &x : A) {
        x++;
    }
    cout<<endl;

    for(auto x : A) {
        cout <<x<<" ";
    }
    cout<<endl;
}

void setDemo()
{
    set<int> S;

    S.insert(1);
    S.insert(2);
    S.insert(-1);
    S.insert(-10);

    for(auto x : S) {
        cout << x << " ";
    }
    cout << endl;

    // -10, -1, 1, 2

    auto it = S.find(-1);

    if(it == S.end()) {
        cout << " not present" << endl;
    } else {
        cout << *it << " preset " << endl;
    }

    auto it2 = S.upper_bound(-1);
    auto it3 = S.upper_bound(0);

    cout << *it2 << " " << *it3 << endl;

    auto it4 = S.upper_bound(2);
    if(it4 == S.end()) {
        cout << "oops no numer greater than 2 found" << endl;
    }
}

int main() {

    setDemo();

    return 0;
}