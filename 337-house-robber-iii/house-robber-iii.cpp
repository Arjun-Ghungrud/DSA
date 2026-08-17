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
    vector<int> helper(TreeNode*root){
        if(root==NULL){
            return {0,0};
        }
        vector<int>leftn=helper(root->left);
        vector<int>rightn=helper(root->right);
        vector<int>nums(2);
        nums[0]=root->val+leftn[1]+rightn[1];
        nums[1]=max(leftn[0],leftn[1])+max(rightn[0],rightn[1]);
        return nums;
    }
    int rob(TreeNode* root) {
        vector<int>opt=helper(root);
        return max(opt[0],opt[1]);
    }
};