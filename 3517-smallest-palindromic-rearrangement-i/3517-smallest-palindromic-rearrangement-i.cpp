class Solution {
public:
    string smallestPalindrome(string s) {
      vector<int>freq(26,0);
      for(char c:s){
        int idx=c-'a';
        freq[idx]++;
      }
      // in palindrome there can be only 1 character that can have odd count  
      string ans="";
      int odd=-1;
      for(int i=0;i<26;i++){
        int count=freq[i];
        if(count%2!=0)odd=i;
        count/=2;
        for(int k=0;k<count;k++){
            ans+=(i+'a');
        }
      }
      

      string temp=ans;
     if(odd!=-1){
        ans+=(odd+'a');
      }
      for(int i=ans.size()-1;i>=0;i--){
        temp+=ans[i];
      }
     return temp;
      
    }
};