//https://leetcode.com/problems/longest-univalue-path/

/*
 * Intution / Basic Algorithm

        -We will create a function that return the length of the max path
        -For calculating the uni-value path we need to make a recursive call for the left and right
        -if the right node is equal to root node we add +1 to the right path
            -If the left node is equal to root node we add +1 to the left path
        -If we have reached the nullptr neturn 0;
        we have to return the max of left and right 
        -we need a variable to store the maxPath for the we can do the following
            -left + right 
        -but for returning we cannot return both as it woulf qualify for a non-valid path
 * */


class Solution {
public:
    
    int helper( TreeNode* node, int& length )
    {
        if ( !node )
            return 0;

        int leftl = helper( node->left, length );
        int rightl = helper( node->right, length );
        int leftval = 0;
        int rightval = 0;
        if ( node->left && node->left->val == node->val )
            leftval = leftl +1;
        
        if ( node->right && node->right->val == node->val )
            rightval = rightl +1;

        length = max( length, leftval+rightval );
        return max(leftval,rightval);
    }

    int longestUnivaluePath(TreeNode* root) 
    {
        if ( !root )
            return 0;

        int length = 0;
        helper( root, length );
        return length;
    }
};
