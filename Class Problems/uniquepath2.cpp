#include<bits/stdc++.h>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) return 0;

    vector<vector<long long>> dp(m, vector<long long>(n, 0));
    dp[0][0] = 1;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(obstacleGrid[i][j] == 1) {
                dp[i][j] = 0;
            } else if(i == 0 && j == 0) {
                dp[i][j] = 1;
            } else {
                if(i > 0) dp[i][j] += dp[i-1][j];
                if(j > 0) dp[i][j] += dp[i][j-1];
            }
        }
    }

    return dp[m-1][n-1];
}

int main() {
    vector<vector<int>> grid = {{0,0,0},{0,1,0},{0,0,0}};
    cout << uniquePathsWithObstacles(grid) << endl;
    return 0;
}
