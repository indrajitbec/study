// This problem was asked by Airbnb.

// Given a list of integers, write a function that returns the largest sum of non-adjacent numbers. 
// Numbers can be 0 or negative.

// For example, [2, 4, 6, 2, 5] should return 13, since we pick 2, 6, and 5. [5, 1, 1, 5] should return 10, since we pick 5 and 5.

// Follow-up: Can you do this in O(N) time and constant space?

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// time O(N), space O(N)
class LargestNonAdjacentSum {
public:
    static int find(vector<int> &nums) {
        int n = nums.size();


        vector<int> dp(n+1);
        dp[0] = 0;
        dp[1] = nums[0];
        if(n < 2) {
            return dp[n];
        }
        dp[2] = max(nums[0],nums[1]);


        for(int i = 3; i <= n; i++) {
            dp[i] = max(max(dp[i-2] + nums[i-1], dp[i-1]), nums[i-1]);
        }
        return dp[n];
    }
};

int main() {
    vector<int> arr = {2, 4, 6, 2, 5};

    cout << LargestNonAdjacentSum::find(arr) << endl;
    return 0;
}
