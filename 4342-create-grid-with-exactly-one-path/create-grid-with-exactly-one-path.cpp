class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string>ans;
        for(int i=0;i<m;i++){
            string s="";
            for(int j=0;j<n;j++)s+="#";
            ans.push_back(s);
        }
        //traverse right
        int i=0;
        int j=0;
        string st=ans[0];
        while(i<n){
            st[i]='.';
            i++;
        }
        ans[0]=st;
        if(m==1)return ans;
        i = 1;
        while(i<m){
            ans[i][n-1]='.';
            i++;
        }
        return ans;
    }
};