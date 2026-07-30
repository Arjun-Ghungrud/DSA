class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1 || s.length()<=numRows)return s;
        vector<vector<char>>ans;
        vector<char>apl;
        int r=numRows;
        int val=0;
        int n0=0;
        int i=0;
        int n=s.size();
        while(i<n){
            if(n0==0){
                while(val<r && i<n){
                    apl.push_back(s[i]);
                    i++;
                    val++;
                }
            }else{
                if(val==(r-n0-1) && i<n){
                    apl.push_back(s[i]);
                    i++;
                }else{
                    apl.push_back('0');
                }
                val++;
            }

            if(val==r){
                ans.push_back(apl);
                apl.clear();
                val = 0;
                n0=(n0+1)%(numRows-1==0?1:numRows-1);
            }
        }
        while(val>0&& val<r){
            apl.push_back('0');
            val++;
        }
        if(!apl.empty()){
            ans.push_back(apl);
        }
        int cols=ans.size();
        int rows=ans[0].size();
        string res="";
        for (int row=0;row<rows;row++){
            for (int col=0;col<cols;col++){
                if(ans[col][row]!='0'){
                    res.push_back(ans[col][row]);
                }
            }
        }
        return res;
    }
};