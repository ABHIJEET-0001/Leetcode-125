class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        
        int n = nums.size();
        int count = 1;
        int maxLen = 1;

        for(int i = 1; i < n; i++) {

            if(nums[i] > nums[i-1]) {
                count++;
            }
            else {
                count = 1;
            }

            maxLen = max(maxLen, count);
        }

        return maxLen;
    }
};