//https://leetcode.com/problems/remove-element/description/?envType=study-plan-v2&envId=top-interview-150
//
class Solution {
public:
    int removeElement(vector<int>& nums, int val) 
    {
        const int sz = nums.size();
        int swapidx = sz-1;  
        for ( int idx=0; idx<=swapidx; idx++ )
        {
            const int num = nums[idx];
            if ( num == val )
            {
                while( swapidx >= idx )
                {
                    const int swapnum = nums[swapidx];
                    if ( swapnum != val )
                    {
                        swap( nums[idx], nums[swapidx] );
                        swapidx--;
                        break;
                    }

                    swapidx--;
                }
            }
        }

        return swapidx+1;
    }
};
