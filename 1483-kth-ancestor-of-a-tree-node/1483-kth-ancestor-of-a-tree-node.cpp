class TreeAncestor {
public:
    vector<vector<int>>ancestor;
    int cols;
    TreeAncestor(int n, vector<int>& parent) {
        cols=log2(n)+1;
        ancestor.resize(n);
        for(int i=0;i<n;i++){
            ancestor[i].resize(cols,-1);
        }

        // now set values for  j=0 means 2^0=1 jumps above  i.e just above child its parent is there
        for(int node=0;node<n;node++){
            ancestor[node][0]=parent[node];
        }

        for(int j=1;j<cols;j++){
            for(int node=0;node<n;node++){
                if(ancestor[node][j-1]!=-1){
                    ancestor[node][j]=ancestor[ancestor[node][j-1]][j-1];
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for(int j=0;j<cols;j++){
            if((k >> j) & 1){
               node=ancestor[node][j];
               if(node==-1)return -1;
            }
        }

        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */