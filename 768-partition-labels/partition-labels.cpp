class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.size();
        map<char,int>mp;
        for(int i=0;i<n;i++){
            mp[s[i]]=i;
        }
        int last=0;
        vector<int>ans;
        int maxlim=0;
        for(int i=0;i<n;i++){
            if(maxlim<mp[s[i]]){
                maxlim=mp[s[i]];
            }
            if(i==maxlim){
                int len=i-last+1;
                last=i+1;
                ans.push_back(len);
            }
        }
        return ans;
    }
};