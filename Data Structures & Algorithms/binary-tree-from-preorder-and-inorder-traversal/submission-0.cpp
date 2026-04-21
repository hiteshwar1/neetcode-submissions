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
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int &preorderIdx, int l, int h){
        if(l>h) return nullptr;
        TreeNode* node = new TreeNode(preorder[preorderIdx]);
        int x = -1;
        for(int i = 0; i < inorder.size(); i++){
            if(inorder[i] == preorder[preorderIdx]){
                x = i;
                break;
            }
        }
        preorderIdx += 1;
        node->left = helper(preorder,inorder,preorderIdx,l,x-1);
        node->right = helper(preorder,inorder,preorderIdx,x+1,h);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preorderIdx = 0;
        return helper(preorder, inorder, preorderIdx, 0, preorder.size()-1);
    }
};
