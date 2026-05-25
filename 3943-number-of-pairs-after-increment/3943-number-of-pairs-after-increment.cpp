class Solution {
public:
    
    int n;
    vector<long long> nums;

    int blockSize;
    int blocks;

    // har block ke liye lazy addition
    vector<long long> lazy;

    // har block ke liye frequency map
    vector<unordered_map<long long,int>> freq;


    // block ki freq map rebuild karne vala function
    void rebuild(int b) {

        freq[b].clear();

        int start = b * blockSize;
        int end = min(n, start + blockSize);

        for(int i=start; i<end; i++) {
            freq[b][nums[i]]++;
        }
    }

    
    vector<int> numberOfPairs(vector<int>& nums1,
                              vector<int>& nums2,
                              vector<vector<int>>& queries) {

        nums.assign(nums2.begin(), nums2.end());

        n = nums.size();

        blockSize = sqrt(n) + 1;

        blocks = (n + blockSize - 1) / blockSize;

        lazy.assign(blocks,0);

        freq.resize(blocks);


        // initial frequency build
        for(int b=0; b<blocks; b++) {
            rebuild(b);
        }

        vector<int> ans;


        for(auto &q : queries) {

            // ---------------- UPDATE QUERY ----------------
            if(q[0] == 1) {

                int l = q[1];
                int r = q[2];
                int val = q[3];

                int leftBlock = l / blockSize;
                int rightBlock = r / blockSize;


                // CASE 1 :
                // l aur r same block me hai
                if(leftBlock == rightBlock) {

                    // lazy ko actual values me push karo
                    for(int i = leftBlock * blockSize;
                        i < min(n, (leftBlock + 1) * blockSize);
                        i++) {

                        nums[i] += lazy[leftBlock];
                    }

                    lazy[leftBlock] = 0;


                    // range update
                    for(int i=l; i<=r; i++) {
                        nums[i] += val;
                    }

                    rebuild(leftBlock);
                }

                // CASE 2 :
                // multiple blocks involved
                else {

                    // -------- LEFT PARTIAL BLOCK --------

                    // pehle lazy apply karo
                    for(int i = leftBlock * blockSize;
                        i < min(n, (leftBlock + 1) * blockSize);
                        i++) {

                        nums[i] += lazy[leftBlock];
                    }

                    lazy[leftBlock] = 0;

                    // required range update
                    for(int i=l;
                        i < min(n, (leftBlock + 1) * blockSize);
                        i++) {

                        nums[i] += val;
                    }

                    rebuild(leftBlock);


                    // -------- FULL BLOCKS --------

                    for(int b = leftBlock + 1;
                        b < rightBlock;
                        b++) {

                        lazy[b] += val;
                    }


                    // -------- RIGHT PARTIAL BLOCK --------

                    // lazy apply karo
                    for(int i = rightBlock * blockSize;
                        i < min(n, (rightBlock + 1) * blockSize);
                        i++) {

                        nums[i] += lazy[rightBlock];
                    }

                    lazy[rightBlock] = 0;

                    // required update
                    for(int i = rightBlock * blockSize;
                        i <= r;
                        i++) {

                        nums[i] += val;
                    }

                    rebuild(rightBlock);
                }
            }

            // ---------------- COUNT QUERY ----------------
            else {

                long long tot = q[1];

                long long cnt = 0;

                
                // nums1 ka size max 5 hai
                for(int a : nums1) {

                    long long need = tot - a;

                    
                    // har block check karo
                    for(int b=0; b<blocks; b++) {

                        // actual value = stored + lazy
                        // stored value chahiye:
                        long long req = need - lazy[b];

                        if(freq[b].count(req)) {
                            cnt += freq[b][req];
                        }
                    }
                }

                ans.push_back(cnt);
            }
        }

        return ans;
    }
};