class Solution {
public:
    vector<int> helper(const string &s){
        vector<int>res;
        for(int i=0;i<s.size();i++){
            if(s[i]=='+' || s[i]=='-' || s[i]=='*'){
                vector<int>leftres=helper(s.substr(0,i));
                vector<int>rightres=helper(s.substr(i+1));
                for(int j=0;j<leftres.size();j++){
                    for(int k=0;k<rightres.size();k++){
                        if(s[i]=='+'){
                            res.push_back(leftres[j]+rightres[k]);
                        }else if(s[i]=='-'){
                            res.push_back(leftres[j]-rightres[k]);
                        }else if(s[i]=='*'){
                            res.push_back(leftres[j]*rightres[k]);
                        }
                    }
                }
            }
        }
        if(res.size()==0)res.push_back(stoi(s));
        return res;
    }
    vector<int> diffWaysToCompute(string s) {
        return helper(s);
    }
};