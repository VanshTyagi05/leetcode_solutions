class Solution {
public:
    int calculate(string s) {
        stack<pair<int, int>> st; // {total, sign}
        long long total = 0;
        int sign = 1;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            if (isdigit(s[i])) {
                long long num = 0;
                while (i < n && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                total += num * sign;
                i--; // Step back because the outer loop increments i
            } else if (s[i] == '+') {
                sign = 1;
            } else if (s[i] == '-') {
                sign = -1;
            } else if (s[i] == '(') {
                // Save the state before the parenthesis
                st.push({total, sign});
                total = 0;
                sign = 1;
            } else if (s[i] == ')') {
                // Result = (Result inside bracket * Sign before bracket) + Total before bracket
                total = st.top().first + (st.top().second * total);
                st.pop();
            }
        }
        return (int)total;
    }
};
