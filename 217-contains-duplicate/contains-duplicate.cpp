class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> st;

        for(int num : nums) {
            if(st.count(num)) {
                return true;
            }
            st.insert(num);
        }

        return false;
    }
};