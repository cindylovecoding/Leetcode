class Solution{
public:
  bool isInterleave(string s1,string s2,string s3){
    int len1 = s1.size(),len2 = s2.size(),len3 = s3.size();
    if(len3 != len1 + len2) return false;
    s1 = "#" + s1;
    s2 = "#" + s2;
    s3 = "#" + s3;
    vector<vector<bool>> dp (len1+1,vector<bool>(len2+1,false));
    dp[0][0] = true;
    for(int i=1;i<=len1;i++)
      if(s3[i] == s1[i]) dp[i][0] = dp[i-1][0];
    for(int j=1;j<=len2;j++)
      if(s3[j] == s2[j]) dp[0][j] = dp[0][j-1];
    for(int i=1;i<=len1;i++){
      for(int j=1;j<=len2;j++){
        if(s3[i+j] == s1[i])
          dp[i][j] = dp[i-1][j];
        else if(s3[i+j] == s2[j])
          dp[i][j] = dp[i][j-1];
      }
    }    
    return dp[len1][len2];
  }
};
