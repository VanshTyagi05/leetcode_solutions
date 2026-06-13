class Solution {
public:
    int n; // number of node
    int cols;
    int M = 1e9 + 7;
    unordered_map<int, vector<int>> adj;
    vector<vector<int>> ancestor;
    vector<int> depth;

    void dfs(int node, int parent) {
        ancestor[node][0] = parent;
        for (int ngbr : adj[node]) {
            if (ngbr == parent) {
                continue;
            } else {
                depth[ngbr] = depth[node] + 1;
                dfs(ngbr, node);
            }
        }
    }

    void buildAncestorTable() {
        for (int j = 1; j < cols; j++) {
            for (int node = 0; node < n; node++) {
                if (ancestor[node][j - 1] != -1) {
                    ancestor[node][j] = ancestor[ancestor[node][j - 1]][j - 1];
                }
            }
        }
    }

    int findLCA(int u, int v) {
        if (depth[u] < depth[v]) {
            swap(u, v);
        }

        int k = depth[u] - depth[v];
        // phle same level pe laaaa hoga uske liye k level upar jana hoga
        for (int j = 0; j < cols; j++) {
            if (k & (1 << j)) {
                u = ancestor[u][j];
            }
        }
        if (u == v) { // both were on the same path
            return u; // LCA
        }
        // ab same level pe aachuka hai toh dono ko same dteps upar lekr jate
        // rho lekin strting mai badi jump lo
        for (int j = cols - 1; j >= 0; j--) {
            if (ancestor[u][j] == -1)
                continue; // invalid jump hai
            if (ancestor[u][j] != ancestor[v][j]) {
                u = ancestor[u][j];
                v = ancestor[v][j]; // dono ko 2^j stpe upar phouvha do
            }
        }

        return ancestor[u]
                       [0]; // just u ke upar unka LCA hi baitha hoga last mai
    }
    vector<int> assignEdgeWeights(vector<vector<int>>& edges,
                                  vector<vector<int>>& queries) {
        // mainly hume nikalna hai isme distance between two node in O(logn)
        // time me

        // thoda sa gemotery ke sath khelel
        // d(u,v)= depth(u)+depth(v)-2*depth(LCA(u,v));
        n = edges.size() + 1;
        cols = log2(n) + 1;
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0] - 1;
            int v = edges[i][1] - 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        depth.resize(n);
        depth[0] = 0; // root node ki depth toh zero hi ahi
        ancestor.resize(n, vector<int>(cols, -1));
        // dfs call krdo jisse ki har node ki dpeth pta chl jae
        dfs(0, -1); // bcz zero ka koi parent nhi hai
        buildAncestorTable();
        // 2 ki powr baar baar na compute kr i pde toh pehle hi store kro
        vector<int> pow2(n + 1);
        pow2[0] = 1;
        for (int i = 1; i <= n; i++) {
            pow2[i] = (2LL * pow2[i - 1]) % M;
        }
        // aur iske baad apna answer find kregee
        vector<int> answer;
        for (int i = 0; i < queries.size(); i++) {
            int u = queries[i][0] - 1;
            int v = queries[i][1] - 1;
            int depth_u = depth[u];
            int depth_v = depth[v];
            int LCA = findLCA(u, v);
            int d = depth_u + depth_v - 2 * depth[LCA];
            if (d == 0) {
                answer.push_back(0);
            } else {
                int curr_ans = pow2[d - 1];
                answer.push_back(curr_ans);
            }
        }
        return answer;
    }
};