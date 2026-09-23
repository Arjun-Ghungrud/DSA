class Solution {
public:
    int myAtoi(string s) {
        string ans="";
        int i=0;
        while(i<s.size() && s[i]==' ')i++;
        if(i<s.size() &&(s[i]=='-'||s[i] == '+')) {
            ans+=s[i];
            i++;
        }
        while(i<s.size() && isdigit(s[i])){
            ans+=s[i];
            i++;
        }
        if(ans.empty() || ans=="+" || ans=="-")return 0;
        long long res=0;
        int pro=1;
        int start=0;
        if(ans[0]=='-'){
            pro=-1;
            start=1;
        }
        else if(ans[0]=='+'){
            start=1;
        }
        for (int j=start;j<ans.size();j++){
            int dig=ans[j]-'0';
            res=res*10+dig;
            if(pro==1 && res>INT_MAX){
                return INT_MAX;
            }
            if(pro==-1 && -res<INT_MIN){
                return INT_MIN;
            }
        }
        return pro*res;
    }
};