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
    int helper(TreeNode* root,map<int,int>&mp){
        if(root==NULL)return 0;
        int leftv=helper(root->left,mp);
        int rightv=helper(root->right,mp);
        int sum=root->val+leftv+rightv;
        mp[sum]+=1;
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        map<int,int>mp;
        helper(root,mp);
        vector<int>ans;
        int maxval=INT_MIN;
        for(auto &it:mp){
            maxval=max(maxval,it.second);
        }
        for(auto &it:mp){
            if(it.second==maxval)ans.push_back(it.first);
        }
        return ans;
    }
};