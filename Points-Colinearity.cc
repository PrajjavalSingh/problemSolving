//https://leetcode.com/problems/max-points-on-a-line/?envType=study-plan-v2&envId=top-interview-150

class Solution {
protected:
    float udf = nan(""); 
    enum Orientation { Inclined=0, Vertical=1, Horizontal=2 };

    bool isInclined(Orientation ornt )
    {
        return ornt == Inclined;
    }

    bool isHorizontal(Orientation ornt )
    {
        return ornt == Horizontal;
    }

    bool isVertical(Orientation ornt )
    {
        return ornt == Vertical;
    }

    bool areCoLinear( vector<int>&p1, vector<int>&p2, vector<int>&p3 )
    {
        const int xdiff12 = (p2[0]-p1[0]);
            //since points are integers normal int comaprison would be enough
        Orientation orientation12 = Inclined;
        if ( xdiff12 == 0 )
            orientation12 = Vertical;

        const int ydiff12 = (p2[1]-p1[1]);
        if ( ydiff12 == 0 )
            orientation12 = Horizontal;

        float slope = udf;
        if ( isInclined(orientation12) || isHorizontal(orientation12)  )
            slope = (float)ydiff12 / xdiff12;

        Orientation orientation13 = Inclined;
        const int xdiff13 = (p3[0]-p1[0]);
        if ( xdiff13 == 0 )
            orientation13 = Vertical;
        
        const int ydiff13 = (p3[1]-p1[1]);
        if ( ydiff13 == 0 )
            orientation13 = Horizontal;

        if ( orientation13 != orientation12 )
            return false;

        if ( isVertical(orientation13) )
            return true;
        
        const float slope13 = (float)ydiff13 / xdiff13;

        const bool arecolinear = areEqual(slope,slope13);
        return arecolinear;
    }

    //map skey should idx1idx2
public:
    bool areEqual(float f1, float f2)
    {
        const float eps = 0.00000000001;
        return fabs(f1-f2) < eps;
    }

    int maxPoints(vector<vector<int>>& points)
    {
        const int size = points.size();
        if ( size < 3 )
            return size; //if 1 point, no co-linear points, if 2 points they will always be co-linear

        //unordered_map<string,float> slopemap;
        //unordered_map<int,vector<int>> pointsmap;
        unordered_map<int,int> pointsmap;
        vector<int> processedidx;
        int counter = 0;
        for ( int iidx=0; iidx<size; iidx++ )
        {
            for ( int jidx=0; jidx<size; jidx++ )
            {
                counter++;
                if ( iidx == jidx )
                    continue;

                pointsmap[counter] = 2;
                for ( int kidx=0; kidx<size; kidx++ )
                {
                    if ( kidx == jidx || kidx == iidx )
                        continue;

                    vector<int> p1 = points[iidx];
                    vector<int> p2 = points[jidx];
                    vector<int> p3 = points[kidx];
                    if ( areCoLinear(p1,p2,p3) )
                    {
                        auto it = pointsmap.find(counter);
                        it->second++;
                    }

                }
            }    
        }

        auto itx = pointsmap.begin();
        int output = 0;
        while ( itx != pointsmap.end() )
        {
            if ( itx->second > output )
                output = itx->second;
            
            itx++;

        }

        return output;
    }
};
