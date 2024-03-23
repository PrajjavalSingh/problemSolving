//https://leetcode.com/problems/distinct-subsequences/
//time out issues, need more optimisation
class Solution {
public:
    void helper( int& ans, const string& s, const string& t, string& curr, int startidx )
    {
        if ( curr == t )
        {
            ans++;
            return;
        }

        for ( int idx=startidx; idx<s.size(); idx++ )
        {
            char ch = s[idx];
            curr.push_back(ch);
            helper( ans, s, t, curr, idx+1 );
            curr.pop_back();
        }
    }


    int numDistinct(string s, string t) 
    {
        int ans = 0;
        string curr;
        helper( ans, s, t, curr, 0 );
        return ans;
    }
};
