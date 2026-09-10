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
    int count=0;
    vector<int> helper(TreeNode* root){
        if(root==NULL){
            return {0,0};
        }
        vector<int>ltree=helper(root->left);
        vector<int>rtree=helper(root->right);
        int sum=root->val+ltree[0]+rtree[0];
        int nodes=1+ltree[1]+rtree[1];
        if(sum/nodes==root->val)count++;
        return {sum,nodes};
    }
    int averageOfSubtree(TreeNode* root) {
        helper(root);
        return count;
    }
};