class Solution {
public:
    string reverseParentheses(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(s[i]!=')'){
                st.push(s[i]);
            }
            else{
                string test="";
                while(st.top()!='('){
                    test+=st.top();
                    st.pop();
                }
                st.pop();
                for(int i=0;i<test.size();i++){
                    st.push(test[i]);
                }
            }
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};