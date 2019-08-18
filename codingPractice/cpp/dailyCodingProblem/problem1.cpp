// [Easy]
// This problem was recently asked by Google.

// Given a list of numbers and a number k, return whether any two numbers from the list add up to k.

// For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.

// Bonus: Can you do this in one pass?

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class PairSum {
    public:
        bool static hasPair(vector<int> & arr, int k) {
            int n = arr.size();
            int l = 0, r = n-1;

            sort(arr.begin(), arr.end());

            while(l < r) {
                int sum = arr[l] + arr[r];
                if(sum == k) {
                    return true;
                } else if(sum < k) {
                    l++;
                } else {
                    r--;
                }
            }
            return false;
        }
};

int main() {

    vector<int> arr = {10, 15, 3, 7,-1};
    int num = 17;
    if(PairSum::hasPair(arr, num)) {
        cout << "sum found " << num << endl;
    } else {
        cout << "sum not found " << num << endl;
    }

    num = -17;
    if(PairSum::hasPair(arr, num)) {
        cout << "sum found " << num << endl;
    } else {
        cout << "sum not found " << num << endl;
    }

    vector<int> empty;
    num = 17;
    if(PairSum::hasPair(empty, num)) {
        cout << "sum found " << num << endl;
    } else {
        cout << "sum not found " << num << endl;
    }

    num = 13;
    if(PairSum::hasPair(arr, num)) {
        cout << "sum found " << num << endl;
    } else {
        cout << "sum not found " << num << endl;
    }
    
    return 0;
}