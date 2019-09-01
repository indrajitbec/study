// [Easy]
// This problem was asked by Amazon.
// 
// Run-length encoding is a fast and simple method of encoding strings. 
// The basic idea is to represent repeated successive characters as a single count and character. 
// For example, the string "AAAABBBCCDAA" would be encoded as "4A3B2C1D2A".
// 
// Implement run-length encoding and decoding. 
// You can assume the string to be encoded have no digits and consists solely of alphabetic characters. 
// You can assume the string to be decoded is valid.

#include<iostream>
#include<string>

using namespace std;

class RunLengthEncoding {
public:
    static string Encode(string str) {
        int n = str.length();
        if(n==0) return "";
        wchar_t prev = str[0];
        int count = 1;
        string out;

        for(int i = 1; i<n ; i++) {
            if(prev != str[i]) {
                out += to_string(count);
                out += prev;
                count = 0;
            }
            prev = str[i];
            count++;
        }

        out += to_string(count);
        out += prev;
        return out;
    }
};

// For example, the string  would be encoded as .

int main() {

    cout << RunLengthEncoding::Encode("AAAABBBCCDAA") << endl;
    return 0;
}