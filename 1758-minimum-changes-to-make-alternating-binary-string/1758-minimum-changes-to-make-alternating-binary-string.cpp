class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        int first_way=0; // string starting as 0
        for(int i=0;i<n;i++){
            //010101....
            // even pe zero hoga 
            if(i%2==0 && s[i]=='1'){
                first_way++; 
            }
            //odd pe 1 hoga
            if(i%2!=0 && s[i]=='0'){
                first_way++;
            }
        }
        int second_way=0;// string starting as 1
         for(int i=0;i<n;i++){
            //101010....
            // even pe 1 hona chahiye agr 0 hua toh change hoga
            if(i%2==0 && s[i]=='0'){
                second_way++;
            }
            //odd pe 0 hona chahiye agr 1 hua toh change hoga
            if(i%2!=0 && s[i]=='1'){
                second_way++;
            }
        }

        return min(first_way,second_way);
    }
};