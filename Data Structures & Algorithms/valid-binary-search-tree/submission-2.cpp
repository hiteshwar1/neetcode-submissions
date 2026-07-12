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
    bool helper(TreeNode* root, int maxi, int mini) {
        if (!root) return true;
        return root->val > mini && root->val < maxi && helper(root->left, root->val, mini) &&
               helper(root->right, maxi, root->val);
    }
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        return helper(root, INT_MAX, INT_MIN);
    }
};
