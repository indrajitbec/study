// Medium
// This problem was asked by Google.

// Given the root to a binary tree, implement serialize(root), 
// which serializes the tree into a string, and deserialize(s), 
// which deserializes the string back into the tree.

// For example, given the following Node class

// class Node:

//     def __init__(self, val, left=None, right=None):
//         self.val = val
//         self.left = left
//         self.right = right
// The following test should pass:

// node = Node('root', Node('left', Node('left.left')), Node('right'))
// assert deserialize(serialize(node)).left.left.val == 'left.left'

// null can be represented as '#'


// Time : 1h21m
// errors : 
// 1. took val as char instead of string which confused after writing the algorithm
// 2. corected : ' ' as node val seperator and '#' as nullptr 
// 3. str.find(" ", pos) => str.find(' ', pos)
// 4. pos = found => pos = found + 1 after the change #1&#2 

#include<iostream>
#include<string>
#include<cassert>
using namespace std;

class TreeNode {
    static const char delim = '#';
    public:
        string val;
        TreeNode *left, *right;
        TreeNode(string val, TreeNode *left = nullptr, TreeNode *right = nullptr) 
            : val(val), left(left), right(right) {}
        static string serialize(TreeNode *root) {
            string result;
            serializePreOrder(root, result);
            return result;
        }
        static TreeNode *deserialize(string str) {
            size_t pos = 0;
            return deserializePreOrder(str, pos);
        }

    private:
        static void serializePreOrder(TreeNode *root, string &result) {
            if(root != nullptr) {
                result += root->val;
                result += " ";
                serializePreOrder(root->left, result);
                serializePreOrder(root->right, result);
                return;
            }
            result.push_back(delim);
        }
        static TreeNode *deserializePreOrder(string &str, size_t &pos) {
            if(pos >= str.length()) {
                return nullptr;
            }

            if(str[pos] == delim) {
                pos++;
                return nullptr;
            }

            size_t found  = str.find(' ', pos);
            if(found == string::npos) {
                return nullptr;
            }

            string node_val = str.substr(pos, found-pos);
            TreeNode *root = new TreeNode(node_val);
            pos = found + 1;
            root->left = deserializePreOrder(str,pos);
            root->right = deserializePreOrder(str, pos);
            return root;
        }
};


int main() {
    TreeNode *node = new TreeNode("root", new TreeNode("left", new TreeNode("left.left")), new TreeNode("right"));
    string serialized = TreeNode::serialize(node);
    cout << serialized <<endl;
    TreeNode *new_node = TreeNode::deserialize(serialized);
    assert(new_node->left->left->val == "left.left");
    cout << "ASSERT PASSED" << endl;

    return 0;
}