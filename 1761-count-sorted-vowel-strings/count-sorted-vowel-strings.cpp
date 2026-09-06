class Solution {
public:
    void helper(string &temp,int n,vector<char>&vowels,int &count,int idx){
        if(temp.size()==n){
            count++;
            return;
        }
        for(int i=idx;i<vowels.size();i++){
            temp.push_back(vowels[i]);
            helper(temp,n,vowels,count,i);
            temp.pop_back();
        }
        return;
    }
    int countVowelStrings(int n) {
        vector<char>vowels;
        vowels.push_back('a');
        vowels.push_back('e');
        vowels.push_back('i');
        vowels.push_back('o');
        vowels.push_back('u');
        string temp="";
        int count=0;
        helper(temp,n,vowels,count,0);
        return count;
    }
};