class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n=word.size();
        vector<int>lower(26,-1e9);
        vector<int>upper(26,1e9);
        for(int i=0;i<n;i++){
            char ch=word[i];
            if(ch>='a' && ch<='z'){
                lower[ch-'a']=max(lower[ch-'a'],i);
            }else {
                upper[ch-'A']=min(upper[ch-'A'],i);
            }
        }

        int ans=0;
        for(int i=0;i<26;i++){
            if(lower[i]!=-1e9 && upper[i]!=1e9 && lower[i]<upper[i]){
                ans++;
                
            }
        }

        return ans;
    }
};