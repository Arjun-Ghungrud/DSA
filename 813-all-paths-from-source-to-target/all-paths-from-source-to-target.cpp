class Solution {
public:
    void dfs(int curr,vector<int>&temp,vector<vector<int>>&ans,vector<vector<int>>& graph,int n){
        if(curr==n-1){
            ans.push_back(temp);
            return ;
        }
        for(int v:graph[curr]){
            temp.push_back(v);
            dfs(v,temp,ans,graph,n);
            temp.pop_back();
        }
        return;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int>temp;
        vector<vector<int>>ans;
        int n=graph.size();
        temp.push_back(0);
        dfs(0,temp,ans,graph,n);
        return ans;
    }
};