//https://leetcode.com/problems/symmetric-tree/?envType=study-plan-v2&envId=top-interview-150

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
    bool isSymmetric_My(TreeNode* left_root, TreeNode* right_root ) 
    {
        if ( !left_root || !right_root )
        {
            if ( left_root && !right_root )
                return false;
            else if ( !left_root && right_root )
                return false;
            else if ( !left_root && !right_root )
                return true;
        }

        return isSymmetric_My( left_root->left, right_root->right ) && 
            isSymmetric_My( left_root->right, right_root->left ) &&
            (left_root->val == right_root->val);
    }

    bool isSymmetric(TreeNode* root) 
    {
        if ( !root )
            return true;

        return isSymmetric_My( root->left, root->right );
    }
};
