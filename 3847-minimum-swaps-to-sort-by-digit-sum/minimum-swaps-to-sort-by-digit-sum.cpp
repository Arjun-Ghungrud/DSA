class Solution {
public:
    int f(int n){
        int sum=0;
        while(n>0){
            int ld=n%10;
            sum+=ld;
            n/=10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        vector<int>nums1=nums;
        auto lam=[this](int num1,int num2){
            int val1=f(num1);
            int val2=f(num2);
            if(val1!=val2)return val1<val2;
            return num1<num2;
        };
        sort(begin(nums1),end(nums1),lam);
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]=i;
        }
        int count=0;
        for(int i=0;i<n;i++){
            int exp=nums1[i];
            int curr=nums[i];
            if(exp==curr)continue;
            int idx=mp[exp];
            nums[i]=exp;
            nums[idx]=curr;
            mp[exp]=i;
            mp[curr]=idx;
            count++;
        }
        return count;
    }
};