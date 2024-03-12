//https://leetcode.com/problems/unique-paths-ii/?envType=study-plan-v2&envId=top-interview-150
//using recursion as well as dynamic programming
class Solution {
public:
    // void helperFunction( vector<vector<int>>& grid, int m, int n, int x, int y, int& count,
    //                                                                          set<int>& paths )
    // {
    //     if ( x>=m || y>=n || grid[x][y] )
    //         return;

    //     count++;
    //     if ( x == m-1 && y == n-1 && !grid[x][y] )
    //     {
    //         paths.insert( count );   
    //         return;
    //     }

    //     helperFunction( grid, m, n, x+1, y, count, paths );
    //     helperFunction( grid, m, n, x, y+1, count, paths );
    // }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
        // int x = 0;
        // int y = 0;
        // int count = 0;
        // set<int> paths;

        // helperFunction( obstacleGrid, m, n, x, y, count, paths );
        //return paths.size();
        
        const int m = obstacleGrid.size();
        const int n = obstacleGrid[0].size();
        if ( obstacleGrid[0][0] || obstacleGrid[m-1][n-1] )
            return 0;
        
        vector<vector<int>> dp(m,vector<int>(n,0));
        dp[0][0] = 1;

        for ( int idx=0; idx<m; idx++ )
        {
            if ( obstacleGrid[idx][0] )
                break;

            dp[idx][0] = 1;
        }
        
        for ( int idx=0; idx<n; idx++ )
        {
            if ( obstacleGrid[0][idx] )
                break;

            dp[0][idx] = 1;
        }

        for ( int idx=1; idx<m; idx++ )
        {
            for ( int jidx=1; jidx<n; jidx++ )
            {
                if ( obstacleGrid[idx][jidx] )
                    continue;

                const int up = dp[idx-1][jidx];
                const int down = dp[idx][jidx-1];
                dp[idx][jidx] = up+down;
            }
        }
        

        return dp[m-1][n-1];
    }
};
