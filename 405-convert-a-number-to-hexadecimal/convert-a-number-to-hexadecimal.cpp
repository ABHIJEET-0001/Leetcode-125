class Solution {
public:
    string toHex(int num) {

        if(num == 0)
            return "0";

        unsigned int n = num;

        string hex = "0123456789abcdef";
        string result = "";

        while(n > 0) {
            result = hex[n % 16] + result;
            n /= 16;
        }

        return result;
    }
};