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
    bool isEqualTree(TreeNode* x, TreeNode* y) {
        if (!x && !y) return true;
        if (!x || !y) return false;
        return x->val == y->val && isEqualTree(x->left, y->left) && isEqualTree(x->right, y->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root || !subRoot) return false;
        if (isEqualTree(root, subRoot)) return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
