//https://leetcode.com/problems/path-sum-iii/
//Strategy : 
//At each node, either choose the node and subtract the value
//or move left or right
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
    bool isLeaf( TreeNode* node )
    {
        return node && !node->left && !node->right;
    }

    // void helper( TreeNode* node, int targetSum, int& nrpaths, int sum, queue<int>& prevvals )
    // {
    //     if ( !node )
    //         return;

    //     sum += node->val;
    //     prevvals.push( node->val );

    //     if ( sum == targetSum )
    //     {
    //         nrpaths++;
    //         sum -= prevvals.front();
    //         prevvals.pop();
    //     }
    //     else if ( abs(sum) > abs(targetSum) )
    //     {
    //         while( abs(sum) > abs(targetSum) )
    //         {
    //             sum -= prevvals.front();
    //             prevvals.pop();
    //         }

    //         if ( prevvals.size() && sum == targetSum )
    //         {
    //             nrpaths++; 
    //         }
    //         else
    //             sum = 0;           
    //     }

    //     helper( node->left, targetSum, nrpaths, sum, prevvals );
    //     //prevvals.pop();
    //     helper( node->right, targetSum, nrpaths, sum, prevvals );
    // }

    int nrpaths = 0;
    void helper( TreeNode* node, long long sum )
    {
        if ( !node )
            return;
        
        if ( sum == node->val)
            nrpaths++;

        helper( node->left, sum-node->val );
        helper( node->right, sum-node->val );
    }

    int pathSum(TreeNode* root, int targetSum) 
    {
        if ( !root )
            return nrpaths;

        // int nrpaths = 0;
        // int sum = 0;
        // queue<int> prevvals;
        // helper( root, targetSum, nrpaths, sum, prevvals );
        helper( root, targetSum );
        pathSum( root->left, targetSum );
        pathSum( root->right, targetSum );

        return nrpaths;
    }
};
