// [Medium]
// This problem was asked by Dropbox.
// 
// Given the root to a binary search tree, find the second largest node in the tree.
//
#include<iostream>

struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int val, TreeNode *left=nullptr, Tree *right=nullptr): val(val), left(left), right(right) {}
};

class BSTUtil {
		bool dfs(TreeNode *root, int &secondMax, int &index) {
			if(root == nullptr) return false;
			if(dfs(root->right, secondMax, index)) {
				return true;
			}
			index++;
			if(index == 2) {
				secondMax = root->val;
				return true;
			}
			return dfs(root->left, secondMax, index);

		}
	public:
		int FindSecondLargest(TreeNode *root) {
			int index = 0;
			int res;
			if(dfs(root, res,index)) {
				return res;
			} else {
				return -1;
			}
			
		}
};
