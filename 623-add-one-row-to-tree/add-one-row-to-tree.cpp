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
    TreeNode* helper(TreeNode* root, int val, int depth,int lev){
        if(root==NULL)return NULL;
        TreeNode*leftsub=helper(root->left,val,depth,lev+1);
        TreeNode*rightsub=helper(root->right,val,depth,lev+1);
        if(lev==depth-1){
            TreeNode*n1=new TreeNode(val);
            TreeNode*n2=new TreeNode(val);
            n1->left=leftsub;
            n2->right=rightsub;
            root->left=n1;
            root->right=n2;
        }
        return root;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        return helper(root,val,depth,1);
    }
};