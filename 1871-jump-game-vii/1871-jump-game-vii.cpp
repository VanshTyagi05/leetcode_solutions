class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        if (s[n - 1] != '0')
            return false; // end agr 0 nhi hoga toh lund phouvhoge
        queue<int> q;
        q.push(0); // index that is reachable

        for (int i = 1; i < n; i++) {
            if (s[i] == '1')
                continue; // kuch nhi kr skte

            // jo iindex bhout dur hai aur reach ke bahr hai unko hata do
            while (!q.empty() && q.front() < i - maxJump) {
                q.pop();
            }
            // jo index reach mai hai unko add krdo
            if (!q.empty() && q.front() <= i - minJump) {
                q.push(i); // i reavhable hai
            }
        }
        return (!q.empty() && q.back() == n - 1) ? true : false;
    }
};