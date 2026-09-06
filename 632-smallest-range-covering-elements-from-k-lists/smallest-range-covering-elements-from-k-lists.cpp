class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k=nums.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        int maxel=INT_MIN;
        for(int i=0;i<k;i++){
            pq.push({nums[i][0],i,0});
            maxel=max(maxel,nums[i][0]);
        }
        vector<int>res={0,INT_MAX};
        while(pq.size()==k){
            vector<int>curr=pq.top();
            pq.pop();
            int minel=curr[0];
            int listidx=curr[1];
            int idx=curr[2];
            if(maxel-minel<res[1]-res[0]){
                res[0]=minel;
                res[1]=maxel;
            }
            if(idx+1<nums[listidx].size()){
                int nextele=nums[listidx][idx+1];
                pq.push({nextele,listidx,idx+1});
                maxel=max(maxel,nextele);
            }
        }
        return res;
    }
};