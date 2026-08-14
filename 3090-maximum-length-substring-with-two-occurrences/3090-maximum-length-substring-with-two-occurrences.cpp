class Solution {
public:
   bool solve(string s,int start,int end){
      vector<int>freq(26,0);
      for(int i=start;i<=end;i++){
        freq[s[i]-'a']++;
      }

      for(int i=0;i<26;i++){
        if(freq[i]>2)return false;
      }
      return true;
   }
    int maximumLengthSubstring(string s) {
        int count=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(solve(s,i,j)==true){
                    count=max(count,j-i+1);
                };
            }
        }
        return count;
    }
};