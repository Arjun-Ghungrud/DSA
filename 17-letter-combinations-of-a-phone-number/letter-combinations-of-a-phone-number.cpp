class Solution {
public:
    vector<string>res;
    void solve(int idx,string &st,string &temp,unordered_map<char,string>&mp){
        if(idx>=st.size()){
            res.push_back(temp);
            return;
        }
        char ch=st[idx];
        string s=mp[ch];
        for(int i=0;i<s.size();i++){
            temp.push_back(s[i]);
            solve(idx+1,st,temp,mp);
            temp.pop_back();
        }
        return;
    }
    vector<string> letterCombinations(string st) {
        int n=st.size();
        unordered_map<char,string>mp;
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
        string temp="";
        solve(0,st,temp,mp);
        return res;
    }
};