#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int n = nums.size();
        
        if (n < 4) return result;

        // Step 1: Sort the array
        sort(nums.begin(), nums.end());

        // Step 2: Fix first number
        for (int i = 0; i < n - 3; i++) {
            
            // Skip duplicate for i
            if (i > 0 && nums[i] == nums[i - 1]) 
                continue;

            // Step 3: Fix second number
            for (int j = i + 1; j < n - 2; j++) {
                
                // Skip duplicate for j
                if (j > i + 1 && nums[j] == nums[j - 1]) 
                    continue;

                // Two pointers
                int left = j + 1;
                int right = n - 1;

                while (left < right) {
                    // Use long long to prevent overflow
                    long long sum = (long long)nums[i] 
                                  + nums[j] 
                                  + nums[left] 
                                  + nums[right];

                    if (sum == target) {
                        result.push_back({
                            nums[i], nums[j], nums[left], nums[right]
                        });

                        // Skip duplicates for left
                        while (left < right && nums[left] == nums[left + 1])
                            left++;

                        // Skip duplicates for right
                        while (left < right && nums[right] == nums[right - 1])
                            right--;

                        left++;
                        right--;
                    }
                    else if (sum < target) {
                        left++;   // Need bigger sum
                    }
                    else {
                        right--;  // Need smaller sum
                    }
                }
            }
        }
        return result;
    }
};
