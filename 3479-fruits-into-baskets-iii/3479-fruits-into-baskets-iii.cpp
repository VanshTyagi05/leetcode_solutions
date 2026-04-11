class Solution {
public:
    void buildtree(int i, int l, int r, vector<int> &segtree,
                   vector<int> &baskets) {
        if (l == r) {
            segtree[i] = baskets[l];
            return;
        }
        int mid = l + (r - l) / 2;
        buildtree(2 * i + 1, l, mid, segtree, baskets);
        buildtree(2 * i + 2, mid + 1, r, segtree, baskets);
        segtree[i] = max(segtree[2 * i + 1], segtree[2 * i + 2]);
        return;
    }

    bool query(int i, int l, int r, vector<int>& segtree, int fruit) {
        if (segtree[i] < fruit) {
            return false;
        }

        // barabr ho jae
        if (l == r) {
            segtree[i] = -1;
            return true;
        }
        int mid = l + (r - l) / 2;
        bool placed = false;
        if (segtree[2 * i + 1] >= fruit) {
            placed = query(2 * i + 1, l, mid, segtree, fruit);
        } else {
            placed = query(2 * i + 2, mid+1, r, segtree, fruit);
        }
        segtree[i]= max(segtree[2 * i + 1], segtree[2 * i + 2]);

        return placed;
    }
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        vector<int> segtree(4 * n,-1);
        buildtree(0, 0, n - 1, segtree, baskets);
        int ans=0;
        for(int fruit:fruits){
          if(!query(0,0,n-1,segtree,fruit)){
            ans++;
          }
        }
        return ans;
    }
};