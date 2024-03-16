//https://leetcode.com/problems/number-of-islands/?envType=study-plan-v2&envId=top-interview-150
class Solution {
public:
    void helper( vector<vector<char>>& grid, int x, int y, int n, int m )
    {
        if ( x < 0 || y < 0 || x>=n || y >=m || (grid[x][y] == '2') || (grid[x][y] == '0') )
            return;
        
        grid[x][y] = '2';
        helper( grid, x+1, y, n, m );
        helper( grid, x, y+1, n, m );
        helper( grid, x-1, y, n, m );
        helper( grid, x, y-1, n, m );

    }
    int numIslands(vector<vector<char>>& grid) 
    {
        int nr = 0;
        int n = grid.size();
        int m = grid[0].size();
        for ( int x=0; x<n; x++ )
        {
            for ( int y=0; y<m; y++ )
            {
                if ( grid[x][y] == '1' )
                {
                    helper( grid, x, y, n, m );
                    nr++;
                }
            }
        }
        
        return nr;
    }
};
