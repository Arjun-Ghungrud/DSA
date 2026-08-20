class Solution {
public:
    string intToRoman(int num) {
        int val=num;
        vector<int>nums(4);
        int mul=1;
        int i=0;
        while(val>0){
            int ld=val%10;
            nums[3-i]=ld*mul;
            mul*=10;
            val/=10;
            i++;
        }
        map<int,char>mp;
        mp.insert({1,'I'});
        mp.insert({5,'V'});
        mp.insert({10,'X'});
        mp.insert({50,'L'});
        mp.insert({100,'C'});
        mp.insert({500,'D'});
        mp.insert({1000,'M'});
        string ans="";
        int div=1000;
        for(int i=0;i<nums.size();i++){
            int amt=nums[i]/div;
            
            if(amt==5){
                ans+=mp[5*div];
            }
            else if(amt>5){
                int diff=amt-5;
                if(diff==4){
                    ans+=mp[div];
                    ans+=mp[div*10];
                }
                else if(diff<4){
                    ans+=mp[5*div];
                    for(int i=0;i<diff;i++){
                        ans+=mp[div];
                    }
                }
            }else if(amt<5 && amt>=1){
                if(amt==4){
                    ans+=mp[div];
                    ans+=mp[5*div];
                }
                else if(amt<4){
                    for(int i=0;i<amt;i++){
                        ans+=mp[div];
                    }
                }
            }
            div/=10;
        }
        return ans;
    }
};