//https://leetcode.com/problems/3sum/?envType=study-plan-v2&envId=top-interview-150
class Solution {
public:
    
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        sort( nums.begin(), nums.end() );
        set<vector<int>> retset;
        vector<vector<int>> ans;
        for ( int i=0; i<nums.size(); i++ )
        {
            auto s = i+1;
            auto f = nums.size()-1;
            while ( s < f )
            {
                const int sum = nums[i] + nums[s] + nums[f];
                if ( sum == 0 )
                {
                    retset.insert(vector<int>{nums[s],nums[f],nums[i]});
                    s++;
                    f--;
                }
                else
                {
                    if ( sum < 0 )
                        s++;
                    else 
                        f--;
                }
            }
        }

        for ( auto ret : retset )
            ans.push_back( ret );

        return ans;
    }
};
