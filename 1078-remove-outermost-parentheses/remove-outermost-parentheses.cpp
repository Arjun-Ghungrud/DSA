class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.size();
        string ans="";
        int count=0;
        string res="";
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                count++;
                ans.push_back(s[i]);
            }
            else if(s[i]==')'){
                count--;
                ans.push_back(s[i]);
            }
            if(count==0){
                if(!ans.empty())ans.erase(0,1);
                if(!ans.empty())ans.pop_back();
                res+=ans;
                ans.clear();
            }
        }
        return res;
    }
};