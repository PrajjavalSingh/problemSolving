//https://leetcode.com/problems/repeated-substring-pattern/submissions/

class Solution {
public:
    bool repeatedSubstringPattern(string s) 
    {
        string repeatchar;
        const int sz = s.size();
        for ( int idx=0; idx<sz/2; idx++ )
        {
            char ch = s[idx];
            repeatchar.push_back( ch );
            
            const int repeat_sz = repeatchar.size();
            string::size_type pos_st = 0;
            int count = 0;
            while( (pos_st = s.find(repeatchar,pos_st)) != string::npos )
            {
                ++count;
                pos_st += repeat_sz;
            }

            if ( count > 1 )
            {
                bool isvalid = sz % repeat_sz == 0;
                if ( isvalid ) 
                {
                    const int nr_expec_repeat = sz/repeat_sz;
                    if ( count == nr_expec_repeat )
                        return true;
                }
            }
            
        }

        

        return false;
        
    }
};
