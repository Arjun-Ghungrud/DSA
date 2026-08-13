class Solution {
public:
    unordered_map<string,bool>mp;
    bool helper(string word,unordered_set<string>&st){
        if(mp.find(word)!=mp.end())return mp[word];
        int l=word.size();
        for(int i=0;i<l;i++){
            string pre=word.substr(0,i+1);
            string suff=word.substr(i+1);
            if((st.find(pre)!=st.end() && helper(suff,st)) || (st.find(pre)!=st.end() && st.find(suff)!=st.end())){
                return mp[word]=true;
            }
        }
        return mp[word]=false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        int n=words.size();
        mp.clear();
        unordered_set<string>st(begin(words),end(words));
        vector<string>ans;
        for(int i=0;i<n;i++){
            string word=words[i];
            if(helper(word,st)){
                ans.push_back(word);
            }
        }
        return ans;
    }
};