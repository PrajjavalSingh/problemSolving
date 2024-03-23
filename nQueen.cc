//https://leetcode.com/problems/n-queens-ii/?envType=study-plan-v2&envId=top-interview-150
class Solution {
public:
    
    bool isSafe(const vector<vector<int>>& board, int row, int col, int n )
    {
        int idx, jidx = 0;

        for ( jidx=0; jidx<col; jidx++ )
        {
            if ( board[row][jidx] )
                return false;
        }

        for ( idx = row, jidx = col; idx>=0 && jidx >=0; idx--, jidx-- )
        {
            if ( board[idx][jidx] )
                return false;
        }

        for ( idx = row, jidx = col; idx < n && jidx >= 0; idx++, jidx-- )
        {
            if ( board[idx][jidx] )
                return false;
        }
       
        return true;
    }

    void solveForNQueen( vector<vector<int>>& board, int col, int n, vector<vector<int>>& result )
    {
        if ( col == n )
        {
            vector<int> vec;
            for ( int idx=0; idx<n; idx++ )
            {
                for ( int jidx=0; jidx<n; jidx++ )
                {
                    if ( board[idx][jidx] )
                        vec.push_back( jidx );
                }
            }
            
            result.push_back( vec );
        }

        for ( int idx=0; idx<n; idx++ )
        {
            if ( isSafe(board,idx,col,n) )
            {
                board[idx][col] = 1;
                solveForNQueen(board,col+1,n,result);
                board[idx][col] = 0;
            }
        }
    }

    int totalNQueens(int n) 
    {
        vector<vector<int>> board(n,vector<int>(n,0));
        vector<vector<int>> result; 
        solveForNQueen(board,0,n,result);

        return  result.size();
    }
};
