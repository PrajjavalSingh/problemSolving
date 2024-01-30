//https://leetcode.com/problems/jump-game/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    bool canJump(vector<int>& nums) 
    {
        const int sz = nums.size();
        if ( sz == 1 )
            return nums[0] >= 0;

        int max_jump = nums[0];
        if ( max_jump == 0 )
            return false;
        else if ( max_jump >= sz-1 )
            return true;

        for ( int idx=1; idx<sz; idx++ )
        {
            const int val = nums[idx];
            if ( idx+val >= sz-1 )
                return true;

            if ( val < max_jump )
                max_jump--;
            else if ( val >= max_jump )
                max_jump = val;

            if ( max_jump <= 0 )
                return false; 
        }

        return false;
    }
};
