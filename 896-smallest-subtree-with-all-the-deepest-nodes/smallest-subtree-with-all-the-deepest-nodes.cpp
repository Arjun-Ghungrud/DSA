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
    pair<TreeNode*,int> helper(TreeNode* root,int lev){
        if(root==NULL){
            return {NULL,lev};
        }
        pair<TreeNode*,int>lefts=helper(root->left,lev+1);
        pair<TreeNode*,int>rights=helper(root->right,lev+1);
        if(lefts.first==NULL && rights.first!=NULL){
            return rights;
        }
        if(lefts.first!=NULL && rights.first==NULL){
            return lefts;
        }
        if(lefts.first!=NULL && rights.first!=NULL){
            if(lefts.second==rights.second){
                return {root,lefts.second};
            }
            else{
                if(lefts.second>rights.second)return lefts;
                return rights;
            }
        }
        return {root,lev};
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        pair<TreeNode*,int>ans=helper(root,0);
        return ans.first;
    }
};