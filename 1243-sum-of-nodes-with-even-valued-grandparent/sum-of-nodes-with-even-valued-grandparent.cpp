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
    int sumEvenGrandparent(TreeNode* root) {
        queue<pair<pair<TreeNode*,int>,pair<int,int>>>q;
        q.push({{root,0},{-1,-1}});
        int sum=0;
        while(q.size()>0){
            auto curr=q.front().first;
            auto ancest=q.front().second;
            q.pop();
            TreeNode*currnode=curr.first;
            int lev=curr.second;
            int par=ancest.first;
            int gpar=ancest.second;
            if(gpar%2==0)sum+=(currnode->val);
            if(currnode->left){
                if(lev!=0)q.push({{currnode->left,lev+1},{currnode->val,par}});
                else q.push({{currnode->left,lev+1},{currnode->val,-1}});
            }
            if(currnode->right){
                if(lev!=0)q.push({{currnode->right,lev+1},{currnode->val,par}});
                else q.push({{currnode->right,lev+1},{currnode->val,-1}});
            }
        }
        return sum;
    }
};