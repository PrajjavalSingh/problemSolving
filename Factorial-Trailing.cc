//https://leetcode.com/problems/factorial-trailing-zeroes/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    

    int trailingZeroes(int n) 
    {
        int val = 0;
        if ( n < 5 )
            return val;

        while ( n>=5 )
        {
            val += n/5;
            n = n/5;
        }

        return val;   
    }
};
