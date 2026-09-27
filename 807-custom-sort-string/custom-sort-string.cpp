class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> mp;
        for(char c:s)mp[c]++;
        string ans="";
        for(char c:order){
            while(mp[c]>0){
                ans+=c;
                mp[c]--;
            }
        }

        for(auto &it:mp){
            while(it.second>0){
                ans+=it.first;
                it.second--;
            }
        }
        return ans;
    }
};