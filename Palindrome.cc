//https://leetcode.com/problems/palindrome-number/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    bool isPalindrome(int x) 
    {
        if ( x < 0 )
            return false;

        string num = to_string( x );

        auto itr = num.end()-1;
        auto itl = num.begin();
        bool success = true;
        while( itr>itl )
        {
            if ( *itl != *itr )
            {
                success = false;
                break;
            }

            itl++;
            itr--;
        }
        
        return success;
    }
};
