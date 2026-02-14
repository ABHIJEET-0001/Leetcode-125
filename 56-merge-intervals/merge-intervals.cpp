class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        if(intervals.size() <= 1)
            return intervals;
        
        // Step 1: Sort
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> result;
        
        // Step 2: Push first interval
        result.push_back(intervals[0]);
        
        // Step 3: Traverse
        for(int i = 1; i < intervals.size(); i++) {
            
            // last merged interval
            vector<int>& last = result.back();
            
            // overlap condition
            if(intervals[i][0] <= last[1]) {
                last[1] = max(last[1], intervals[i][1]);
            } 
            else {
                result.push_back(intervals[i]);
            }
        }
        
        return result;
    }
};
