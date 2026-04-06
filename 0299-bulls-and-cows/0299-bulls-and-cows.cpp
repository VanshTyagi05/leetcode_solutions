class Solution {
public:
    string getHint(string secret, string guess) {
         vector<int>sec(10,0); // frequency count of digits for secret
         vector<int>ges(10,0); // frequency count digits for guess
      
        int i=0;// iterator 
        int n=secret.size();
        int bulls=0;
        int cows=0;
        while(i<n){
            if(secret[i]==guess[i]){
                bulls++;
            }else{

                sec[secret[i]-'0']++;
                ges[guess[i]-'0']++;
            }
            i++;
        }

        for(int i=0;i<10;i++){
            cows+=min(sec[i],ges[i]);
        }

        return to_string(bulls)+"A"+to_string(cows)+"B";
    }
};