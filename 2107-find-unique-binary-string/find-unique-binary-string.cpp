class Solution {
public:
    void helper(string &temp,int n,set<string>&st,string &ans){
        if(temp.size()==n ){
            if(st.find(temp)==st.end()){
                ans=temp;
            }
            return;
        }
        temp.push_back('0');
        helper(temp,n,st,ans);
        if(ans!="") return;
        temp.pop_back();
        temp.push_back('1');
        helper(temp,n,st,ans);
        if (ans!="") return;
        temp.pop_back();
    }
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums.size();
        set<string>st;
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        string temp="";
        string ans="";
        helper(temp,n,st,ans);
        return ans;
    }
};