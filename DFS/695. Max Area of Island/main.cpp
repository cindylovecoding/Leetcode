class Solution {
public:
    int height,width;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        height = grid.size();
        width = grid[0].size();
        int ans = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    ans = max(ans,dfs(grid,i,j));
                }
            }
        }
        return ans;
    }
    int dfs(vector<vector<int>>& grid,int i,int j){
        int num;
        if(grid[i][j] == 1){
            num = 1;
            grid[i][j] = 0;
            int upx = j,upy=i-1;
            int rx = j+1,ry=i;
            int lx = j-1,ly=i;
            int downx = j,downy=i+1;
            if((upy >=0 && upy <height)&&(upx>=0 && upx <width))
                if(grid[upy][upx] == 1)
                    num += dfs(grid,upy,upx);
                
            if((ry >=0 && ry <height)&&(rx>=0 && rx <width))
                if(grid[ry][rx] == 1)
                    num += dfs(grid,ry,rx);
                
            if((ly >=0 && ly <height)&&(lx>=0 && lx <width))
                if(grid[ly][lx] == 1)
                    num += dfs(grid,ly,lx);
                
            if((downy >=0 && downy <height)&&(downx>=0 && downx <width))
                if(grid[downy][downx] == 1)
                    num += dfs(grid,downy,downx);
                
            return num;
        }
        else{
            return 0;
        }
    }
};
