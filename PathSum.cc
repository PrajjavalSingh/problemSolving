//https://leetcode.com/problems/path-sum/?envType=study-plan-v2&envId=top-interview-150
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
class Solution {
public:
    bool helper( bool isleaf, TreeNode* root, int leftsum )
    {
        if ( !root )
            return leftsum == 0 && isleaf;
    
        bool hassum = helper( !root->right, root->left,leftsum-root->val);
        if ( !hassum )
            hassum = helper( !root->left, root->right,leftsum-root->val);

        return hassum;
    }

    bool hasPathSum(TreeNode* root, int targetSum) 
    {
        if ( !root )
            return false;
        bool isleaf = !root->left && !root->right;
        return helper(isleaf,root,targetSum);
    }
};
