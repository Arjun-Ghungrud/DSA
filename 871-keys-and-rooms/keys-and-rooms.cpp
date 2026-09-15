class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool>vis(n,false);
        vis[0]=true;
        queue<int>q;
        q.push(0);
        while(q.size()>0){
            int curr=q.front();
            q.pop();
            for(int v:rooms[curr]){
                if(!vis[v]){
                    q.push(v);
                    vis[v]=true;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(vis[i]==false)return false;
        }
        return true;
    }
};