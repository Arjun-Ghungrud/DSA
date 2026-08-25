class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_set<int>st;
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        int ans=-1;
        int i=1;
        while(true){
            int val=i*k;
            if(st.find(val)==st.end()){
                ans=val;
                break;
            }
            i++;
        }
        return ans;
    }
};