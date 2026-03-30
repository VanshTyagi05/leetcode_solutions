class Solution {
public:
    bool check(string s) {
        int n = s.size();
        // if the size of string is 1 that is always possible so return true
        if (n == 1) {
            return true;
        }
        // if we have length >3 or string starts with 0 return false
        if (n > 3 || s[0] == '0') {
            return false;
        }
        // we are converting string to integer to check if it is less than
        // equalto 255
        int val = stoi(s);
        if (val > 255) {
            return false;
        }
        // return true at last
        return true;
    }
    vector<string> restoreIpAddresses(string s) {
        int n = s.size();
        vector<string> ans;
        if (n < 4 || n > 12)
            return ans;

        for (int i = 1; i <= 3; i++) { // for the length before first '.'
            for (int j = 1; j <= 3;
                 j++) { // for the lenght between first and second '.'
                for (int k = 1; k <= 3;
                     k++) { // for the lenght bw second and third '.'
                    if (i + j + k < n && i + j + k + 3 >= n) {
                        string a = s.substr(0, i);
                        string b = s.substr(i, j);
                        string c = s.substr(i + j, k);
                        string d = s.substr(i + j + k);
                        if (check(a) && check(b) && check(c) && check(d)) {
                            ans.push_back(a + "." + b + "." + c + "." + d);
                        }
                    }
                }
            }
        }
        return ans;
    }
};