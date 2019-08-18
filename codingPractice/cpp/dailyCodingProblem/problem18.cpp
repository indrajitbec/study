// [Hard]
// This problem was asked by Google.

// Given an array of integers and a number k, where 1 <= k <= length of the array, 
// compute the maximum values of each subarray of length k.

// For example, given array = [10, 5, 2, 7, 8, 7] and k = 3, we should get: [10, 7, 8, 8], since:

// 10 = max(10, 5, 2)
// 7 = max(5, 2, 7)
// 8 = max(2, 7, 8)
// 8 = max(7, 8, 7)
// Do this in O(n) time and O(k) space. 
// You can modify the input array in-place and you do not need to store the results.
// You can simply print them out as you compute them.

#include<iostream>
#include<deque>
#include<vector>

using namespace std;

class WindowMax {
public:
    static vector<int> GetWindowsMax(vector<int> & arr, int K) {
        int n = arr.size();
        if(n == 0|| K < 1|| K >=n ) {
            return vector<int>();
        }

        deque<int> win;
        vector<int> res(n-K+1);

        int i = 0;
        for(; i<K; i++) {
            while(!win.empty() && arr[i] > arr[win.back()]) {
                win.pop_back();
            }
            win.push_back(i);
        }

        int j = 0;
        res[j++] = arr[win.front()];

        for(;i<n; i++) {
            while(!win.empty() && win.front() <= i-K) {
                win.pop_front();
            }
            
            while(!win.empty() && arr[i] > arr[win.back()]) {
                win.pop_back();
            }
            win.push_back(i);
            res[j++]=arr[win.front()];
        }

        return res;
    }
};


int main() {
    vector<int> arr = {10, 5, 2, 7, 8, 7};

    auto res = WindowMax::GetWindowsMax(arr, 3);

    for(auto item : res) {
        cout << item <<" ";
    }
    cout<<endl;

    vector<int> arr1;
    auto res1 = WindowMax::GetWindowsMax(arr1, 3);

    if(res1.empty()) {
        cout << "nil result" <<endl;
    }
    return 0;
}