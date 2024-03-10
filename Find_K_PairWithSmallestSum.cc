//https://leetcode.com/problems/find-k-pairs-with-smallest-sums/?envType=study-plan-v2&envId=top-interview-150
//Timeout solution
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) 
    {
        const int nums1sz = nums1.size();
        const int nums2sz = nums2.size();
        map<int,vector<vector<int>>> ansmap;
        for ( int idx=0; idx<nums1sz; idx++ )
        {
            vector<int> vecnums(2);
            vecnums[0] = nums1[idx];
            for ( int jidx=0; jidx<nums2sz; jidx++ )
            {
                vecnums[1] = nums2[jidx];
                const int sum = vecnums[0] + vecnums[1];
                const int currsz = ansmap[sum].size();
                if ( currsz < k )
                    ansmap[sum].push_back(vecnums);
                else
                    break;
            }
        }
        
        auto it = ansmap.begin();
        vector<vector<int>> ret;
        while( it != ansmap.end() )
        {
            vector<vector<int>> retset = it->second;
            for ( int idx=0; idx<retset.size(); idx++ )
            {
                k--;
                if ( k<0 )
                    break;

                ret.push_back( retset[idx] );
            }

            it++;
        }


        return ret;
    }
};


//Optimised solution using priority queue
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) 
    {
        const int nums1sz = nums1.size();
        const int nums2sz = nums2.size();
        priority_queue<pair<int,pair<int,int>>> heapmap;
        for ( int idx=0; idx<nums1sz; idx++ )
        {
            const int num1 = nums1[idx];
            for ( int jidx=0; jidx<nums2sz; jidx++ )
            {
                const int num2 = nums2[jidx];
                const int sum = num1+num2;

                if ( heapmap.size() >= k )
                {
                    if ( heapmap.top().first <= sum )
                        break;

                    heapmap.pop();
                }

                heapmap.push( {sum, {num1,num2}} );
            }
        }
        
        vector<vector<int>> ret;
        while( !heapmap.empty() )
        {
            ret.push_back({heapmap.top().second.first,heapmap.top().second.second});
            heapmap.pop();
        }


        return ret;
    }
};
