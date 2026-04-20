class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int currentNum = 0;
        char op = '+'; // Track the operator BEFORE the current number

        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                currentNum = currentNum * 10 + (s[i] - '0');
            }

            // Process if it's an operator OR the end of the string
            if ((!isdigit(s[i]) && s[i] != ' ') || i == s.size() - 1) {
                if (op == '+')
                    st.push(currentNum);
                else if (op == '-')
                    st.push(-currentNum);
                else if (op == '*') {
                    int top = st.top();
                    st.pop();
                    st.push(top * currentNum);
                } else if (op == '/') {
                    int top = st.top();
                    st.pop();
                    st.push(top / currentNum);
                }
                op = s[i]; // Update to the NEW operator
                currentNum = 0;
            }
        }

        int result = 0;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        return result;
    }
};