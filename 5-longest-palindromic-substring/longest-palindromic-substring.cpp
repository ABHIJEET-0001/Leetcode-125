class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() <= 1) return s;

        int start = 0, end = 0;

        auto expand = [&](int left, int right) {
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                left--;
                right++;
            }
            return pair<int,int>(left + 1, right - 1);
        };

        for (int i = 0; i < s.size(); i++) {

            // Odd length palindrome
            auto [l1, r1] = expand(i, i);

            if (r1 - l1 > end - start) {
                start = l1;
                end = r1;
            }

            // Even length palindrome
            auto [l2, r2] = expand(i, i + 1);

            if (r2 - l2 > end - start) {
                start = l2;
                end = r2;
            }
        }

        return s.substr(start, end - start + 1);
    }
};