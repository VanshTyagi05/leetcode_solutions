#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size() + 1;
        const int MOD = 1000000007;
        
        // 1. Build adjacency list
        vector<vector<int>> adj(n + 1);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        // Determine the maximum log steps required
        int LOG = log2(n) + 2;
        vector<vector<int>> up(n + 1, vector<int>(LOG, 0));
        vector<int> depth(n + 1, 0);
        
        // 2. Iterative DFS using a stack to compute parent array and depths
        // Stack stores pairs of {current_node, parent_node}
        vector<pair<int, int>> st;
        st.push_back({1, 0});
        depth[1] = 0;
        
        vector<bool> visited(n + 1, false);
        visited[1] = true;
        
        while (!st.empty()) {
            auto [curr, p] = st.back();
            st.pop_back();
            
            up[curr][0] = p;
            
            for (int neighbor : adj[curr]) {
                if (neighbor != p) {
                    depth[neighbor] = depth[curr] + 1;
                    st.push_back({neighbor, curr});
                }
            }
        }
        
        // 3. Populate binary lifting table
        for (int j = 1; j < LOG; ++j) {
            for (int i = 1; i <= n; ++i) {
                if (up[i][j - 1] != 0) {
                    up[i][j] = up[up[i][j - 1]][j - 1];
                }
            }
        }
        
        // 4. Precompute powers of 2 for O(1) answering
        vector<int> pow2(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            pow2[i] = (pow2[i - 1] * 2) % MOD;
        }
        
        // Lambda function to find LCA using binary lifting
        auto get_lca = [&](int u, int v) {
            if (depth[u] < depth[v]) swap(u, v);
            
            // Bring both nodes to the same depth level
            int diff = depth[u] - depth[v];
            for (int j = 0; j < LOG; ++j) {
                if ((diff >> j) & 1) {
                    u = up[u][j];
                }
            }
            
            if (u == v) return u;
            
            // Lift both nodes simultaneously
            for (int j = LOG - 1; j >= 0; --j) {
                if (up[u][j] != up[v][j]) {
                    u = up[u][j];
                    v = up[v][j];
                }
            }
            return up[u][0];
        };
        
        // 5. Answer all queries
        vector<int> ans;
        ans.reserve(queries.size());
        
        for (const auto& q : queries) {
            int u = q[0];
            int v = q[1];
            
            if (u == v) {
                ans.push_back(0); // Graph length 0 cannot have an odd sum
            } else {
                int lca = get_lca(u, v);
                int k = depth[u] + depth[v] - 2 * depth[lca];
                ans.push_back(pow2[k - 1]);
            }
        }
        
        return ans;
    }
};
