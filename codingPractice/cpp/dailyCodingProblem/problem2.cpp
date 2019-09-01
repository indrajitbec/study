// [Hard]
// This problem was asked by Uber.

// Given an array of integers, return a new array such that each element at index i of the new array is the 

// product of all the numbers in the original array except the one at i.

// For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24]. If our input was [3, 2, 1], the expected output would be [2, 3, 6].

// Follow-up: what if you can't use division?

// Questions: 
// 1. How big are the numbers ? overflow
// 2. result : long int ?
// 3. How many max numbers in the array ?

// Idea:

// 1st pass
//  temp = 1
// 0 - n-1
//  prod[i] = temp

//  temp *= arr[i] 

// 2nd pass
//  temp = 1
//  n-1 - 0
//  prod[i] *= temp; // right elements prod
//  temp *= arr[i]

// Time : 18m51s < 20

#include<iostream>
#include<vector>

using namespace std;

class ArrayProduct {
public:
    static vector<long int> exceptSelf(const vector<int> &nums) {
        if(nums.size() == 0) {
            return vector<long int>();
        }

        vector<long int> prod(nums.size());
        int temp = 1;
        for(int i = 0; i < nums.size(); i++) {
            // left product
            prod[i] = temp;
            temp *= nums[i];
        }

        temp = 1;

        for(int i = nums.size() -1; i >= 0; i--) {
            // right prod
            prod[i] *= temp;
            temp *= nums[i];
        }

        return prod;
    }
};


int main() {
    vector<int> input = {1, 2, 3, 4, 5};

    cout << "Input : ";
    for(auto x : input) {
        cout << x << " ";
    }
    cout << endl;

    cout << "Output :";
    for(auto x : ArrayProduct::exceptSelf(input)) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
