#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        int n = digits.size();

        // Traverse from last digit
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;      // Add 1
                return digits;    // Done
            }
            digits[i] = 0;        // Carry over
        }

        // If all digits were 9
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
