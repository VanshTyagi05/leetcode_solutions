class Solution {
public:
    int size;
    int req;
    set<string> unique_ans;
    void recur(int idx, string& s, string temp, vector<string>& ans,
               int balance) {
        if (temp.size() == req) {
            // means string is of sixe required and also st is empty
            if (balance == 0) {
                // agr stack khali hai sirf tabhi
                if (unique_ans.find(temp) == unique_ans.end()) {
                    unique_ans.insert(temp);
                    ans.push_back(temp);
                }
            }
            return;
        }
        if (idx >= size)
            return; // total size ke bahr nhi ja skte na
        if(balance<0)return;
        // not take
        recur(idx + 1, s, temp, ans, balance);
        // take vali condition
        char ch = s[idx];
        if (ch == '(') {

            recur(idx + 1, s, temp + ch, ans, balance + 1);
        } else if (ch == ')') {
            if (balance > 0) {

                recur(idx + 1, s, temp + ch, ans, balance - 1);
            } else {

                recur(idx + 1, s, temp + ch, ans, balance - 1);
            }
        } else {
            recur(idx + 1, s, temp + ch, ans, balance);
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        stack<char> st;
        size = s.size();
        for (char c : s) {
            if (c == ')') {
                if (!st.empty() && st.top() == '(') {
                    // completepair hogya pop krdo
                    st.pop();
                    continue;
                }
            }
            if (c == '(' || c == ')') {
                st.push(c);
            }
        }
        int extra = st.size();

        // required are size-extra
        req = size - extra;
        // we just need to consider the string of size req
        string temp = "";
        vector<string> ans;
        stack<char> st2;

        recur(0, s, temp, ans, 0);
        return ans;
    }
};