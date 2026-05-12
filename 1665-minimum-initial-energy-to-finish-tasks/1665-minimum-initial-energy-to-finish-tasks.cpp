#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        // Sort by the difference (minimum - actual) descending
        sort(tasks.begin(), tasks.end(), [](const vector<int>& a, const vector<int>& b) {
            return (a[1] - a[0]) > (b[1] - b[0]);
        });

        int totalInitialEnergy = 0;
        int currentEnergy = 0;

        for (const auto& task : tasks) {
            int actual = task[0];
            int minimum = task[1];

            // If we don't have enough to even start the task
            if (currentEnergy < minimum) {
                // Add the missing gap to our starting capital
                totalInitialEnergy += (minimum - currentEnergy);
                // After adding, we now have exactly the minimum required
                currentEnergy = minimum;
            }
            
            // Spend the actual energy
            currentEnergy -= actual;
        }

        return totalInitialEnergy;
    }
};
