class Solution {
public:
    vector<string>res;
    void helper(string curr,int open,int close,int n){
        if(curr.size()==2*n){
            res.push_back(curr);
            return;
        }
        if(open<n){
            curr.push_back('(');
            helper(curr,open+1,close,n);
            curr.pop_back();
        }
        if(close<open){
            curr.push_back(')');
            helper(curr,open,close+1,n);
            curr.pop_back();
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        string curr="";
        int open=0;
        int close=0;
        helper(curr,open,close,n);
        return res;
    }
};