class Solution {
public:
    string evaluate(string s, vector<vector<string>>& know) {
        int n=know.size();
        map<string,string>mp;
        for(int i=0;i<n;i++){
            string k=know[i][0];
            string v=know[i][1];
            mp[k]=v;
        }
        string ans="";
        int i=0;
        while(i<s.size()){
            if(s[i]=='('){
                i+=1;
                string word="";
                while(s[i]!=')'){
                    word+=s[i];
                    i++;
                }
                if(mp.find(word)==mp.end()){
                    ans+="?";
                }else{
                    ans+=mp[word];
                }
            }else{
                ans+=s[i];
            }
            i++;
        }
        return ans;
    }
};