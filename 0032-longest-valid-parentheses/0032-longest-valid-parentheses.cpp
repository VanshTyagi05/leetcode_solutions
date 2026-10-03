class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st; // Store indices of unmatched parentheses
        int n = s.size();
        int ans = 0;

        // Traverse the string and manage the stack
        for (int i = 0; i < n; i++) {
            if (!st.empty() && s[i] == ')' && s[st.top()] == '(') {
                st.pop(); // Valid pair found, remove '(' index
            } else {
                st.push(i); // Push index of unmatched parenthesis
            }
        }

        // Calculate the longest valid parentheses substring
        // If the stack is empty, the entire string is valid
        if (st.empty()) {
            return n;
        }

        // Process remaining indices in the stack
        int last_idx = n; // Start with the end of the string
        while (!st.empty()) {
            int current_idx = st.top();
            st.pop();
            ans = max(ans, last_idx - current_idx - 1);
            last_idx = current_idx;
        }

        // Consider the substring from the start to the first unmatched index
        ans = max(ans, last_idx);

        return ans;
    }
};
