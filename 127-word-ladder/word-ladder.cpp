class Solution {
public:
    int ladderLength(string st, string end, vector<string>& wordList) {
        unordered_set<string>set;
        unordered_set<string>set2;
        for(int i=0;i<wordList.size();i++){
            set.insert(wordList[i]);
        }
        queue<pair<string,int>>q;
        q.push({st,1});
        set2.insert(st);
        string pos="abcdefghijklmnopqrstuvwxyz";
        while(q.size()>0){
            string s=q.front().first;
            int ans=q.front().second;
            q.pop();
            if(s==end)return ans;
            string temp=s;
            int k=0;
            while(k<pos.size()){
                for(int i=0;i<temp.size();i++){
                    if(temp[i]!=pos[k]){
                        temp[i]=pos[k];
                        if(set.find(temp)!=set.end()){
                            if(set2.find(temp)==set2.end()){
                                q.push({temp,ans+1});
                                set2.insert(temp);
                            }
                        }
                    }
                    temp=s;
                }
                k++;
            }
        }
        return 0;
    }
};