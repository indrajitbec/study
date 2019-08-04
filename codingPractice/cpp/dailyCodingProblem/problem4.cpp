// Hard
// This problem was asked by Stripe.

// Given an array of integers, find the first missing positive integer in linear time and constant space. 
// In other words, find the lowest positive integer that does not exist in the array. The array can contain duplicates and negative numbers as well.

// For example, the input [3, 4, -1, 1] should give 2. The input [1, 2, 0] should give 3.

// You can modify the input array in-place.

// Idea :cycle sort technic
//  if arr.size() = n, then 1,2,3...n should be present in that case n+1 is output
// we can ignore arr[i] > n
// for i == 1 to n
// check if arr[arr[i-1]  != i 

#include<iostream>
#include<vector>

using namespace std;

class BoundedArray {
public:
    static int findFirstMissingPositive(vector<int> &nums) {
        if(nums.size() == 0) {
            return 1;
        }

        for(int i = 0; i < nums.size(); i++) {
            while(nums[i] > 0 && nums[i] <= nums.size() && nums[nums[i]-1] != nums[i]) {
                swap(nums[i], nums[nums[i]-1]);
            }
        }

        for(int i = 1; i <= nums.size(); i++) {
            if(nums[i-1] != i) {
                return i;
            }
        }
        return nums.size() + 1;
    }
};


int main() {

    vector<int> arr = {3, 4, -1, 1};

    cout << BoundedArray::findFirstMissingPositive(arr) << endl;;

    vector<int> arr2 = {1, 2, 0};

    cout << BoundedArray::findFirstMissingPositive(arr2) << endl;;

    return 0;
}
