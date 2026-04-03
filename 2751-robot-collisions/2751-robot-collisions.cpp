class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions,
                                      vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> indices(n);
        for (int i = 0; i < n; i++)
            indices[i] = i;

        // Sort indices based on positions to process robots from left to right
        sort(indices.begin(), indices.end(),
             [&](int a, int b) { return positions[a] < positions[b]; });

        stack<int> st; // Stores indices of robots moving 'R'

        for (int idx : indices) {
            if (directions[idx] == 'R') {
                st.push(idx);
            } else {
                // Robot moving 'L' collides with 'R' robots in the stack
                while (!st.empty() && healths[idx] > 0) {
                    int top_idx = st.top();

                    if (healths[top_idx] > healths[idx]) {
                        // Stack robot survives, current 'L' robot dies
                        healths[top_idx] -= 1;
                        healths[idx] = 0;
                    } else if (healths[top_idx] < healths[idx]) {
                        // Current 'L' robot survives, stack robot dies
                        healths[idx] -= 1;
                        healths[top_idx] = 0;
                        st.pop(); // Remove the dead 'R' robot
                    } else {
                        // Both die
                        healths[idx] = 0;
                        healths[top_idx] = 0;
                        st.pop(); // Remove the dead 'R' robot
                    }
                }
            }
        }

        vector<int> ans;
        for (int h : healths) {
            if (h > 0)
                ans.push_back(h);
        }
        return ans;
    }
};
