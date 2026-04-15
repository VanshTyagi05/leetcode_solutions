class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int goingforward = 0;
        int i = startIndex;
        int n = words.size();
        while (words[i] != target) {
            i = (i + 1) % n;
            goingforward++;
            if(goingforward>n)return -1;
        }
        i = startIndex;
        int goingbackword = 0;
        while (words[i] != target) {
            i = (i - 1 + n) % n;
            goingbackword++;
        }

        return min(goingforward, goingbackword);
    }
};