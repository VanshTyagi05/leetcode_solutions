class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> freq(5, 0);
        // b->0
        // a->1
        // l->2
        // o->3
        // n->4
        for (int i = 0; i < text.size(); i++) {
            if (text[i] == 'b') {
                freq[0]++;
            } else if (text[i] == 'a') {
                freq[1]++;
            } else if (text[i] == 'l') {
                freq[2]++;
            } else if (text[i] == 'o') {
                freq[3]++;
            } else if (text[i] == 'n') {
                freq[4]++;
            }else{
                // kuch bhi nhi
            }
        }

        freq[2]/=2;
        freq[3]/=2;
        int ans=INT_MAX;
        for(int i=0;i<5;i++){
            ans=min(ans,freq[i]);
        }

        return ans;
    }
};