class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if ((m + n - 1) % 2 != 0)
            return false;

        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(')
            return false;

        int maxBalance = m + n;

        vector<vector<vector<bool>>> dp(
            m,
            vector<vector<bool>>(
                n,
                vector<bool>(maxBalance + 1, false)
            )
        );

        dp[0][0][1] = true;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0)
                    continue;

                for (int balance = 0; balance <= maxBalance; balance++) {
                    int prevBalance;

                    if (grid[i][j] == '(') {
                        if (balance == 0)
                            continue;
                        prevBalance = balance - 1;
                    } else {
                        prevBalance = balance + 1;
                    }

                    if (i > 0 && dp[i - 1][j][prevBalance])
                        dp[i][j][balance] = true;

                    if (j > 0 && dp[i][j - 1][prevBalance])
                        dp[i][j][balance] = true;
                }
            }
        }

        return dp[m - 1][n - 1][0];
    }
};