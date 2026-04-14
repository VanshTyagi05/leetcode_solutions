class RangeFreqQuery {
public:
    unordered_map<int, vector<int>> mp;
    
    RangeFreqQuery(vector<int>& arr) {
        for (int i = 0; i < arr.size(); i++) {
            mp[arr[i]].push_back(i);
        }
    }

    int query(int left, int right, int value) {
        if (mp.find(value) == mp.end()) return 0;
        
        const vector<int>& temp = mp[value];

        // Manual Lower Bound: First index in 'temp' where temp[mid] >= left
        int l_idx = getLowerBound(temp, left);
        
        // Manual Upper Bound: First index in 'temp' where temp[mid] > right
        int r_idx = getUpperBound(temp, right);

        return r_idx - l_idx;
    }

private:
    int getLowerBound(const vector<int>& temp, int target) {
        int low = 0, high = temp.size();
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (temp[mid] >= target) high = mid;
            else low = mid + 1;
        }
        return low;
    }

    int getUpperBound(const vector<int>& temp, int target) {
        int low = 0, high = temp.size();
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (temp[mid] > target) high = mid;
            else low = mid + 1;
        }
        return low;
    }
};
