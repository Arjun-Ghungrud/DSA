class Solution {
public:
    vector<int> buildLPS(vector<int>& pat) {
        int m = pat.size();
        vector<int> lps(m, 0);
        int len = 0, i = 1;

        while (i < m) {
            if (pat[i] == pat[len]) {
                lps[i++] = ++len;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i++] = 0;
                }
            }
        }
        return lps;
    }

    bool KMPSearch(vector<int>& pat, vector<int>& txt) {
        int m = pat.size(), n = txt.size();
        if (m == 0) return true;
        if (m > n) return false;

        vector<int> lps = buildLPS(pat);
        int i = 0, j = 0;

        while (i < n) {
            if (pat[j] == txt[i]) {
                i++;
                j++;
            }

            if (j == m) {
                return true;
            } else if (i < n && pat[j] != txt[i]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }

        return false;
    }
    bool poss(vector<int>& vec1,vector<int>& vec2){
        vector<int>text=vec2;
        text.insert(end(text),begin(vec2),end(vec2));
        return KMPSearch(vec1,text);
    }
    int sortableIntegers(vector<int>& nums) {
        int n=nums.size();
        vector<int>s=nums;
        sort(nums.begin(),nums.end());
        int res=0;
        for(int k=1;k<=n;k++){
            if(n%k!=0)continue;
            bool valid=true;
            for(int st=0;st<n;st+=k){
                vector<int>vec1(begin(nums)+st,begin(nums)+st+k);
                vector<int>vec2(begin(s)+st,begin(s)+st+k);
                if(!poss(vec1,vec2)){
                    valid=false;
                    break;
                }
            }
            if(valid)res+=k;
        }
        return res;
    }
};