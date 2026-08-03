class Solution {
public:
    int hIndex(vector<int>& cit) {
        int n=cit.size();
        sort(cit.begin(),cit.end());
        reverse(cit.begin(),cit.end());
        int idx=0;
        for(int i=0;i<n;i++){
            if(i+1<=cit[i])idx=i+1;
            else break;
        }
        return idx;
    }
};