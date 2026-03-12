class Solution {
public:
    int N; // total size gloablly declared 
    int M=1e9+7;
    //int  Ls is declard to check if previous two are L if yes then we cant take L again
    // int As will track total absents if greater than two not consideres
    int memo[100001][2][3];
    int helper(int Ls,int curr_size,int As ){
         
         if(As>=2)return 0;
         if(Ls>=3)return 0;
         if(curr_size==N)return 1;
         // sum of all possible cases
         if(memo[curr_size][As][Ls]!=-1)return memo[curr_size][As][Ls];
         long long res=0;
        res=helper(0,curr_size+1,As);
        res=(res+helper(Ls+1,curr_size+1,As))%M;
        res=(res+helper(0,curr_size+1,As+1))%M;
        return memo[curr_size][As][Ls]=res;
    }
    int checkRecord(int n) {
        N=n;
        for(int i=0; i<=n; i++)
            for(int j=0; j<2; j++)
                for(int k=0; k<3; k++)
                    memo[i][j][k] = -1;
        return helper(0,0,0);
    }
};