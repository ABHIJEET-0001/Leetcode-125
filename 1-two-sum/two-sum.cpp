class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Using unordered_map for O(1) lookups
        unordered_map<int, int> mpp; 
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            int moreNeeded = target - num;
            
            // If the complement exists in the map, return the indices
            if (mpp.find(moreNeeded) != mpp.end()) {
                return {mpp[moreNeeded], i};
            }
            
            // Otherwise, store the current number and its index in the map
            mpp[num] = i;
        }
        
        // Return empty vector if no solution is found (though the problem guarantees one)
        return {}; 
    }
};