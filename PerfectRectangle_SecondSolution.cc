//https://leetcode.com/problems/perfect-rectangle/
// Timeout 

struct coord
{
    coord(int x, int y)
    : x_(x),
      y_(y) {}
    
    bool operator<(const coord& other) const {
        return (x_ < other.x_) || (x_ == other.x_ && y_ < other.y_);
    }

    bool operator>(const coord& other) const {
        return !(*this < other);
    }

    bool operator==(const coord& other) const 
    {
        return (x_ == other.x_) && (y_ == other.y_);
    }

    void operator=(const coord& other) 
    {
        if ( *this == other )
        {
            return;
        }

        this->x_ = other.x_;
        this->y_ = other.y_;
    }

    int x_ = 0;
    int y_ = 0;
};

class Rectangle
{

    // [NW] 1-------2 [NE]
    //      |   :   |
    //      |-------| 
    //      |   :   |
    // [SW] 0-------3 [SE]
    // above is rectangle which has both sides of equidimensions of size 2 units. This can be divided into basic
    // unit of 1 Cell of dimension 1*1, so the above rectangle would have 4 cells.
public:
    
    Rectangle(int initX=0, int initY=0, int endX=0, int endY=0)
    : initX_(initX),
    initY_(initY),
    endX_(endX),
    endY_(endY)
    {}
    
    bool operator==(const Rectangle& other) const 
    {
        return (initX_ == other.initX_) && (initY_ == other.initY_) && (endX_ == other.endX_) &&
        (endY_ == other.endY_);
    }

    void operator=(const Rectangle& other) 
    {
        if ( *this == other )
        {
            return;
        }

        this->initX_ = other.initX_;
        this->initY_ = other.initY_;
        this->endX_ = other.endX_;
        this->endY_ = other.endY_;
    }
    const int getArea() const
    {
        const int length = endX_ - initX_;
        const int breadth = endY_ - initY_;
        return length * breadth;
    }

    const coord getSW() const
    {
        return coord(initX_, initY_);
    }

    const coord getSE() const
    {
        return coord(endX_, initY_);
    }

    const coord getNW() const
    {
        return coord(initX_, endY_);
    }

    const coord getNE() const
    {
        return coord(endX_, endY_);
    }
    
    bool overlaps(const Rectangle& other) const {
        // Return true if rectangles overlap
        return !(endX_ <= other.initX_ || other.endX_ <= initX_ ||
                 endY_ <= other.initY_ || other.endY_ <= initY_);
    }

    bool populateCells(vector<pair<int,int>>& cells) const
    {
        const int nrCells = getArea();
        int i = initX_;
        int j = initY_;
        pair<int,int> newpair(i,j);
        if (find(cells.begin(), cells.end(), newpair) != cells.end()) 
        {
            return false;
        }
        cells.push_back(newpair);
        const int xLength = endX_-initX_;
        for(int index=1; index<nrCells; index++)
        {
            if (index == xLength)
            {
                i = initX_;
                j++;
            }
            else
            {
                i++;
            }

            newpair.first = i;
            newpair.second = j;
            if (find(cells.begin(), cells.end(), newpair) != cells.end()) 
            {
                return false;
            }   
            cells.push_back(newpair);
        }

        return true;
    }

int initX_;
int initY_;
int endX_;
int endY_;
};

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) 
    {

        const int nrRectangles = rectangles.size();
        if (nrRectangles == 0)
        {
            return false;
        }

        if (nrRectangles == 1)
        {
            return true;
        }
        //Calculating the bounding box
        Rectangle boundingRectangle(INT_MAX, INT_MAX, INT_MIN, INT_MIN);
        int areaOfAllTheRectangles = 0;
        vector<pair<int,int>> cells;
        for ( const auto& rectangle : rectangles )
        {
            const int x0 = rectangle[0];
            const int y0 = rectangle[1];
            const int xn = rectangle[2];
            const int yn = rectangle[3];
            
            const Rectangle rect(x0, y0, xn, yn);
            
            if (!rect.populateCells(cells))
            {
                return false;
            }

            if (boundingRectangle.initX_ > x0)
            {
                boundingRectangle.initX_ = x0;
            }

            if (boundingRectangle.initY_ > y0)
            {
                boundingRectangle.initY_ = y0;
            }

            if (boundingRectangle.endX_ < xn)
            {
                boundingRectangle.endX_ = xn;
            }

            if (boundingRectangle.endY_ < yn)
            {
                boundingRectangle.endY_ = yn;
            }
            
            areaOfAllTheRectangles += rect.getArea();
            rectangles_.push_back(rect);
        }

        Rectangle currrect;
        coord init = boundingRectangle.getSW();
        auto it = rectangles_.begin();
        bool continous = false;
        // Going UP
        while(true)
        {
            it =  std::find_if(rectangles_.begin(), rectangles_.end(), [&](const Rectangle& r) {
                        return r.getSW() == init; });
            if (it == rectangles_.end())
            {
                break;
            }

            if (boundingRectangle.getNW() == it->getNW())
            {
                continous = true;
                break;
            }

            init = it->getNW();
        }
        if (!continous)
        {
            return false;
        }

        // Going RIGHT
        init = boundingRectangle.getNW();
        continous = false;
        while(true)
        {
            it =  std::find_if(rectangles_.begin(), rectangles_.end(), [&](const Rectangle& r) {
                        return r.getNW() == init; });
            if (it == rectangles_.end())
            {
                break;
            }

            if (boundingRectangle.getNE() == it->getNE())
            {
                continous = true;
                break;
            }

            init = it->getNE();
        }

        if (!continous)
        {
            return false;
        }

        // Going DOWN
        continous = false;
        init = boundingRectangle.getNE();
        while(true)
        {
            it =  std::find_if(rectangles_.begin(), rectangles_.end(), [&](const Rectangle& r) {
                        return r.getNE() == init; });
            if (it == rectangles_.end())
            {
                break;
            }

            if (boundingRectangle.getSE() == it->getSE())
            {
                continous = true;
                break;
            }

            init = it->getSE();
        }
        
        if (!continous)
        {
            return false;
        }

        // Going LEFT
        continous = false;
        init = boundingRectangle.getSE();
        while(true)
        {
            it =  std::find_if(rectangles_.begin(), rectangles_.end(), [&](const Rectangle& r) {
                        return r.getSE() == init; });
            if (it == rectangles_.end())
            {
                break;
            }

            if (boundingRectangle.getSW() == it->getSW())
            {
                continous = true;
                break;
            }

            init = it->getSW();
        }
        
        if (!continous)
        {
            return false;
        }

        const int area = boundingRectangle.getArea();
        return area == areaOfAllTheRectangles;
    }

    vector<Rectangle> rectangles_;
};
