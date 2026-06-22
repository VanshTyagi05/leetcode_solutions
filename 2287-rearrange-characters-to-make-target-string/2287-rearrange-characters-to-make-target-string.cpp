class Solution {
public:
    int rearrangeCharacters(string s, string target) {
       //count freq of chars in s
       vector<int>freq_s(26,0);
       for(int i=0;i<s.size();i++){
          freq_s[s[i]-'a']++;
       } 
       // also count the freq of chars in target
       vector<int>freq_t(26,0);
       for(char c:target){
        freq_t[c-'a']++;
       }
        int max_copies = INT_MAX;
        for(char c : target){
            int idx = c - 'a';
            max_copies = min(max_copies, freq_s[idx] / freq_t[idx]);
        }
        
        return max_copies;
       
    }
};