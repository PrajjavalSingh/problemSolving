//https://leetcode.com/problems/combinations/?envType=study-plan-v2&envId=top-interview-150
class Solution {
public:
    // 1 2 3 4
    // 1 2
    void helper( vector<vector<int>>& ans, const vector<int>& nums, int sz, vector<int>& curr, int startidx )
    {
        if ( curr.size() == sz )
        {
            ans.push_back(curr);
            return;
        }

        for ( int idx=startidx; idx<nums.size(); idx++ )
        {
            const int num = nums[idx];
            if ( find(curr.begin(),curr.end(),num) == curr.end() )
            {
                curr.push_back(num);
                helper( ans, nums, sz, curr, idx+1 );
                curr.pop_back();
            }
        }
    }

    vector<vector<int>> combine(int n, int k) 
    {
        vector<int> nums(n);
        for ( int idx=0; idx<n; idx++ )
            nums[idx] = idx+1;

        vector<int> curr;
        vector<vector<int>> ans;
        helper( ans, nums, k, curr, 0 );
        return ans;
    }
};
