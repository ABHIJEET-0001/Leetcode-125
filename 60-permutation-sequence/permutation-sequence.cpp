class Solution {
public:
    string getPermutation(int n, int k) {
        
        vector<int> numbers;
        int fact = 1;
        
        for(int i = 1; i < n; i++)
            fact *= i;
        
        for(int i = 1; i <= n; i++)
            numbers.push_back(i);
        
        k--;  // zero-based
        
        string ans = "";
        
        while(true) {
            
            int index = k / fact;
            ans += to_string(numbers[index]);
            
            numbers.erase(numbers.begin() + index);
            
            if(numbers.empty())
                break;
            
            k %= fact;
            fact /= numbers.size();
        }
        
        return ans;
    }
};
