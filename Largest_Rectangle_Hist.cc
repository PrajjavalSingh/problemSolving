//https://leetcode.com/problems/largest-rectangle-in-histogram/description/

class Solution {
public:
    int largestRectangleArea(vector<int>& height) 
    {
        //here the next rectangle should be increaing, i.e continuity needs to be maintained
        const int sz = height.size();
        int ret_area = 0;
        for ( int idx=0; idx<sz; idx++ )
        {
            int area = 0;
            const int curr_height = *(height.begin()+idx);
            for (int jidx=0; jidx<sz; jidx++ )
            {
                const int it_height = *(height.begin()+jidx);
                if ( it_height >= curr_height )
                {
                    area += curr_height;
                }
                else if ( jidx > idx )
                    break;
                else
                    area = 0;
            }

            if ( area > ret_area )
                ret_area = area;
        }

        return ret_area;
    }
};
