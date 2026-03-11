class Solution {
public:
    int longestPalindrome(string s) {

        vector<int> freq(128,0);

        for(char c : s)
            freq[c]++;

        int length = 0;
        bool oddFound = false;

        for(int count : freq){

            if(count % 2 == 0)
                length += count;
            else{
                length += count - 1;
                oddFound = true;
            }
        }

        if(oddFound)
            length += 1;

        return length;
    }
};