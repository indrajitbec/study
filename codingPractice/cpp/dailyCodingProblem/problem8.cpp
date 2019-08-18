// [Easy]
// This problem was asked by Google.

// A unival tree (which stands for "universal value") is a tree 

// where all nodes under it have the same value.

// Given the root to a binary tree, count the number of unival subtrees.

// For example, the following tree has 5 unival subtrees:

//    0
//   / \
//  1   0
//     / \
//    1   0
//   / \
//  1   1

#include<iostream>
#include<limits>
using namespace std;

class Node {
public:
    int val;
    Node *left, *right;
    Node(int val, Node *left=nullptr, Node *right=nullptr) {
        this->val = val;
        this->left = left;
        this->right = right;
    }
};

class UniversalSubTree {
private:
    static int CountRec(Node *root, int &match) {
        if(root == nullptr) {
            return 0;
        }
        int lmatch = numeric_limits<int>::max();
        int rmatch = numeric_limits<int>::max();
        int lc = root->left ? CountRec(root->left, lmatch): 0;
        int rc = root->right ? CountRec(root->right, rmatch): 0;
        if(root->left == nullptr && root->right == nullptr) {
            match = root->val;
            return 1;
        } else {
            if(root->left == nullptr && rc && root->right->val == root->val && root->val == rmatch) {
                return rc + 1;
            } else if(root->right == nullptr && lc && root->left->val == root->val && root->val == lmatch) {
                return lc + 1;
            } else if(lc && rc && 
                      (root->left->val == root->val && root->val == lmatch) && 
                      (root->right->val == root->val & root->val == rmatch) ) { 
                return lc + rc + 1;
            }
        }
        return lc + rc;
    }
public:
    static int Count(Node *root) {
        int match = numeric_limits<int>::max();
        return CountRec(root, match);
    }

};

int main() {
    Node *root  = new Node(0, new Node(1) , new Node(0,new Node(1,new Node(1), new Node(1)), new Node(0)));

    cout << UniversalSubTree::Count(root) << endl;

    root  = new Node(0, new Node(1) , new Node(0, new Node(0, new Node(1,new Node(1), new Node(1)), nullptr), new Node(0)));

    cout << UniversalSubTree::Count(root) << endl;
}