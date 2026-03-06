class Solution {
public:
    bool checkOnesSegment(string s) {
        int n=s.size();
        int transition=0;
       for(int i=0;i<n-1;i++){
          if(s[i]!=s[i+1]){
            transition++;
          }
       }
       return transition>1?false:true;
    }
};