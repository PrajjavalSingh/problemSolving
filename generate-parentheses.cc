//https://leetcode.com/problems/generate-parentheses/submissions/
//working all cases
class Solution {
public:

    void generateDistinctPattern( int totn, int opennr, int closenr, vector<string>& ret, string currstr )
    {
        if ( (opennr == totn) && (closenr == totn) )
        {
            if ( std::find(ret.begin(),ret.end(),currstr) == ret.end() )
                ret.push_back( currstr );
            
            return;
        }

        if ( opennr < totn )
        {
            generateDistinctPattern( totn, opennr+1, closenr, ret, currstr + '(' );
        }

        if ( closenr < opennr )
        {
            generateDistinctPattern( totn, opennr, closenr+1, ret, currstr + ')' );
        }



    }


    vector<string> generateParenthesis( int n ) 
    {
        vector<string> ret;
        string currstr;
        generateDistinctPattern( n, 0, 0, ret, currstr );
        return ret;
    }
};
