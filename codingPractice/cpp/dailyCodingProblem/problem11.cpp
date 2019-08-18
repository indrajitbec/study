// [Medium]
// This problem was asked by Twitter.

// Implement an autocomplete system. That is, given a query string s and a set of all possible query strings, return all strings in the set that have s as a prefix.

// For example, given the query string de and the set of strings [dog, deer, deal], return [deer, deal].

// Hint: Try preprocessing the dictionary into a more efficient data structure to speed up queries.

// Idea : Trie

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Node {
private:
  unordered_map<char, Node *> child;
  bool eos;
  
public:

  Node(bool eos=false): eos(eos) {}
  Node *GetChild(char c) {
        if(child.find(c) != child.end()) {
            return child[c];
        }
        return nullptr;
  }
  void SetChild(char c, Node *node) {
      child[c] = node;
  }
  void SetEos() {eos = true;}
  bool IsEos() {return eos;}
};

class AutoCompleteUtil {
private:
    Node root;
    void dfs(Node *pChild, string &curr, vector<string> &result) {
        if(pChild->IsEos()) {
            result.push_back(curr);
        }
        for(auto c : pChild->child
    }
    
public:
    void AddWord(string s) {
        Node *pChild = &this->root;
        int n = s.length();

        for(i = 0; i < n ; i++) {
            if(pChild->GetChild(s[i]) != nullptr) {
                pChild = pChild->GetChild(s[i]);
            } else {
                auto newChild = new Node();
                pChild->SetChild(s[i], newChild);
                pChild = newChild;
            }
        }
        pChild->SetEos();
    }
    vector<string> sreach(string key) {
        
        vector<string> result;
        Node *pChild = &root;
        for(int i = 0; i < key.length(); i++) {
            if(pChild->GetChild(key[i]) != nullptr) {
                pChild = pChild->GetChild(key[i]);
            } else {
                return result;
            }
        }

        dfs(pChild, key, result);
        return result;
    }
};