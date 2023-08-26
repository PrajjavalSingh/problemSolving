//https://leetcode.com/problems/permutations-ii/editorial/
//Works but not much effective
//Run time has been reduced but still takes 397ms and taking 92.2MB

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        vector<vector<int>> ret;
        const int size = nums.size();
        if ( size <= 2 )
        {
            ret.push_back( nums );
            if ( size == 2 )
            {
                swap( nums[0], nums[1] );
                if (ret[0]!=nums) 
                    ret.push_back( nums );
            }

            return ret;
        }
        
        
        for ( int idx=0; idx<size; idx++ )
        {
            vector<int> copy_nums = nums;
            const int currval = copy_nums[idx];
            copy_nums.erase(copy_nums.begin()+idx);
            vector<vector<int>> currret = permuteUnique(copy_nums);
            for ( auto& vec : currret )
            {
                vec.push_back( currval );
                if (find(ret.begin(),ret.end(),vec)==ret.end())
                    ret.push_back( vec );
            }       
        }
        
        return ret;
    }
};
