class Solution {
public:
    int waviness(int n){
        string num=to_string(n);
        int ans=0;
        for(int i=1;i<num.size()-1;i++){
            if((num[i]>num[i-1] && num[i]>num[i+1] ) || (num[i]<num[i-1] && num[i]<num[i+1] )){
                ans++;
            }
        }
        return ans;
    }
    int totalWaviness(int num1, int num2) {
        int result=0;
        for(int i=num1;i<=num2;i++){
          result+=waviness(i);
        }
        return result;
    }
};