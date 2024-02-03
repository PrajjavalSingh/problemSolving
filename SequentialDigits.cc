//https://leetcode.com/problems/sequential-digits/

class Solution {
public:
    double factor = 11.1111111;
    int startnum = 12;
    void nextSequence( vector<int>& nums, int num, int low, int high  )
    {
        if ( num <= low )
        {
            if ( num == low )
                nums.push_back( num );

            
            while ( num < low )
            {
                const int testnum = num + factor;
                if ( testnum%10 == 0 )
                {
                    factor = factor * 10;
                    num = startnum + factor;
                    startnum = num;
                }
                else
                    num = num + factor;
            }
        }

        
        if ( num <= high )
        {
            nums.push_back( num );
            
            const int testnum = num + factor;
            if ( testnum%10 == 0 )
            {
                factor = factor * 10;
                num = startnum + factor;
                startnum = num;
            }
            else 
                num = num + factor;
            
            nextSequence( nums, num, low, high );
        }

        return;
    }


    vector<int> sequentialDigits(int low, int high) 
    {
        vector<int> nums;
        nextSequence( nums, startnum, low, high ); 
        return nums;
    }
};
