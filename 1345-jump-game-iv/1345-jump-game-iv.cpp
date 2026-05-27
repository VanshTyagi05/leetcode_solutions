class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return 0;

        // Group indices by their values
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }

        // Standard BFS queue stores: {index, current_steps}
        queue<pair<int, int>> q; 
        vector<bool> visited(n, false);

        q.push({0, 0});
        visited[0] = true;

        while (!q.empty()) {
            auto [node, curr_steps] = q.front();
            q.pop();

            // Reached the destination
            if (node == n - 1) return curr_steps;

            // Option 1: Move forward
            if (node + 1 < n && !visited[node + 1]) {
                visited[node + 1] = true;
                q.push({node + 1, curr_steps + 1});
            }

            // Option 2: Move backward
            if (node - 1 >= 0 && !visited[node - 1]) {
                visited[node - 1] = true;
                q.push({node - 1, curr_steps + 1});
            }

            // Option 3: Jump to identical values
            int val = arr[node];
            if (mp.count(val)) {
                for (int neigh : mp[val]) {
                    if (!visited[neigh]) {
                        visited[neigh] = true;
                        q.push({neigh, curr_steps + 1});
                    }
                }
                // CRITICAL OPTIMIZATION: Clear the list to avoid duplicate scans
                mp.erase(val); 
            }
        }

        return 0;
    }
};
