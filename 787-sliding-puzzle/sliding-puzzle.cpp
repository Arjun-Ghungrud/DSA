class Solution{
public:
    int slidingPuzzle(vector<vector<int>>&board){
        vector<vector<int>>ans={{1,2,3},{4,5,0}};
        queue<pair<vector<vector<int>>,pair<pair<int,int>,int>>>q;
        set<string>vis;
        int zi=0,zj=0;
        for(int i=0;i<2;i++){
            for(int j=0;j<3;j++){
                if(board[i][j]==0){
                    zi=i;
                    zj=j;
                }
            }
        }
        q.push({board,{{zi,zj},0}});
        string s="";
        for(int i=0;i<2;i++){
            for(int j=0;j<3;j++){
                s+=char(board[i][j]+'0');
            }
        }
        vis.insert(s);
        while(!q.empty()){
            auto curr=q.front();
            q.pop();
            vector<vector<int>>currBoard=curr.first;
            int i=curr.second.first.first;
            int j=curr.second.first.second;
            int moves=curr.second.second;
            if(currBoard==ans)return moves;
            if(i>0){
                vector<vector<int>>temp=currBoard;
                swap(temp[i][j],temp[i-1][j]);
                string s="";
                for(int x=0;x<2;x++){
                    for(int y=0;y<3;y++){
                        s+=char(temp[x][y]+'0');
                    }
                }
                if(!vis.count(s)){
                    vis.insert(s);
                    q.push({temp,{{i-1,j},moves+1}});
                }
            }
            if(i<2-1){
                vector<vector<int>>temp=currBoard;
                swap(temp[i][j],temp[i+1][j]);
                string s="";
                for(int x=0;x<2;x++){
                    for(int y=0;y<3;y++){
                        s+=char(temp[x][y]+'0');
                    }
                }
                if(!vis.count(s)){
                    vis.insert(s);
                    q.push({temp,{{i+1,j},moves+1}});
                }
            }
            if(j>0){
                vector<vector<int>>temp=currBoard;
                swap(temp[i][j],temp[i][j-1]);
                string s="";
                for(int x=0;x<2;x++){
                    for(int y=0;y<3;y++){
                        s+=char(temp[x][y]+'0');
                    }
                }
                if(!vis.count(s)){
                    vis.insert(s);
                    q.push({temp,{{i,j-1},moves+1}});
                }
            }
            if(j<3-1){
                vector<vector<int>>temp=currBoard;
                swap(temp[i][j],temp[i][j+1]);
                string s="";
                for(int x=0;x<2;x++){
                    for(int y=0;y<3;y++){
                        s+=char(temp[x][y]+'0');
                    }
                }
                if(!vis.count(s)){
                    vis.insert(s);
                    q.push({temp,{{i,j+1},moves+1}});
                }
            }
        }
        return -1;
    }
};