class Solution {
public:
    void helper(int i,int n,string &s,string &ans,vector<string>&res){
        if(i==n){
            res.push_back(ans);
            return;
        }
        if(isdigit(s[i])){
            ans.push_back(s[i]);
            helper(i+1,n,s,ans,res);
            ans.pop_back();
            return;
        }
        ans.push_back(s[i]);
        helper(i+1,n,s,ans,res);
        ans.pop_back();
        if(isupper(s[i])){
            char let=tolower(s[i]);
            ans.push_back(let);
        }else{
            char let=toupper(s[i]);
            ans.push_back(let);
        }
        helper(i+1,n,s,ans,res);
        ans.pop_back();
        return;
    }
    vector<string> letterCasePermutation(string s) {
        int n=s.size();
        string ans="";
        vector<string>res;
        helper(0,n,s,ans,res);
        return res;
    }
};