class Solution {
public:
    bool checkRecord(string s) {
        int n = s.size();
        int countA = 0;
        int i = 0;
        while(i<n){
            if (s[i] == 'A') {
                countA++;
                if (countA >= 2)
                    return false;
            }
            if (s[i] == 'L') {
                int countConsecutive = 0;
                for (int j = i; j < i + 3 && j < n; j++) {
                    if (s[j] == 'L') {
                        countConsecutive++;
                    }
                }
                if (countConsecutive == 3) {
                    return false;
                }
            }
            i++;
        }
        return true;
    }
};