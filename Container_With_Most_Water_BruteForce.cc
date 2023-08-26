//https://leetcode.com/problems/container-with-most-water/submissions/
//bruteforce
class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        vector<int> areas;
        for (int idx=0; idx<height.size(); idx++ )
        {
            const int curr_height = height[idx];
            for ( int jidx=0; jidx<idx; jidx++ )
            {
                const int it_height = *(height.begin()+jidx);
                if ( it_height >= curr_height )
                {
                    int area = (idx-jidx)*curr_height;
                    areas.push_back(area);
                    break; 
                }
            }

            for ( int kidx=height.size()-1; kidx>=idx; kidx-- )
            {
                const int it_height = *(height.begin()+kidx);
                if ( it_height >= curr_height )
                {
                    int area = (kidx-idx)*curr_height;
                    areas.push_back(area);
                    break; 
                }
            }
        }
        
        if ( areas.size()>0 )
        {
            sort(areas.begin(),areas.end());
             return *(areas.end()-1);
 	}
        else
            return 0;
        
    }
};
