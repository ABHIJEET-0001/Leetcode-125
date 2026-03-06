class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end(),
             [](vector<int>& a, vector<int>& b){
                 return a[1] < b[1];
             });

        int count = 0;
        int prevEnd = intervals[0][1];

        for(int i = 1; i < intervals.size(); i++) {

            if(intervals[i][0] < prevEnd) {
                count++;  // remove interval
            }
            else {
                prevEnd = intervals[i][1];
            }
        }

        return count;
    }
};