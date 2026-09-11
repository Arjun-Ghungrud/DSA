class Solution {
public:
    set<int>st;
    void helper(vector<int>& digits,int nums,vector<bool>&used,int digus){
        if(digus==3){
            if(nums%2==0)st.insert(nums);
            return;
        }
        for(int i=0;i<digits.size();i++){
            if(used[i])continue;
            if(digus == 0 && digits[i] == 0) continue;
            nums=nums*10+digits[i];
            used[i]=true;
            helper(digits,nums,used,digus+1);
            used[i]=false;
            nums/=10;
        }
        return;
    }
    int totalNumbers(vector<int>& digits) {
        int n=digits.size();
        vector<bool>used(n,false);
        helper(digits,0,used,0);
        return st.size();
    }
};