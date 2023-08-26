//https://leetcode.com/problems/two-sum/
//
//This is time efficient solution

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<int> ret;
        
        for (int idx=0; idx<nums.size(); idx++)
        {
            const int num = nums[idx];
            int complement = target - num;
            auto it = std::find(nums.begin()+idx+1, nums.end(),complement);
            if ( it != nums.end() )
            {
                ret.push_back(idx);
                ret.push_back(it-nums.begin());
                break;
            }
        }

         return ret;
    }
};
