// [Hard]
// This problem was asked by Amazon.

// Given an integer k and a string s, 

// find the length of the longest substring that contains at most k distinct characters.

// For example, given s = "abcba" and k = 2, 
// the longest substring with k distinct characters is "bcb".

#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

class LongestDistinctSubString {
public:

    static int findLongest(string str, int k) {
        unordered_map<char, int> cfreq;

        int wStart=0;
        int n = str.length();
        int maxLen = 0;

        for(int wEnd=0; wEnd < n; wEnd++) {
            cfreq[str[wEnd]]++;

            while(cfreq.size()> k) {
                char left = str[wStart];
                cfreq[left]--;
                if(cfreq[left]==0) {
                    cfreq.erase(left);
                }
                wStart++;
            }
            maxLen = max(maxLen, wEnd-wStart+1);
        }
        return maxLen;
    }
};

int main() {
    cout << LongestDistinctSubString::findLongest("abcba",2) << endl;
}