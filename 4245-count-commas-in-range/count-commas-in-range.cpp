class Solution {
public:
    long long countCommas(int n) {

        long long result = 0;   // stores total commas

        long long base = 1000;  // first number where comma starts

        while(base <= n) {

            // count numbers from base to n
            result += (n - base + 1);

            // move to next level (1000 → 1000000 → ...)
            base *= 1000;
        }

        return result;
    }
};