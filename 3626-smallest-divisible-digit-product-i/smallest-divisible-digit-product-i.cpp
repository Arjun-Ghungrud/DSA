class Solution {
public:
    int smallestNumber(int n, int t) {
        int i=n;
        int ans=n;
        while(true){
            int pro=1;
            int temp=i;
            while(temp>0){
                int ld=temp%10;
                pro=pro*ld;
                temp/=10;
            }
            if(pro%t==0){
                ans=i;
                break;
            }
            i++;
        }
        return ans;
    }
};