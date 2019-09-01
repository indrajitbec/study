// [Easy]
// This problem was asked by Facebook.

// Given a string of round, curly, and square open and closing brackets, 
// return whether the brackets are balanced (well-formed).

// For example, given the string "([])[]({})", you should return true.

// Given the string "([)]" or "((()", you should return false.

#include<iostream>
#include<string>
#include<stack>
#include<unordered_map>

using namespace std;

class BracketExpresion {
private:
    static inline bool isClose(wchar_t c) {
        return c == ')' || c == '}' || c == ']';
    }
    static inline bool isComplement(wchar_t o, wchar_t c) {
        unordered_map<wchar_t, wchar_t> cmap = {{'(',')'}, {'{','}'}, {'[',']'},};

        return cmap[o] == c;
    }
public:
    static bool isValid(string str) {
        int n = str.length();

        if(n==0) return true;

        stack<wchar_t> st;
        for(auto c : str) {
            if(isClose(c)) {
                if(st.empty() || !isComplement(st.top(), c)) {
                    return false;
                }
                st.pop();
            } else {
                st.push(c);
            }
        }
        return st.empty();
    }
};

int main() {

    string ans[2] = {"False", "True"};

    cout << ans[BracketExpresion::isValid("([])[]({})")] << endl;
 
    cout << ans[BracketExpresion::isValid("([)]")] << endl;

    cout << ans[BracketExpresion::isValid("((()")]<< endl;
}


