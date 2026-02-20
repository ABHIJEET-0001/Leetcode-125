class Solution {
public:
    string countAndSay(int n) {
        string result = "1";
        
        for(int i = 2; i <= n; i++) {
            string current = result;
            string next = "";
            
            int count = 1;
            
            for(int j = 1; j < current.length(); j++) {
                if(current[j] == current[j-1]) {
                    count++;
                } else {
                    next += to_string(count);
                    next += current[j-1];
                    count = 1;
                }
            }
            
            // Add last group
            next += to_string(count);
            next += current.back();
            
            result = next;
        }
        
        return result;
    }
};
