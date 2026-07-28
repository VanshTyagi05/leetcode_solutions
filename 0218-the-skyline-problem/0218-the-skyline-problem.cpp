class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        // Ek event list banayenge jisme har element hoga: {x_coordinate, height, isStart}
        // isStart = 1 matlab building shuru ho rahi hai, 0 matlab khatam ho rahi hai
        vector<vector<int>> events;
        
        for (const auto& building : buildings) {
            int left = building[0];
            int right = building[1];
            int height = building[2];
            
            events.push_back({left, height, 1});  // 1 = building starts
            events.push_back({right, height, 0}); // 0 = building ends
        }

        // Events ko sort karenge. X-coordinate ke saath-saath tie-cases ko handle karna zaroori hai:
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] != b[0]) {
                return a[0] < b[0]; // Pehle x-coordinate ke basis par sort karo
            }
            // Agar x-coordinate same hai, toh ye tie-breaking rules lagenge:
            if (a[2] != b[2]) {
                return a[2] > b[2]; // Start event (1) pehle aana chahiye End event (0) se
            }
            if (a[2] == 1) {
                return a[1] > b[1]; // Agar dono Start hain, toh badi height pehle aayegi
            }
            return a[1] < b[1];     // Agar dono End hain, toh choti height pehle aayegi
        });

        // Java ke PriorityQueue ki tarah active heights track karne ke liye multiset use karenge
        // Kyunki C++ priority_queue me kisi specific element ko beech se delete (.remove()) nahi kar sakte.
        multiset<int> activeHeights;
        vector<vector<int>> skyline;
        int previousMax = 0;

        // Saare events ko ek ek karke process karenge (Sweep-line)
        for (const auto& event : events) {
            int x = event[0];
            int height = event[1];
            bool isStart = (event[2] == 1);

            if (isStart) {
                activeHeights.insert(height); // Building shuru hui toh height heap me daal do
            } else {
                // Building khatam hui toh heap se us height ki ek instance remove kar do
                auto it = activeHeights.find(height);
                if (it != activeHeights.end()) {
                    activeHeights.erase(it);
                }
            }

            // Agar heap empty hai toh currentMax 0 hoga, nahi toh sabse badi height (last element)
            int currentMax = activeHeights.empty() ? 0 : *activeHeights.rbegin();

            // Agar maximum height me koi change aaya hai, toh ye ek skyline turning point hai
            if (currentMax != previousMax) {
                skyline.push_back({x, currentMax});
                previousMax = currentMax;
            }
        }

        return skyline;
    }
};
