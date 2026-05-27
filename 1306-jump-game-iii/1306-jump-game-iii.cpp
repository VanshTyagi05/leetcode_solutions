class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<n;i++){
           int maxi=i+arr[i]; // aage kitna ja skte ho
           int mini=i-arr[i];// piche kitna ja skte hi
           if(maxi<n){
            adj[i].push_back(maxi);
           }
           if(mini>=0){
            adj[i].push_back(mini);
           }
        }


        queue<int>q;
        vector<bool>visited(n);
        q.push(start);
        visited[start]=true;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            visited[it]=true;
            if(arr[it]==0){
                return true;
            }
           for(int neigh:adj[it]){
            if(visited[neigh]==false){
                q.push(neigh);
            }
           }
            
        }

        return false;
    }
};