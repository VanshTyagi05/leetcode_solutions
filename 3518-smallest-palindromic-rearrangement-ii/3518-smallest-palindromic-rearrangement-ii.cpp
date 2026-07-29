class Solution {
private:
    // Yeh function bache huye characters se total permutations nikalta hai, 
    // par overflow se bachne ke liye 'limit' par truncate kar deta hai.
    long long countTotalPerms(const vector<int>& counts, long long limit) {
        long long total_perms = 1;
        int n = 0;
        
        for (int c : counts) {
            if (c == 0) continue;
            // C(n, k) format mein calculations kar rahe hain taaki intermediate overflow na ho
            for (int i = 1; i <= c; ++i) {
                n++;
                // Yeh C(n, i) ka direct updates hai
                total_perms = total_perms * n / i;
                
                // AGAR PERMUTATIONS LIMIT SE BADI HO JAYE, TOH WAHI STOP KARDO
                if (total_perms > limit) {
                    return limit + 1; // Safely return dynamic ceiling
                }
            }
        }
        return total_perms;
    }

public:
    string smallestPalindrome(string s, long long k) {
        // Step 1: Har character ki frequency count karo
        vector<int> total_counts(26, 0);
        for (char c : s) {
            total_counts[c - 'a']++;
        }
        
        int odd_count = 0;
        char mid_char = '#';
        for (int i = 0; i < 26; ++i) {
            if (total_counts[i] % 2 != 0) {
                odd_count++;
                mid_char = (char)('a' + i);
            }
        }
        
        // Agar ek se zyada character odd frequency ke hain toh palindrome impossible hai
        if (odd_count > 1) return "";
        
        // Step 2: Left half ke liye characters ka pool ready karo
        vector<int> half_counts(26, 0);
        int half_length = 0;
        for (int i = 0; i < 26; ++i) {
            half_counts[i] = total_counts[i] / 2;
            half_length += half_counts[i];
        }
        
        // Agar total permutations k se kam hain, toh sequence exist nahi karti
        long long limit = k + 2; // Hum safe window limit bana rahe hain
        if (countTotalPerms(half_counts, limit) < k) {
            return "";
        }
        
        // Step 3 & 4: Left half ko digit-by-digit fill karo
        string left_half = "";
        
        for (int pos = 0; pos < half_length; ++pos) {
            for (int i = 0; i < 26; ++i) {
                if (half_counts[i] > 0) {
                    // Try placing character 'a' + i
                    half_counts[i]--;
                    
                    // Bache hue combination check karo aur limit lagao
                    long long perms = countTotalPerms(half_counts, limit);
                    
                    if (k <= perms) {
                        // Agar k combinations ke range mein hai, toh yeh character final hai
                        left_half += (char)('a' + i);
                        break;
                    } else {
                        // Agar range se bahar hai, toh is pure block ko skip karke k chota karo
                        k -= perms;
                        // Backtrack / Rollback karo
                        half_counts[i]++;
                    }
                }
            }
        }
        
        // Complete palindrome construct karo mirroring ke saath
        string right_half = string(left_half.rbegin(), left_half.rend());
        if (mid_char != '#') {
            return left_half + mid_char + right_half;
        }
        return left_half + right_half;
    }
};
