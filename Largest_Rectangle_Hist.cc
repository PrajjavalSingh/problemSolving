//https://leetcode.com/problems/largest-rectangle-in-histogram/description/

class Solution {
public:
    int largestRectangleArea(vector<int>& height) 
    {
        //here the next rectangle should be increaing, i.e continuity needs to be maintained
        vector<int> areas;
        for ( int idx=0; idx<height.size(); idx++ )
        {
            int area = 0;
            const int curr_height = height[idx];
            for (int jidx=0; jidx<height.size(); jidx++ )
            {
                const int it_height = height[jidx];
                if ( it_height >= curr_height )
                {
                    area += curr_height;
                }
                else if ( jidx > idx )
                    break;
                else
                    area = 0;
            }

            areas.push_back(area);
        }

        sort(areas.begin(),areas.end());
        return areas[areas.size()-1];
    }
}; 
