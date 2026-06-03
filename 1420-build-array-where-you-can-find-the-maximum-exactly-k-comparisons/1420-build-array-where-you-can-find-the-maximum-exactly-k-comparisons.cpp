class Solution {
public:
   int N,M,K;
   int Mod=1e9+7;
   int dp[52][53][102];
   int solve(int idx,int searchCost,int maxSoFar){
    if(idx>=N){
        if(searchCost==K){
            return 1;
        }
        return 0;
    }

    if(dp[idx][searchCost][maxSoFar+1]!=-1){
        return dp[idx][searchCost][maxSoFar+1];
    }
    int result=0;
    for(int i=1;i<=M;i++){
        if(i>maxSoFar){
            result=(result+solve(idx+1,searchCost+1,i))%Mod;
        }else{
            result=(result+solve(idx+1,searchCost,maxSoFar))%Mod;
        }
    }

    return dp[idx][searchCost][maxSoFar+1]=result;
   }
    int numOfArrays(int n, int m, int k) {
        N=n;
        M=m;
        K=k;
        memset(dp,-1,sizeof(dp));
        return solve(0,0,-1);
    }
};