class Solution {
public:
    int maximum69Number (int num) {
        string dig=to_string(num);
        for(int i=0;i<dig.size();i++){
            if(dig[i]=='6'){
                dig[i]='9';
                break;
            }
        }
        int ans=stoi(dig);
        return ans;
    }
};