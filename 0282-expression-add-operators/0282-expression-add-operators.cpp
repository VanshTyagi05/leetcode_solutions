class Solution {
public:
    vector<string> ans;

    // currR: abhi tak ka total result
    // prevNum: pichla number jo add/sub/mul kiya tha (Multiplication undo karne ke liye)
    void solve(int idx, string num, int target, string path, long currR, long prevNum) {
        // Base Case: Agar string khatam ho gayi aur result target ke barabar hai
        if (idx == num.size()) {
            if (currR == target) ans.push_back(path);
            return;
        }

        for (int j = idx; j < num.size(); j++) {
            // Leading zero check: "05" allow nahi hai, sirf "0" allow hai
            if (j > idx && num[idx] == '0') break;

            string s = num.substr(idx, j - idx + 1);
            long n = stol(s); // Current substring ko number mein convert kiya

            if (idx == 0) {
                // Pehla number: Iske pehle koi operator nahi aayega
                solve(j + 1, num, target, s, n, n);
            } else {
                // 1. ADD: Normal addition
                solve(j + 1, num, target, path + "+" + s, currR + n, n);

                // 2. SUBTRACT: Normal subtraction, prevNum negative ho jayega
                solve(j + 1, num, target, path + "-" + s, currR - n, -n);

                // 3. MULTIPLY: BODMAS handle karne ke liye pichla operation undo karo
                // Formula: (Total - Previous) + (Previous * Current)
                solve(j + 1, num, target, path + "*" + s, (currR - prevNum) + (prevNum * n), prevNum * n);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        if (num.empty()) return {};
        solve(0, num, target, "", 0, 0);
        return ans;
    }
};
