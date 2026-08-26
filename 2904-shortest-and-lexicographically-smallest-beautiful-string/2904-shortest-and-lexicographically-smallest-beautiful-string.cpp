class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();

        int start = 0;
        int end = 0;
        int count = 0;

        string final_ans = "";

        while (end < n) {

            // right pointer se window bada karo
            if (s[end] == '1') {
                count++;
            }

            // jab exactly k ones mil gaye
            while (count == k) {

                // pehle left ke unnecessary zero hatao
                while (start <= end && s[start] == '0') {
                    start++;
                }

                // ab [start...end] ek valid beautiful substring hai
                string curr = s.substr(start, end - start + 1);

                // answer update karo
                if (final_ans == "" ||
                    curr.size() < final_ans.size() ||
                    (curr.size() == final_ans.size() && curr < final_ans)) {
                    final_ans = curr;
                }

                // ab leftmost 1 hatao
                if (s[start] == '1') {
                    count--;
                }

                start++;
            }

            end++;
        }

        return final_ans;
    }
};