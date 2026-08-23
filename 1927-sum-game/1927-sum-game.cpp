class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int left = 0, right = 0, qL = 0, qR = 0;
        
        for(int i = 0; i < n; i++){
            if(i < n / 2){
                if(num[i] == '?'){
                    qL++;
                } else {
                    left += (num[i] - '0');
                }
            } else {
                if(num[i] == '?'){
                    qR++;
                } else {
                    right += (num[i] - '0');
                }
            }
        }
        
        // Remove abs(). Keep the direction intact.
        // If (left - right) is positive, then (qR - qL) must also be positive.
        return (2 * (left - right) != 9 * (qR - qL));
    }
};
