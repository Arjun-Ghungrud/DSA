class Solution {
public:
    
    void helper(string curr,vector<string>&res,int open,int close,int n){
        if(curr.size()==2*n){
            res.push_back(curr);
            return;
        }
        if(open<n){
            curr.push_back('(');
            helper(curr,res,open+1,close,n);
            curr.pop_back();
        }
        if(close<open){
            curr.push_back(')');
            helper(curr,res,open,close+1,n);
            curr.pop_back();
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        string curr="";
        int open=0;
        int close=0;
        vector<string>res;
        helper(curr,res,open,close,n);
        return res;
    }
};