class Solution {
    int mod=1e9+7;
  public:
    int uniquePaths(int r, int c, vector<vector<int>> &grid) {
        if(grid[0][0]==0 or grid[r-1][c-1]==0){
            return 0;
        }
        int dp[r][c];
        dp[0][0]=1;
        //fill the first row
        for(int p=1;p<c;p++){
            if(grid[0][p]==0){
                dp[0][p]=0;
            }else{
                dp[0][p]=dp[0][p-1];
            }
            
        }
        //fill the first col
        for(int p=1;p<r;p++){
            if(grid[p][0]==0){
                dp[p][0]=0;
            }else{
                dp[p][0]=dp[p-1][0];
            }
        }
        //fill the rest
        for(int a=1;a<r;a++){
            for(int b=1;b<c;b++){
                if(grid[a][b]==0){
                    dp[a][b]=0;
                }else{
                    dp[a][b]=(dp[a-1][b]%mod+dp[a][b-1]%mod)%mod;
                }
            }
        }
        return dp[r-1][c-1]%mod;
        
    }
};
