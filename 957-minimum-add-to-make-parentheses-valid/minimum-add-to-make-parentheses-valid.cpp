class Solution {
public:
    int minAddToMakeValid(string s) {
        int n=s.size();
        int count=0;
        int ops=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(')count++;
            else count--;
            if(count<0){
                ops+=abs(count);
                count=0;
            }
        }
        ops+=abs(count);
        return ops;
    }
};