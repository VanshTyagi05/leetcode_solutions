class Solution {
public:
    int maxDepth(string s) {
        int ans=0;
        int i=0;// iterator 
        stack<int>st;
        while(i<s.size()){
            // add '(' to stack and pop
            if(s[i]=='('){
                st.push(i);
            }
            if(s[i]==')' && s[st.top()]=='('){
                st.pop();
            }
            if(st.size()>ans){
                ans=st.size();
            }
            i++;
        }
        return ans;
    }
};