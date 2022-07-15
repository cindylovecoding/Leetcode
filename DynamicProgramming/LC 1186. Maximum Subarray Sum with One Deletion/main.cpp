class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int dp[arr.size()][2];
        dp[0][0] = arr[0];
        dp[0][1] = arr[0];
        for(int i = 1;i < arr.size();i++){
            dp[i][0] = max(dp[i-1][0] + arr[i],arr[i]);
            dp[i][1] = max(dp[i-1][1] + arr[i], dp[i-1][0]);
        }
        int ans = -0x3f3f3f3f;
        for(int i = 0; i < arr.size();i++){
            ans = max(ans, max(dp[i][0],dp[i][1]));
        }
        return ans;
    }
};
