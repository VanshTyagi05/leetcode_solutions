class Solution {
public:
    vector<int> t;
    bool solve(int n) {
        if (n == 0) {
            return false;
        }
        if(t[n]!=-1)return t[n];
        for (int k = 1; k * k <= n; k++) {
            if (solve(n - (k * k)) == false) {
                // agr k*k alice le leta hai toh bob ke liye n-(k*k) bachega
                // uske liye call krdo bas
                return t[n]=true;
            }
        }
        return t[n]=false;
    }
    bool winnerSquareGame(int n) { 
        t.assign(n+1,-1);
        return solve(n);
     }
};