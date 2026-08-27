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
    int findtheheight(TreeNode* root){
        if(root==NULL)return 0;
        int lev1=1+findtheheight(root->left);
        int lev2=1+findtheheight(root->right);
        return max(lev1,lev2);
    }
    vector<vector<string>> printTree(TreeNode* root) {
        int h=findtheheight(root);
        int n=h;
        int m=pow(2,n)-1;
        vector<vector<string>>ans(n,vector<string>(m,""));
        queue<pair<pair<TreeNode*,char>,pair<int,int>>>q;
        int r=0;
        int c=(m-1)/2;
        q.push({{root,'0'},{r,c}});
        ans[r][c]=to_string(root->val);
        while(q.size()>0){
            TreeNode*Node=q.front().first.first;
            int lr=q.front().second.first;
            int lc=q.front().second.second;
            q.pop();
            if(lr+1<h && Node->left){
                int exp=h-lr-2;
                int column=lc-pow(2,exp);
                ans[lr+1][column]=to_string(Node->left->val);
                q.push({{Node->left,'l'},{lr+1,column}});
            }
            if(lr+1<h && Node->right){
                int exp=h-lr-2;
                int column=lc+pow(2,exp);
                ans[lr+1][column]=to_string(Node->right->val);
                q.push({{Node->right,'r'},{lr+1,column}});
            }
        }
        return ans;
    }
};