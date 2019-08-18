// [Medium]
// This problem was asked by Facebook.

// Given the mapping a = 1, b = 2, ... z = 26, and an encoded message, 
// count the number of ways it can be decoded.

// For example, the message '111' would give 3, 
// since it could be decoded as 'aaa', 'ka', and 'ak'.

// You can assume that the messages are decodable. For example, '001' is not allowed.

#include<iostream>
#include<string>

using namespace std;

class Encoding {
public:

    static int CountWays(string str) {
        
        int  prev = 1, prev_prev = 1;

        for(int i=2; i<=str.length(); i++) {
            int curr = 0;
            if(str[i-2]=='1' || 
               (str[i-2] == 2 && str[i-1] >= '0' && str[i-1] <='6')) {
                   curr = prev_prev;
            }
            if(str[i-1] != '0') {
                curr += prev;
            }
            prev_prev = prev;
            prev = curr;
        }
        return prev;
    } 
};

int main() {
    cout << Encoding::CountWays("111") << endl;
    cout << Encoding::CountWays("123") << endl;
    return 0;
}