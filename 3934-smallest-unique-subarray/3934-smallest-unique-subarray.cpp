class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        
        // Hash collision se bachne ke liye bade primes select kiye hain
        long long MOD = 1e11 + 7;  
        long long BASE = 313;
        
        // Yeh helper function check karega ki kya 'length' size ka koi unique subarray hai
        auto has_unique_subarray = [&](int length) -> bool {
            unordered_map<long long, int> hash_counts;
            long long current_hash = 0;
            
            // highest_power = (BASE^(length - 1)) % MOD
            // Jab window slide hogi, toh sabse pehle element ko hatane ke liye iska use hoga
            long long highest_power = 1;
            for (int i = 0; i < length - 1; ++i) {
                highest_power = (highest_power * BASE) % MOD;
            }
            
            // Step 1: Pehli window (0 se leke length-1 tak) ka hash nikal rahe hain
            for (int i = 0; i < length; ++i) {
                current_hash = (current_hash * BASE + nums[i]) % MOD;
            }
            hash_counts[current_hash] = 1;
            
            // Step 2: Window ko aage badha rahe hain (Sliding Window)
            for (int i = length; i < n; ++i) {
                // Jo element peeche chhut raha hai usko remove karo
                long long out_elem = nums[i - length];
                current_hash = (current_hash - out_elem * highest_power) % MOD;
                
                // Naye aane wale element ko hash mein add karo
                current_hash = (current_hash * BASE + nums[i]) % MOD;
                
                // C++ mein modulo negative aa sakta hai, isliye isko hamesha positive rakho
                if (current_hash < 0) {
                    current_hash += MOD;
                }
                
                // Is hash ki frequency count badhao
                hash_counts[current_hash]++;
            }
            
            // Step 3: Check karo ki kya koi bhi aisa hash hai jo sirf 1 baar aaya ho
            for (auto& pair : hash_counts) {
                if (pair.second == 1) {
                    return true; // Haan, unique subarray mil gaya!
                }
            }
            return false; // Koi unique subarray nahi mila is length ka
        };

        // Binary Search lagayenge answer space par (Minimum length 1 ho sakti hai, max n)
        int low = 1, high = n;
        int ans = n;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (has_unique_subarray(mid)) {
                ans = mid;         // Agar mil gaya, toh isko potential answer maan lo
                high = mid - 1;    // Aur chhota answer dhoondne ki koshish karo
            } else {
                low = mid + 1;     // Agar nahi mila, toh window size bada karna padega
            }
        }
        
        return ans;
    }
};
