#include <climits>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {

        // Special overflow case
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        // Determine sign of result
        bool negative = (dividend < 0) ^ (divisor < 0);

        // Convert to long long and take absolute values
        long long a = llabs((long long)dividend);
        long long b = llabs((long long)divisor);

        long long result = 0;

        // Bit shifting approach
        while (a >= b) {
            long long temp = b;
            long long multiple = 1;

            while (a >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }

            a -= temp;
            result += multiple;
        }

        // Apply sign
        if (negative)
            result = -result;

        return result;
    }
};
