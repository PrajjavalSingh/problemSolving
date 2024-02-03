//https://leetcode.com/problems/h-index/?envType=study-plan-v2&envId=top-interview-150
class Solution 
{
public:
    int hIndex(vector<int>& citations) 
    {
        sort( citations.begin(), citations.end() );
        const int sz = citations.size();
        int hindex = 0;
        for (int idx=sz-1; idx>=0; idx-- )
        {
            if ( citations[idx] > hindex )
                hindex++;
            else
                break;
        }

        return hindex;
    }
};
