class Solution {
public:
   int M = 1e9+7;
   int memo[5001][10];
    vector<vector<int>> adj = {
        {4, 6},
        {6, 8},
        {7, 9},
        {4, 8},
        {3, 9, 0},
        {},
        {1, 7, 0},
        {2, 6},
        {1, 3},
        {2, 4}
    };
    int helper(int n,int cell){
        if(n==0)return 1; // ek valid move or jum mil gya hai aur tum total number of jumps zero ho chuke hai
        if(memo[n][cell]!=-1){
            return memo[n][cell];
        }
        int ans=0;
        for(int nextcell:adj[cell]){
            ans=(ans+helper(n-1,nextcell))%M;
        }
        return memo[n][cell]=ans;
    }
    int knightDialer(int n) {
        int result=0;
        memset(memo,-1,sizeof(memo));
        // stating from each of 10 cellls
        for(int i=0;i<=9;i++){
            result=(result+helper(n-1,i))%M;
        }
        return result;
    }
};