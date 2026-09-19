class Solution {
public:
    int numSplits(string s) {
        int n=s.size();
        map<int,int>mp1;
        map<int,int>mp2;
        map<char,int>freq;
        map<char,int>freq1;
        for(int i=0;i<n;i++){
            freq[s[i]]++;
            mp1[i]=freq.size();
        }
        for(int i=n-1;i>=0;i--){
            freq1[s[i]]++;
            mp2[i]=freq1.size();
        }
        int count=0;
        for(auto &it:mp1){
            int idx=it.first+1;
            if(it.second==mp2[idx])count++;
        }
        return count;
    }
};