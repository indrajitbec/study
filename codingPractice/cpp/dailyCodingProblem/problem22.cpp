// [Medium]

// This problem was asked by Microsoft.

// Given a dictionary of words and a string made up of those words (no spaces), 
// return the original sentence in a list. If there is more than one possible reconstruction, 
// return any of them. If there is no possible reconstruction, then return null.

// For example, given the set of words 'quick', 'brown', 'the', 'fox', and the string "thequickbrownfox", 
// you should return ['the', 'quick', 'brown', 'fox'].

// Given the set of words 'bed', 'bath', 'bedbath', 'and', 'beyond', and the string "bedbathandbeyond", 
// return either ['bed', 'bath', 'and', 'beyond] or ['bedbath', 'and', 'beyond'].


#include<iostream> 
#include<vector> 
#include<unordered_set>
#include<string>
#include<algorithm>

using namespace std;

class DisctionaryMatch {
private:
    static bool findSentenceUtil(string &str, int start, int end, vector<string> &res, unordered_set<string> &dictionary) {
        if(end == str.length()) {
            if(dictionary.find(str.substr(start)) != dictionary.end()) {
                res.push_back(str.substr(start));
                return true;
            } else {
                return false;
            }
        }

        if(dictionary.find(str.substr(start, end-start+1)) != dictionary.end() &&
           findSentenceUtil(str, end+1, end+1, res, dictionary)) {
            res.push_back(str.substr(start, end-start+1));
            return true;
        } else {
            return findSentenceUtil(str, start, end+1, res, dictionary);
        }
        //return false;
    }
public:
    static vector<string> findSentence(string str, unordered_set<string> &dictionary) {
        vector<string> res;

        if(findSentenceUtil(str, 0, 0, res, dictionary)) {
            reverse(res.begin(), res.end());
            return res;
        }
        return vector<string>();
    }
};


int main() {
    {
        unordered_set<string> dict1 = {"quick", "brown", "the", "fox"};

        auto words = DisctionaryMatch::findSentence("thequickbrownfox", dict1);

        for(auto w : words) {
            cout << w<<",";
        }
        cout << endl;

    }

    {
        unordered_set<string> dict1 = {"bed", "bath", "bedbath", "and", "beyond"};

        auto words = DisctionaryMatch::findSentence("bedbathandbeyond", dict1);

        for(auto w : words) {
            cout << w<<",";
        }
        cout << endl;

    }
    
}