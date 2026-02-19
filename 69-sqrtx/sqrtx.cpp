class Solution {
public:
    int mySqrt(int x) {
        if(x == 0 || x == 1)
            return x;

        long long low = 1, high = x;
        long long ans = 0;

        while(low <= high) {
            long long mid = low + (high - low) / 2;

            if(mid * mid == x)
                return mid;
            else if(mid * mid < x) {
                ans = mid;        // store possible answer
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;
    }
};
