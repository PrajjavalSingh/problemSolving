//https://leetcode.com/problems/daily-temperatures/
//
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
	//Following is optimised code
        const auto sz = temperatures.size();
        vector<int> ret(sz,0);
        if ( sz == 1 )
            return ret; 

        stack<int> vals;
        auto it1 = temperatures.begin();
        auto begin = temperatures.begin();
        auto end = temperatures.end();
        while( it1 != end )
        {
            while( !vals.empty() && (temperatures[vals.top()]<*it1) )
            {
                ret[vals.top()] = it1 - (begin + vals.top());
                vals.pop();
            }

            vals.push( it1 - begin );
            it1++;
        }

        // for ( int idx=0; idx<sz-1; idx++ )
        // {
        //     const auto  currtemp = temperatures[idx];
        //     bool foundnone = true;
        //     for ( int kidx=idx+1; kidx<sz; kidx++ )
        //     {
        //         const auto comptemp = temperatures[kidx];
        //         if ( comptemp > currtemp )
        //         {
        //             foundnone = false;
        //             ret[idx] = kidx-idx;
        //             break;
        //         }                
        //     }
        // }

        // auto it1 = temperatures.begin();
        // while ( it1 != temperatures.end() )
        // {
        //     const int currtemp = *it1;
        //     auto itx = find_if( it1, temperatures.end(), [=](int temp){return temp>currtemp;});
        //     if ( itx != temperatures.end() )
        //         ret.push_back(itx-it1);
        //     else
        //         ret.push_back(0);
            
        //     it1++;
        // }

        
        return ret;
    }
};
