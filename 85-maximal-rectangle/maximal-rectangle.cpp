class Solution {
public:
    int largesthisto(vector<int>&heights){
        int n=heights.size();
        if(n==0)return 0;
        vector<int>right(n);
        vector<int>left(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(st.size()>0 && heights[st.top()]>=heights[i])st.pop();
            right[i]= st.size()==0 ? n:st.top();
            st.push(i);
        }
        while(st.size()>0)st.pop();
        for(int i=0;i<n;i++){
            while(st.size()>0 && heights[st.top()]>=heights[i])st.pop();
            left[i]= st.size()==0 ? -1:st.top();
            st.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int w=right[i]-left[i]-1;
            int area=heights[i]*w;
            ans=max(ans,area);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<int>heights(m,0);
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='1')heights[j]+=(mat[i][j]-'0');
                else heights[j]=0;
            }
            int res=largesthisto(heights);
            ans=max(res,ans);
        }
        return ans;
    }
};