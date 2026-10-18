class Solution {
public:
    void helper(string tiles,vector<bool>&used,unordered_set<string>&res,string curr){
        int n=tiles.size();
        res.insert(curr);
        for(int i=0;i<n;i++){
            if(used[i])continue;
            used[i]=true;
            curr.push_back(tiles[i]);
            helper(tiles,used,res,curr);
            used[i]=false;
            curr.pop_back();
        }
        return;
    }
    int numTilePossibilities(string tiles) {
        int n=tiles.size();
        vector<bool>used(n,false);
        unordered_set<string>res;
        string curr="";
        helper(tiles,used,res,curr);
        return res.size()-1;
    }
};