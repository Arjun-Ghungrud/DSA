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
    vector<int> helper(TreeNode* root,int &count){
        if(root==NULL){
            return {0,0};
        }
        vector<int>ltree=helper(root->left,count);
        vector<int>rtree=helper(root->right,count);
        int sum=root->val+ltree[0]+rtree[0];
        int nodes=1+ltree[1]+rtree[1];
        int avg=sum/nodes;
        if(avg==root->val)count+=1;
        return {sum,nodes};
    }
    int averageOfSubtree(TreeNode* root) {
        int count=0;
        helper(root,count);
        return count;
    }
};