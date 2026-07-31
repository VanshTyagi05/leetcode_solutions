class Solution {
public:
    int minimumPushes(string word) {
        vector<int>freq(26,0);
        for(char c:word){
            int idx=c-'a';
            freq[idx]++;
        }

        sort(freq.rbegin(),freq.rend());
        int ans=0;
        int i=0;
        int group=1;
        while(group<5){
            for(int k=0;k<8 && i<26;k++){
                ans=ans+(group*freq[i]);
                i++;
            }
            group++;
        }
        return ans;
    }
};