class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int j=0;
        map<char,int>mp;
        int ans=0;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
            while(j<=i && mp[s[i]]>1){
                mp[s[j]]--;
                if(mp[s[j]]==0)mp.erase(s[j]);
                j++;
            }
            ans=max(ans,i-j+1);
        }
        return ans;
    }
};