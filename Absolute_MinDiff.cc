/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

 //minimum difference can be 1 
 //This can be our exit strategy

//Following approach using sets
class Solution {
public:
    void helper( TreeNode* root, set<int>& nums )
    {
        if ( !root )
            return;

        nums.insert( root->val );
        helper( root->left, nums );
        helper( root->right, nums );
    }

    int getMinimumDifference(TreeNode* root) 
    {
        if  ( !root )
            return 0;    

        set<int> nums;
        helper( root, nums );
        const int sz = nums.size();
        auto it1 = nums.begin();
        auto it2 = next(nums.begin(),1);
        int ans = abs( *it1 - *it2 ); 
        if ( sz < 2 )
            return ans;

        it1++;
        it2++;
        while( it2 != nums.end() )
        {
            const int diff = abs( *it1 - *it2 );
            if ( diff < ans )
            {
                ans = diff;
                if ( diff == 1 )
                    break;
            }

            it1++;
            it2++;
        }   
  
        return ans;
    }
};


//Following approach using vector
class Solution {
public:
    void helper( TreeNode* root, vector<int>& nums )
    {
        if ( !root )
            return;

        nums.push_back( root->val );
        helper( root->left, nums );
        helper( root->right, nums );
    }

    int getMinimumDifference(TreeNode* root) 
    {
        if  ( !root )
            return 0;    

        vector<int> nums;
        helper( root, nums );
        sort( nums.begin(), nums.end() );
        const int sz = nums.size();
        if ( sz < 2 )
            return nums[0];

        int s = 1;
        int f = 2;
        int ans = abs(nums[1] - nums[0]);
        if ( ans == 1 )
            return ans;

        while( f<sz )
        {
            const int diff = abs( nums[s]-nums[f] );
            if ( diff < ans )
            {
                ans = diff;
                if ( diff == 1 )
                    break;
            }

            s++;
            f++;
        }   
  
        return ans;
    }
};
