class Solution {
public:
    string addBinary(string a, string b) 
    {
        const int asz = a.size();
        const int bsz = b.size();
        if ( asz != bsz )
        {
            if ( asz > bsz )
            {
                const int nrplaces = asz - bsz;
                for ( int idx=0; idx<nrplaces; idx++ )
                {
                    b.insert(0,"0");
                }
            }
            else
            {
                const int nrplaces = bsz - asz;
                for ( int idx=0; idx<nrplaces; idx++ )
                {
                    a.insert(0,"0");
                }
            }
        }

        const int sz = a.size();
        vector<int> ret;
        bool hascarry = false;
        for ( int idx=sz-1; idx>=0; idx-- )
        {
            char ch1 = a[idx];
            char ch2 = b[idx];
            const int a_idx = ch1 == '0' ? 0 : 1;
            const int b_idx = ch2 == '0' ? 0 : 1;
            int c = a_idx ^ b_idx;
            if ( hascarry )
                c = c ^ 1;

            if ( a_idx & b_idx )
            {
                hascarry = true;
            }
            else if ( (a_idx || b_idx) && hascarry )
             {
                hascarry = true;
             }
            else
                hascarry = false;

            ret.push_back( c );
        }

        if ( hascarry )
            ret.push_back(1);

        string retstr;
        for ( int idx=ret.size()-1; idx>=0; idx-- ) 
        {
            retstr += to_string( ret[idx] );
        }

        return retstr;
    }
};
