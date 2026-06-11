class Solution {
public:
    long long MOD = 1e9 + 7;
    long long power(long long base, long long exponent) {
        if (exponent == 0) {
            return 1;
        }
        long long half = power(base, exponent / 2);
        long long result = (half * half) % MOD;
        if (exponent % 2 == 1) {
            result = (result * base) % MOD;
        }
        return result;
    }
    int getDepth(int node, int parent, unordered_map<int, vector<int>>& adj) {

        int maxDepth = 0;
        for (int ngbr : adj[node]) {
            if (ngbr == parent)
                continue;
            maxDepth = max(maxDepth, getDepth(ngbr, node, adj) + 1);
        }

        return maxDepth;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int d = getDepth(1, 0, adj);

        return power(2, d - 1);
    }
};