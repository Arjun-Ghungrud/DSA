class Solution {
public:
    void helper(int idx, string &s, string &ans, vector<string> &res,int count, int remove, int &minRemove){
        if(count<0)return;
        if(idx==s.size()){
            if(count==0){
                if(remove<minRemove){
                    minRemove=remove;
                    res.clear();
                    res.push_back(ans);
                }
                else if(remove==minRemove){
                    res.push_back(ans);
                }
            }
            return;
        }
        ans.push_back(s[idx]);
        if(s[idx]=='(')count++;
        else if(s[idx]==')')count--;
        
        helper(idx+1,s,ans,res,count,remove,minRemove);
        if(s[idx]=='(')count--;
        else if(s[idx]==')')count++;
        ans.pop_back();
        helper(idx+1,s,ans,res,count,remove+1,minRemove);
        return;
    }
    vector<string> removeInvalidParentheses(string s) {
        vector<string>res;
        string ans="";
        int minre=INT_MAX;
        helper(0,s,ans,res,0,0,minre);
        sort(res.begin(),res.end());
        res.erase(unique(res.begin(),res.end()),res.end());
        return res;
    }
};