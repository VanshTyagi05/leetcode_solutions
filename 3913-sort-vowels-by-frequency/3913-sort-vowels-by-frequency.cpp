class Solution {
public:
   bool isVowel(char ch){
        return ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u';
    }
    string sortVowels(string s) {
        int n = s.size();
        unordered_map<char, int> mp;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
                s[i] == 'u') {
                mp[s[i]]++;
            }
        }

        vector<pair<char, int>> v;
        for (auto it : mp) {
            v.push_back({it.first, it.second});
        }

        sort(v.begin(), v.end(), [](pair<char, int> a, pair<char, int> b) {
            return a.second < b.second;
        });

        stack<char> st;
        for (int i = 0; i < v.size(); i++) {
            while (v[i].second--)
                st.push(v[i].first);
        }
        for (int i = 0; i < s.size(); i++) {
            if (isVowel(s[i])) {
                char ch = st.top();
                s[i] = ch;
                st.pop();
            }
        }
        return s;
    }
};