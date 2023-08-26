//https://leetcode.com/problems/largest-rectangle-in-histogram/description/
//This looks like optimized soln but is not handling all the cases properly
// solving 73 cases
class Solution {
public:
    int largestRectangleArea(vector<int>& height) 
    {
        const int sz = height.size();
        if ( sz == 1 )
            return height[0];
        else if ( sz == 2 )
        {
            sort( height.begin(), height.end() );
            return max( height[0]*2, height[1] );
        }

        //here the next rectangle should be increaing, i.e continuity needs to be maintained
        int ret_area = 0;
        for ( int idx=0; idx<sz; idx++ )
        {
            const int curr_height = *(height.begin()+idx);
            auto it = find_if( height.begin(),height.end(),[=](int h){return h<curr_height;} );
            bool inflex = false;
            int startidx = 0;
            int endidx = it-height.begin();
            int area = 0;
            if ( endidx >= idx )
            {
                area = endidx*curr_height;
            }
            else if ( endidx < idx )
            {
                while(endidx<idx)
                {
                    startidx = endidx + 1;
                    it = find_if( height.begin()+startidx,height.end(),[=](int h){return h<curr_height;} );
                    if ( it == height.end() )
                    {
                        endidx = sz;
                        break;
                    } 
                    else
                        endidx = it - height.begin();
                }

                area = ( endidx - startidx ) * curr_height;
            }

            if ( area > ret_area )
                ret_area = area;
        }

        return ret_area;
    }
};
