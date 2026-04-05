class Solution {
public:
   long getBucketId(long val,long w){
     return val<0?(val+1)/w - 1:val/w; 
   }
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        int n=nums.size();
        unordered_map<long,long>buckets;
        long w=valueDiff+1;
        for(int i=0;i<n;i++){
            long val=nums[i];
            long id=getBucketId(val,w);

            if(buckets.count(id)) return true;// same bucket mai milgya
            if(buckets.count(id-1) && abs(val-buckets[id-1])<=valueDiff)return true;
            if(buckets.count(id+1) && abs(val-buckets[id+1])<=valueDiff)return true;

            buckets[id]=val;
            // agr 
            if(i>=indexDiff){
                long lastId=getBucketId(nums[i - indexDiff],w);
                buckets.erase(lastId);
                
            }
        }

        return false;
    }
};