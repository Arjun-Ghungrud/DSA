class Solution {
public:
    string findtheconsstring(string &s){
        int count=1;
        string res="";
        for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1])count++;
            else{
                res+=to_string(count);
                res+=s[i-1];
                count=1;
            }
        }
        res+=to_string(count);
        res+=s[s.size()-1];
        return res;
    }
    void helper(int i,int n,string& ans){
        if(i==n)return;
        string cons=findtheconsstring(ans);
        ans=cons;
        helper(i+1,n,ans);
    }
    string countAndSay(int n) {
        string ans="1";
        helper(1,n,ans);
        return ans;
    }
};