class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        map<int,vector<int>>mp;
        vector<int>res;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mp[i+j].push_back(mat[i][j]);
            }
        }
        bool rev=1;
        for(auto &it:mp){
            if(rev==1){
                reverse(it.second.begin(),it.second.end());
            }
            rev=1-rev;
            for(int k=0;k<it.second.size();k++){
                res.push_back(it.second[k]);
            }
        }
        return res;
    }
};