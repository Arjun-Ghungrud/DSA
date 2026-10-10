
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2,int k1, int k2) {
        int n=nums1.size();
        long long k=(long long)k1+k2;

        int maxDiff=0;
        vector<int>diff(n);

        for(int i=0;i<n;i++){
            diff[i]=abs(nums1[i]-nums2[i]);
            maxDiff=max(maxDiff,diff[i]);
        }
        long long total=0;
        vector<long long>freq(maxDiff+1,0);
        for(int d:diff){
            freq[d]++;
            total+=d;
        }
        if(k>=total)return 0;

        for(int d=maxDiff;d>0 && k>0;d--){
            long long move=min(freq[d],k);

            freq[d]-=move;
            freq[d-1]+=move;
            k-=move;
        }
        long long ans=0;
        for(int d=0;d<=maxDiff;d++){
            ans+=freq[d]*d*d;
        }
        return ans;
    }
};
