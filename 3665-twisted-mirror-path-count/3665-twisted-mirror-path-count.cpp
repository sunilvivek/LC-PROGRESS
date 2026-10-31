
class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1e9 + 7;

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<long long>> L(m, vector<long long>(n, 0));
        vector<vector<long long>> U(m, vector<long long>(n, 0));

        // Start position
        L[0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                long long left = L[i][j];
                long long up = U[i][j];

                if (grid[i][j] == 0) {
                    // Empty cell: can move right or down

                    if (j + 1 < n) {
                        L[i][j + 1] =
                            (L[i][j + 1] + left + up) % MOD;
                    }

                    if (i + 1 < m) {
                        U[i + 1][j] =
                            (U[i + 1][j] + left + up) % MOD;
                    }
                }
                else {
                    // Mirror: direction gets changed

                    // Entered from left -> move down
                    if (i + 1 < m) {
                        U[i + 1][j] =
                            (U[i + 1][j] + left) % MOD;
                    }

                    // Entered from above -> move right
                    if (j + 1 < n) {
                        L[i][j + 1] =
                            (L[i][j + 1] + up) % MOD;
                    }
                }
            }
        }

        return (L[m - 1][n - 1] +
                U[m - 1][n - 1]) % MOD;
    }
};
