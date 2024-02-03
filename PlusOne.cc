//https://leetcode.com/problems/plus-one/?envType=study-plan-v2&envId=top-interview-150
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        const int sz = digits.size();
        vector<int> ret(sz+1,1);
        bool iscarried = false;
        int val = digits[sz-1];
        if ( ++val > 9 )
        {
            val = 0;
            iscarried = true;
        }
        
        ret[sz] = val;
        for ( int idx=sz-2; idx>=0; idx-- )
        {
            val = digits[idx];
            if ( iscarried )
            {
                val++;
                if ( val > 9 )
                    val = 0;
                else
                    iscarried = false;
            }

            ret[idx+1] = val;    
        }

        if ( !iscarried )
            ret.erase(ret.begin());

        return ret;
    }
};
