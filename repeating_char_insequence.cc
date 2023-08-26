//https://leetcode.com/problems/longest-substring-without-repeating-characters/submissions/
class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        const int sz = s.size();
        if ( sz <= 1 )
            return sz;

        string ret;
        ret.push_back( s[0] );
        vector<int> retsz;
        for (int idx=1; idx<sz; idx++)
        {
            char ch = s[idx];
            string::iterator it = std::find( ret.begin(), ret.end(), ch );

            if ( it != ret.end() )
            {
                if ( ret.begin() != it )
                    ret.erase( ret.begin(), it+1 );
                else
                {
                    retsz.push_back( ret.size() );
                    if ( it-ret.begin() == 0 )
                        ret.erase(ret.begin()-0);
                    else
                        ret.clear();
                }

                ret.push_back( ch );
            }
            else
            {
                ret.push_back( ch );
                retsz.push_back(ret.size());
            }

            
        }

        sort( retsz.begin(), retsz.end() );

        return retsz.size() > 0 ? retsz[retsz.size()-1] : 0;
    }
};
