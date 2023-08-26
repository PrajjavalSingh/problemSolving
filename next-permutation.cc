//https://leetcode.com/problems/next-permutation/
//
//Now working for all cases, memory : 12.1MB

class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
        const int sz = nums.size();
        int pivot_idx = -1;
        int pivot_val = 0;
        for ( int idx=sz-1; idx>=1; idx-- )
        {
            if ( nums[idx-1] >= nums[idx] )
                continue;
            
            pivot_idx = idx-1;
            pivot_val = nums[idx-1];
            auto it = std::find_if(nums.begin()+pivot_idx+1,nums.end(),[&](auto num){return num <= pivot_val;});
            int swap_idx = std::distance(nums.begin(),it);
            swap(nums[pivot_idx],nums[swap_idx-1]);
            break;
        }

        std::reverse(nums.begin()+pivot_idx+1, nums.end());
    }
};
