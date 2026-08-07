class Solution {
public:
    int minMutation(string stgen, string endGene, vector<string>& bank) {
        unordered_set<string>set;
        unordered_set<string>set2;
        for(int i=0;i<bank.size();i++){
            set.insert(bank[i]);
        }
        queue<pair<string,int>>q;
        q.push({stgen,0});
        string pos="ACGT";
        while(q.size()>0){
            string s=q.front().first;
            int ans=q.front().second;
            q.pop();
            set2.insert(s);
            if(s==endGene)return ans;
            string temp=s;
            int k=0;
            while(k<pos.size()){
                for(int i=0;i<temp.size();i++){
                    if(temp[i]!=pos[k]){
                        temp[i]=pos[k];
                        if(set.find(temp)!=set.end()){
                            if(set2.find(temp)==set2.end()){
                                q.push({temp,ans+1});
                            }
                        }
                    }
                    temp=s;
                }
                k++;
            }
        }
        return -1;
    }
};