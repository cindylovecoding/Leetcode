class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int dp[nums.size()];
        int count[nums.size()];
        for(int i =0;i<nums.size();i++){
            dp[i] = 1;
            count[i] = 1;
        }
        
        for(int i =1;i<nums.size();i++)
            for(int j =0;j<i;j++){
                if(nums[j]<nums[i]){
                    if(dp[i]==dp[j]+1) 
                        count[i]+= count[j];
                    else if(dp[j]+1 > dp[i]){
                        dp[i]= dp[j]+1;
                        count[i] = count[j];
                    }
                }
            }
            
        int big = -0x3f3f3f3f;
        for(int i=0;i<nums.size();i++)
            big = max(dp[i],big);
            
        
        int ans = 0;
        for(int i=0;i<nums.size();i++)
            if(dp[i] == big) ans+=count[i];
        
        return ans;
    }
};
