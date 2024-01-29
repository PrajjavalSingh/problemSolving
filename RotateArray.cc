//https://leetcode.com/problems/rotate-array/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    {
        const int size = nums.size();
                //Following method uses O(1)
        // const int swapidx = size-1;
        // int countk = 0;
        // while ( countk < k )
        // {
        //     for ( int idx=0; idx<size; idx++ )
        //         swap( nums[idx], nums[swapidx] );

        //     countk++;
        // }  
	//
	// 2. Method
	// reverse(nums.begin(), nums.end());
        //reverse(nums.begin(), nums.begin()+k);
        //reverse(nums.begin()+k, nums.end()); 
        
	k = k % size;
        vector<int> numsorg = nums;
        int idx = 0;
        while(idx<size)
        {
            int kindx = idx + k;
            if ( kindx >= size )
                kindx = kindx-size;

            nums[kindx] = numsorg[idx];
            idx++;
        } 
    }
};
