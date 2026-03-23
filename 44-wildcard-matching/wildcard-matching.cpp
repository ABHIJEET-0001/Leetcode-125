class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return solve(0, 0, s, p, dp);
    }

    bool solve(int i, int j, string &s, string &p, vector<vector<int>> &dp) {
        int n = s.size(), m = p.size();

        // base case
        if(i == n && j == m) return true;
        if(j == m) return false;

        if(i == n) {
            for(int k = j; k < m; k++) {
                if(p[k] != '*') return false;
            }
            return true;
        }

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == p[j] || p[j] == '?') {
            return dp[i][j] = solve(i+1, j+1, s, p, dp);
        }

        if(p[j] == '*') {
            return dp[i][j] = solve(i, j+1, s, p, dp) || solve(i+1, j, s, p, dp);
        }

        return dp[i][j] = false;
    }
};