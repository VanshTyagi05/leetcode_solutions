class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        int n=words.size();
        vector<int>word_weight(n,0);
        for(int i=0;i<n;i++){
            string sr=words[i];
            int sum=0;
            for(char ch:sr){
                sum+=weights[ch-'a'];
            }
            word_weight[i]=sum;
        }

        // now we have to just reverse map
        //For each word, take its weight modulo 26 and map the result to a lowercase English letter using reverse alphabetical order (0 -> 'z', 1 -> 'y', ..., 25 -> 'a').
        string ans="";
        for(int i=0;i<n;i++){
            int currweight=word_weight[i]%26;
            ans+=('z'-currweight);
        }
        return ans;
    }
};