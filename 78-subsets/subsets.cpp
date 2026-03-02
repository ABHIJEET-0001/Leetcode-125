class Solution {
public:
    vector<vector<int>> result;

    void backtrack(vector<int>& nums, int start, vector<int>& current) {
        result.push_back(current);

        for(int i = start; i < nums.size(); i++) {
            current.push_back(nums[i]);
            backtrack(nums, i + 1, current);
            current.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> current;
        backtrack(nums, 0, current);
        return result;
    }
};