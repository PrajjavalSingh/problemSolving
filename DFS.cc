//https://leetcode.com/problems/maximum-depth-of-binary-tree/?envType=study-plan-v2&envId=top-interview-150

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
    
    int maxDepth(TreeNode* root) 
    {
        if ( !root )
            return 0;

        int depth_left = maxDepth( root->left );
        int depth_right = maxDepth( root->right );
        return 1 + max( depth_right, depth_left );
    }
};


void getMaxDepth(TreeNode* root, int& depth )
    {
        if ( !root ) 
            return;

        int leftdepth = 0;
        int rightdepth = 0;
        getMaxDepth( root->left, leftdepth );
        getMaxDepth( root->right, rightdepth );
        depth = 1+max(leftdepth,rightdepth);
    }

    int maxDepth(TreeNode* root) 
    {
        if ( !root )
            return 0;

        int depth = 0;
        getMaxDepth( root, depth );
        return depth;
    }
