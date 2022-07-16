class Solution {
public:
    long long int dp[57][57][57];
    const int MAX_N = 1000000000 + 7;
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp, 0, sizeof(dp));
        dp[0][startRow][startColumn] = 1;
        for(int i = 1;i<maxMove;i++){
            for(int j = 0;j<m;j++){
                for(int k = 0;k<n;k++){
                    dp[i][j][k] = 0;
                    int up = 0,down = 0,right = 0,left = 0;
                    if(j-1>=0 )
                        dp[i][j][k] = (dp[i][j][k] + dp[i-1][j-1][k]) %MAX_N;
                    if(j+1<m)
                        dp[i][j][k] = (dp[i][j][k] + dp[i-1][j+1][k]) %MAX_N;
                    if(k-1>=0)
                        dp[i][j][k] = (dp[i][j][k] + dp[i-1][j][k-1]) %MAX_N;
                    if(k+1<n)
                        dp[i][j][k] = (dp[i][j][k] + dp[i-1][j][k+1]) %MAX_N;
                }
            }
        }
        long long int sum = 0;
        
        for(int i=0;i<maxMove;i++){
            for(int j=0;j<m;j++){
                sum += dp[i][j][0];
                sum += dp[i][j][n-1];
            }
            for(int k=0;k<n;k++){
                sum += dp[i][0][k];
                sum += dp[i][m-1][k];
            }
        }
        return sum % MAX_N;
    }
};
