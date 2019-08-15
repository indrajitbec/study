#include<iostream>
#include<string>
#include<vector>
#include<set>

using namespace std;

class Solution {
private:
    int fact(int n) {
        static vector<int> f(10,-1);
        if(n==0) return 1;
        if(n==1) {
            f[n-1] = 1;
            return f[n-1];
        }
        
        if(f[n-1]!= -1) {
            return f[n-1];
        }
        
        f[n-1] = n * fact(n-1);
        return f[n-1];
    }
public:
    string getPermutation(int n, int k) {
        string res;
        
        if(n<=0||k<=0) {
            return res;
        }
        set<int> nums;
        for(int i=1; i<=n; i++) {
            nums.insert(i);
        }
        // make 0 based index
        k--;
        while(!nums.empty()) {
            int comb = fact(n-1);
            
            int index = k/comb;
            int digit = *std::next(nums.begin(), index);
            res += to_string(digit);
            nums.erase(digit);
            
            k = k % comb;
            n--;
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.getPermutation(3,3) << endl;
    cout << s.getPermutation(3,2) << endl;
    return 0;
}