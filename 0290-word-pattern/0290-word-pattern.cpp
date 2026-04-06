class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> mp;
        unordered_map<string, char> mp2;

        int i = 0; // string s ka iterator
        int k = 0; // pattern ka iterator
        int n1 = pattern.size();
        int n2 = s.size();

        while (i < n2) {
            // 1. Agar string bachi hai par pattern khatam ho gaya
            if (k >= n1)
                return false;

            string temp = "";
            // 2. Word nikalne ke liye loop
            while (i < n2 && s[i] != ' ') {
                temp += s[i];
                i++;
            }

            // 3. Mapping check (Dono taraf se)
            if (mp.count(pattern[k]) && mp[pattern[k]] != temp)
                return false;
            if (mp2.count(temp) && mp2[temp] != pattern[k])
                return false;

            // 4. Nayi mapping insert karo
            mp[pattern[k]] = temp;
            mp2[temp] = pattern[k];

            // 5. Agle word par jane ke liye space skip karo
            i++;
            k++;
        }

        // 6. Final check: Dono poore khatam hone chahiye
        // Agar k < n1 reh gaya, iska matlab pattern bada tha aur words kam the
        return k == n1;
    }
};
