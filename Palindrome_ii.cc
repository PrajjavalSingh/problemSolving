//https://leetcode.com/problems/valid-palindrome/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    bool isPalindrome(string s) 
    {
        // string outstr;
        // for ( auto c : s )
        // {
        //     if ( isalpha(c) )
        //         outstr.push_back(tolower(c));
        //     else if ( isdigit(c) )
        //         outstr.push_back(c);
        // }

        // if ( outstr.empty() )
        //     return true;

        // auto itl = outstr.begin();
        // auto itr = outstr.begin()+outstr.size()-1;
        // bool ispalindrome = true;
        // while ( itl < itr )
        // {
        //     if ( *itl != *itr )
        //     {
        //         ispalindrome = false;
        //         break;
        //     }
            
        //     itr--;
        //     itl++;
        // }       

        //solution 2:
        auto itl = s.begin();
        auto itr = s.begin()+s.size()-1;
        bool ispalindrome = true;
        while ( itl < itr )
        {
            char leftchar = *itl;
            char rightchar = *itr;
            if ( isalpha(leftchar) && isalpha(rightchar) )
            {
                if ( tolower(leftchar) != tolower(rightchar) )
                {
                    ispalindrome = false;
                    break;
                }

                itl++;
                itr--;
            }
            else if ( isdigit(leftchar) && isdigit(rightchar) )
            {
                if ( leftchar != rightchar )
                {
                    ispalindrome = false;
                    break;
                }

                itl++;
                itr--;
            }
            else if ( (isalpha(leftchar) && isdigit(rightchar)) || 
                        (isalpha(rightchar) && isdigit(leftchar)) )
            {
                ispalindrome = false;
                break;
            }
            else if ( (isalpha(leftchar) && !isalpha(rightchar)) ||
                            (isdigit(leftchar) && !isalpha(rightchar)) )
                itr--;
            else if ( (isalpha(rightchar) && !isalpha(leftchar)) ||
                            (isdigit(rightchar) && !isalpha(leftchar)) )
                itl++;
            else if ( !isalpha(rightchar) && !isalpha(leftchar) )
            {
                itr--;
                itl++;
            }
            

        }
        return ispalindrome; 
    }
};
