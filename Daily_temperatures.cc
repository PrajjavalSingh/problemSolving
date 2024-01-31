//https://leetcode.com/problems/daily-temperatures/
//Needs to be more optimised
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        const auto sz = temperatures.size();
        vector<int> ret(sz);
        if ( sz == 1 )
            return ret; 

        vector<int> unique_Count;
        unique_Count.clear();
        
        auto it1 = temperatures.begin();
        auto end = temperatures.end();
        
        unique_copy(it1,end, std::back_inserter(unique_Count));
        if ( unique_Count.size() == 1 )
            return ret;

        auto it2 = temperatures.begin()+1;
        while( it2 != end )
        {
            if ( *it2 <= *it1 )
            {
                it2++;
                if ( it2 == end )
                {
                    it1++;
                    it2 = it1+1;
                }
            }
            else
            {
                ret[it1-temperatures.begin()] = it2-it1;
                it1++;
                it2 = it1+1;
            }
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
