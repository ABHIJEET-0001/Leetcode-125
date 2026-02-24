class NumArray {
public:
    vector<int> prefix;

    NumArray(vector<int>& nums) {
        int n = nums.size();
        prefix.resize(n + 1);
        prefix[0] = 0;

        for(int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        return prefix[right + 1] - prefix[left];
    }
};