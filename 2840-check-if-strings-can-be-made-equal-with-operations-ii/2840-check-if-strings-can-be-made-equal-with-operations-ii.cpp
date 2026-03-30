class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n=s1.size();
        string even_st1,odd_st1;
        string even_st2,odd_st2;
        for(int i=0;i<n;i++){
            char ch1=s1[i];
            char ch2=s2[i];
            if(i%2==0){
              // even index
              even_st1+=ch1;
              even_st2+=ch2;
            }else{
              odd_st1+=ch1;
              odd_st2+=ch2;
            }
        }
        sort(even_st1.begin(),even_st1.end());
        sort(even_st2.begin(),even_st2.end());
        if(even_st1!=even_st2)return false;
        sort(odd_st1.begin(),odd_st1.end());
        sort(odd_st2.begin(),odd_st2.end());
        if(odd_st1!=odd_st2)return false;

        return true;
    }
};