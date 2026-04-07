class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.size();
        vector<int> last_occur(26, -1);
        for (int i = 0; i < n; i++) {
            last_occur[s[i] - 'a'] = i;
        }

        stack<char> st;
        vector<bool> seen(26, false); // Tracks if char is currently in the stack

        for (int i = 0; i < n; i++) {
            char ch = s[i];

            // If we already have this char in our stack, skip it
            if (seen[ch - 'a']) continue;

            // While:
            // 1. Stack isn't empty
            // 2. Current char is smaller than the top
            // 3. The top char appears again later
            while (!st.empty() && ch < st.top() && last_occur[st.top() - 'a'] > i) {
                seen[st.top() - 'a'] = false; // Mark as not in stack
                st.pop();
            }

            st.push(ch);
            seen[ch - 'a'] = true;
        }

        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
