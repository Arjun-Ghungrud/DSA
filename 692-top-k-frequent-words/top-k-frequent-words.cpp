class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n=words.size();
        map<string,int>mp;
        for(int i=0;i<n;i++){
            mp[words[i]]++;
        }   
        map<int,vector<string>,greater<int>>mp1;
        for(auto &it:mp){
            mp1[it.second].push_back(it.first);
        }
        vector<string>ans;
        int count=0;
        for(auto &it:mp1){
            if(count==k)break;
            vector<string>vals=it.second;
            sort(vals.begin(),vals.end());
            for(int i=0;i<vals.size();i++){
                ans.push_back(vals[i]);
                count++;
                if(count==k)break;
            }
        }
        return ans;
    }
};