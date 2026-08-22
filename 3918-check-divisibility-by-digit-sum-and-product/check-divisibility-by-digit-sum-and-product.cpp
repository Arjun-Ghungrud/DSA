class Solution {
public:
    bool checkDivisibility(int n) {
        int num=n;
        int sum=0;
        int pro=1;
        while(num>0){
            int ld=num%10;
            sum+=ld;
            pro*=ld;
            num/=10;
        }
        int val=sum+pro;
        if(n%val==0)return true;
        return false;
    }
};