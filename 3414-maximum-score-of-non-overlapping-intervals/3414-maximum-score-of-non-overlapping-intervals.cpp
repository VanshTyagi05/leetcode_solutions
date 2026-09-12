#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// Custom structure to store the optimal result for a state
struct Result {
    long long score;
    vector<int> indices;
};

class Solution {
private:
    // Structure to represent interval along with its original index
    struct Interval {
        int l, r, weight, id;
        bool operator<(const Interval& other) const {
            if (l != other.l) return l < other.l;
            if (r != other.r) return r < other.r;
            return weight < other.weight;
        }
    };

    int n;
    vector<Interval> arr;
    // DP Memoization Table: memo[index][count]
    // Since count can be 0 to 4, size 5 is enough
    vector<vector<Result>> memo;
    vector<vector<bool>> visited;

    // Helper function to find the first interval that starts after the current ends
    int getNextIndex(int target_r) {
        int low = 0, high = n - 1, ans = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid].l > target_r) { // Strict greater because sharing boundary is overlapping
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    Result solve(int i, int count) {
        // Base case: agar saare intervals khatam ya quota full ho gaya
        if (i >= n || count == 0) {
            return {0, {}};
        }

        if (visited[i][count]) {
            return memo[i][count];
        }

        // Choice 1: Current interval ko skip karo
        Result skipRes = solve(i + 1, count);

        // Choice 2: Current interval ko include karo
        int nextIdx = getNextIndex(arr[i].r);
        Result takeRes = solve(nextIdx, count - 1);
        
        // Naye score ko update karo aur index list mein original ID insert karo
        long long currentScore = arr[i].weight + takeRes.score;
        vector<int> currentIndices = takeRes.indices;
        currentIndices.push_back(arr[i].id);
        // Hamein indices sorted format mein check/maintain karni hoti hain lexicographical compare ke liye
        sort(currentIndices.begin(), currentIndices.end()); 

        Result includeRes = {currentScore, currentIndices};

        // Decision logic based on Max Score and Lexicographical small path
        Result best;
        if (includeRes.score > skipRes.score) {
            best = includeRes;
        } else if (skipRes.score > includeRes.score) {
            best = skipRes;
        } else {
            // Agar score tie ho jaye, toh lexicographically smaller array choose karo
            if (includeRes.indices < skipRes.indices) {
                best = includeRes;
            } else {
                best = skipRes;
            }
        }

        visited[i][count] = true;
        return memo[i][count] = best;
    }

public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        n = intervals.size();
        arr.resize(n);
        
        for (int i = 0; i < n; i++) {
            arr[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};
        }

        // Sort intervals by start time
        sort(arr.begin(), arr.end());

        memo.assign(n, vector<Result>(5));
        visited.assign(n, vector<bool>(5, false));

        Result finalAns = solve(0, 4);
        return finalAns.indices;
    }
};
