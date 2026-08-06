class Solution {
public:
    pair<int,int>getcord(int val,int n){
        int rt=(val-1)/n;
        int rb=(n-1)-rt;
        int colt=(val-1)%n;
        if((n%2==1 && rb%2==1) || (n%2==0 && rb%2==0)){
            colt=(n-1)-colt;
        }
        return {rb,colt};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        queue<int>q;
        int steps=0;
        vector<vector<bool>>vis(n,vector<bool>(n,false));
        vis[n-1][0]=true;
        q.push(1);
        while(q.size()>0){
            int p=q.size();
            while(p--){
                int x=q.front();
                q.pop();
                if(x==n*n)return steps;
                for(int j=1;j<=6;j++){
                    int val=x+j;
                    if(val>n*n)break;
                    pair<int,int>cord=getcord(val,n);
                    int r=cord.first;
                    int c=cord.second;
                    if(vis[r][c])continue;
                    vis[r][c]=true;
                    if(board[r][c]==-1)q.push(val);
                    else q.push(board[r][c]);
                }
            }
            steps++;
        }
        return -1;
    }
};