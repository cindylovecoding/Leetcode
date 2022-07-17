class Solution{
  public:
    int minHeightShelves(vector<vector<int>>& books,int shlefWidth){
      int N = books.size();
      books.insert(books.begin(),{0,0});
      vector<int> dp ( N + 1, 0x3f3f3f3f);
      dp[0] = 0;
      for(int i = 1;i <= N;i++){
        int w = books[i][0];
        int h = books[i][1];
        dp[i] = dp[i-1] + h;
        int j = i-1;
        while(j>=1 && w+books[j][0] <= shlefWidth){
          w += books[j][0];
          h = max(h , books[j][1]);
          dp[i] = min (dp[i],dp[j-1] + h);
          j--;
        }
      }
      return dp[N];
    }
};
