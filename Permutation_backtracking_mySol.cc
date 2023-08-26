//https://leetcode.com/problems/permutations
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>> ret;
        const int size = nums.size();
        if ( size <= 2 )
        {
            ret.push_back( nums );
            if ( size == 2 )
            {
                swap( nums[0], nums[1] );
                ret.push_back( nums );
            }

            return ret;
        }
        
        
        for ( int idx=0; idx<size; idx++ )
        {
            vector<int> copy_nums = nums;
            const int currval = copy_nums[idx];
            copy_nums.erase(copy_nums.begin()+idx);
            vector<vector<int>> currret = permute(copy_nums);
            for ( auto& vec : currret )
            {
                vec.push_back( currval );
                ret.push_back( vec );
            }       
        }

        return ret;
    }
};
