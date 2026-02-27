class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        // Step 1: Find correct row
        int top = 0, bottom = m - 1;
        int row = -1;

        while(top <= bottom) {
            int mid = top + (bottom - top) / 2;

            if(target >= matrix[mid][0] && target <= matrix[mid][n - 1]) {
                row = mid;
                break;
            }
            else if(target < matrix[mid][0]) {
                bottom = mid - 1;
            }
            else {
                top = mid + 1;
            }
        }

        if(row == -1) return false;

        // Step 2: Binary search in that row
        int left = 0, right = n - 1;

        while(left <= right) {
            int mid = left + (right - left) / 2;

            if(matrix[row][mid] == target)
                return true;
            else if(matrix[row][mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return false;
    }
};