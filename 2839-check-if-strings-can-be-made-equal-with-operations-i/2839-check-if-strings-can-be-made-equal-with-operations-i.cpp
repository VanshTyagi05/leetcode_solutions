class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        string temp=s2;
        if(s1[0]!=s2[0]){
            swap(temp[0],temp[2]);
        }
        if(s1[1]!=s2[1]){
            swap(temp[1],temp[3]);
        }
        if(temp==s1)return true;
        return false;

    }
};