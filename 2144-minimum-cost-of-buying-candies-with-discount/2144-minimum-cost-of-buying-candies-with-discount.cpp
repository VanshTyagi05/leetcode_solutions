class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        int n=cost.size();
        int ans=0;
        if(n<=2){
            for(int i=0;i<n;i++){ ans+= cost[i];}
            return ans;
         }

         int j=n-1;
         int mincos;
         while(j>=0){
            // ek bar check krlo ki kya ab bas 2 ya ek candy bachi hai
            if(j<=1){
               for(int i=0;i<=j;i++){
                ans+=cost[i];
               }
               return ans;
            }
           ans+=cost[j];
            ans+=cost[j-1];
            mincos=min(cost[j],cost[j-1]);
            if(cost[j-2]<=mincos){
                j=j-3;
                // skip the next candy because itsss bought
                continue;
            }else{
                j=j-2;
            }

         }

         return ans;
    }
};