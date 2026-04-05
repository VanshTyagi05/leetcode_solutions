class Solution {
public:
    bool judgeCircle(string s) {
        int x=0;
        int y=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='U'){
                y++;
            }else if(s[i]=='D'){
                y--;
            }else if(s[i]=='L'){
                x--;
            }else{
                x++;
            }
        }

        return true?(x==0 && y==0):false;
    }
};