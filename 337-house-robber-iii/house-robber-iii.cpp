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
    pair<int,int> helper(TreeNode*root){
        if(root==NULL){
            return {0,0};
        }
        auto leftn=helper(root->left);
        auto rightn=helper(root->right);
        int val1=root->val+leftn.second+rightn.second;
        int val2=max(leftn.first,leftn.second)+max(rightn.first,rightn.second);
        return {val1,val2};
    }
    int rob(TreeNode* root) {
        auto opt=helper(root);
        return max(opt.first,opt.second);
    }
};