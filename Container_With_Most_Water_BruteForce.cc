//https://leetcode.com/problems/container-with-most-water/submissions/
//bruteforce
class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        vector<int> areas;
        for (int idx=0; idx<height.size(); idx++ )
        {
            bool left_handled = false;
            
            const int curr_height = height[idx];
            auto it = find_if( height.begin(),height.end(),[=](int h){return h>=curr_height;} );
            if ( it == height.end() )
                continue;
                
            for ( int jidx=0; jidx<idx; jidx++ )
            {
                const int it_height = height[jidx];
                if ( it_height >= curr_height )
                {
                    int area = (idx-jidx)*curr_height;
                    areas.push_back(area);
                    break; 
                }
            }

            for ( int kidx=height.size()-1; kidx>=idx; kidx-- )
            {
                const int it_height = height[kidx];
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
            return areas[areas.size()-1];
        }
        else
            return 0;
        
    }
};
