//https://leetcode.com/problems/sqrtx/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    int mySqrt(int x) 
    {
        if ( x <= 0 )
            return 0;

        long msb = (int)(log2(x));

	    // (a = 2^msb)
        long val = 1 << msb;
        int sqrt = 0;
        while (val != 0) 
        {

            if ((sqrt + val) * (sqrt + val) <= x) 
                sqrt += val;

		    // (a = a/2)
		    val >>= 1;
	    }

	    return sqrt;
        
    }
};
