class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        vector<int> last_occur(26, -1);
        for (int i = 0; i < n; i++) {
            last_occur[s[i] - 'a'] = i;
        }

        stack<char> st;
        vector<bool> seen(26, false);

        for (int i = 0; i < n; i++) {
            char ch = s[i];

            // If we already have this char in our stack, skip it
            if (seen[ch - 'a'])
                continue;

            while (!st.empty() && ch < st.top() &&
                   last_occur[st.top() - 'a'] > i) {
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