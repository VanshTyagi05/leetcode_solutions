class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        unordered_map<int, pair<int, int>> mp;
        for (int i = 0; i < n; i++) {
            int color = colors[i];
            if (mp.find(color) == mp.end()) {
                // first time hai
                mp[color] = {i, i};
            } else {
                // first wale mai minimum daal do second vale aimaxmum
                mp[color].first = min(mp[color].first, i);
                mp[color].second = max(mp[color].second, i);
            }
        }

        // now we wil itreate on the map and find two things min left most and maximum rightmost from two different  colors
        int leftmost_color=colors[0];
        int leftmost_idx=INT_MAX;
        // finding the minimum idx leftmost_idx for some leftmost_color
        for(auto const& [key,it]:mp){
             if(it.first<leftmost_idx){
                leftmost_idx=it.first;
                leftmost_color=key;
             }
        }
          int rightmost_idx=INT_MIN;
        // finding the maximum idx leftmost_idx for some color!=leftmost_color
        for(auto const& [key,it]:mp){
             if(it.second>rightmost_idx  && key!=leftmost_color){
                rightmost_idx=it.second;
             }
        }

        return abs(rightmost_idx-leftmost_idx);
    }
};