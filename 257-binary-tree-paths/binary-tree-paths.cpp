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
    void helper(TreeNode* root,string& path,vector<string>&ans){
        if(root->left==NULL && root->right==NULL){
            ans.push_back(path);
            return;
        }
        if(root->left){
            path+="->";
            string val=to_string(root->left->val);
            path+=val;
            helper(root->left,path,ans);
            path.erase(path.size()-val.size()-2);
        }
        if(root->right){
            path+="->";
            string val=to_string(root->right->val);
            path+=val;
            helper(root->right,path,ans);
            path.erase(path.size()-val.size()-2);
        }
        return;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        if(root==NULL)return ans;
        string path=to_string(root->val);
        helper(root,path,ans);
        return ans;
    }
};