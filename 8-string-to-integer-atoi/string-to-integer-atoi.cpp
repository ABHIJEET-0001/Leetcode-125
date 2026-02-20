class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.length();
        
        // 1️⃣ Skip leading spaces
        while(i < n && s[i] == ' ')
            i++;
        
        // 2️⃣ Handle sign
        int sign = 1;
        if(i < n && (s[i] == '+' || s[i] == '-')) {
            if(s[i] == '-')
                sign = -1;
            i++;
        }
        
        // 3️⃣ Convert digits
        long result = 0;
        
        while(i < n && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');
            
            // 4️⃣ Check overflow
            if(sign * result >= INT_MAX)
                return INT_MAX;
            if(sign * result <= INT_MIN)
                return INT_MIN;
            
            i++;
        }
        
        return sign * result;
    }
};