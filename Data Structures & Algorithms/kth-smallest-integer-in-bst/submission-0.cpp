/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* helper(TreeNode* root, int &k){
        if(!root) return nullptr;
        TreeNode* left = helper(root->left, k);
        if(left) return left;
        k--;
        if(k == 0) return root;
        return helper(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        TreeNode* res = helper(root, k);
        return res->val;
    }
};
