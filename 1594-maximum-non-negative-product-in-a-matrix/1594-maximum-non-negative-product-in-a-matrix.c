#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

long long max(long long a, long long b) { return a > b ? a : b; }
long long min(long long a, long long b) { return a < b ? a : b; }

int maxProductPath(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = gridColSize[0];

    // Using long long to store products because 4^30 exceeds 32-bit int
    long long max_dp[15][15];
    long long min_dp[15][15];

    max_dp[0][0] = min_dp[0][0] = grid[0][0];

    // Initialize the first column
    for (int i = 1; i < m; i++) {
        max_dp[i][0] = min_dp[i][0] = max_dp[i - 1][0] * grid[i][0];
    }

    // Initialize the first row
    for (int j = 1; j < n; j++) {
        max_dp[0][j] = min_dp[0][j] = max_dp[0][j - 1] * grid[0][j];
    }

    // Fill the DP table
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            long long val = grid[i][j];
            
            // Calculate 4 possibilities: (prev_max * val) or (prev_min * val)
            // from either the top cell or the left cell.
            long long a = max_dp[i - 1][j] * val;
            long long b = min_dp[i - 1][j] * val;
            long long c = max_dp[i][j - 1] * val;
            long long d = min_dp[i][j - 1] * val;

            max_dp[i][j] = max(max(a, b), max(c, d));
            min_dp[i][j] = min(min(a, b), min(c, d));
        }
    }

    long long final_max = max_dp[m - 1][n - 1];

    // If the max product is negative, return -1 as per the problem rule.
    if (final_max < 0) return -1;
    
    return (int)(final_max % MOD);
}