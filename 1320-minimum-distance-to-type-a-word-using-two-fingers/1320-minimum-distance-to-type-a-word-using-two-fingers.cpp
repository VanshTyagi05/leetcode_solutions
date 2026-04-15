class Solution {
public:
    int dp[301][7][7][7][7];
    pair<int,int> getcoord(char ch){
        int cur=ch-'A';
        return {cur/6,cur%6};
    }

    int getdist(int x1,int y1,int x2,int y2){
       return abs(x1-x2)+abs(y1-y2);
    }
    int solve(string word,int i,int x1,int y1,int x2,int y2){
        if(i>=word.size()){
            return 0;
        }
        if(x1>=0 && y1>=0 && x2>=0 && y2>=0 && dp[i][x1][y1][x2][y2]!=-1)return dp[i][x1][y1][x2][y2];
         char ch=word[i];
         auto [x,y]=getcoord(ch);
         int result=INT_MAX;
        // if non of the finger is used erlier we can use any finger 
        if(x1==-1 && y1==-1 && x2==-1 && y2==-1){
            //use finger 1 means finger1 will now moe to x and y
            return solve(word,i+1,x,y,x2,y2);
        }
        // if f2 is not used already
        if(x2==-1 && y2==-1){
            // use it and dont use f1 as its already used 
            int movef2=0+solve(word,i+1,x1,y1,x,y);
            int moveF1=getdist(x1,y1,x,y)+solve(word,i+1,x,y,x2,y2);
            return min(movef2,moveF1);
        }

        //both areused already 
        int move1=getdist(x1,y1,x,y)+solve(word,i+1,x,y,x2,y2);
        int move2=getdist(x2,y2,x,y)+solve(word,i+1,x1,y1,x,y);

        return dp[i][x1][y1][x2][y2]=min(move1,move2);
    }
    int minimumDistance(string word) {
        memset(dp,-1,sizeof(dp));
      return solve(word,0,-1,-1,-1,-1);
    }
};