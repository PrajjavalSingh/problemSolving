//https://leetcode.com/problems/valid-parentheses

class Solution {
public:
    bool isValid( string s )
    {
        const int stringsz = s.size();
        if ( stringsz%2 != 0 )
            return false;

        vector<char> opensymbols;
        vector<char> closesymbols;
        opensymbols.push_back('(');
        opensymbols.push_back('[');
        opensymbols.push_back('{');
        closesymbols.push_back(')');
        closesymbols.push_back(']');
        closesymbols.push_back('}');
        vector<char> leftopen; 
        const int nrsymbols = opensymbols.size();
        for ( int idx=0; idx<s.size(); idx++ )
        {
            char currsymbol = s[idx];
            auto it = std::find(opensymbols.begin(),opensymbols.end(),currsymbol);
            if ( it != opensymbols.end() )
            {
                const int sidx = std::distance(opensymbols.begin(),it);
                leftopen.push_back(closesymbols[sidx]);
            }
            else if ( std::find(closesymbols.begin(),closesymbols.end(),currsymbol) != closesymbols.end() )
            {
                if ( leftopen.size() == 0 )
                    return false;
                
                char expectedsymbol = leftopen.back();
                if ( currsymbol == expectedsymbol )
                    leftopen.pop_back();
                else
                    return false;
            }           

        }

        return leftopen.size() == 0;
    } 
};
