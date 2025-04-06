// https://leetcode.com/problems/perfect-rectangle/
// Passing
// Using Line sweep algorithm

int OFFSET = 1e5;

struct PairHash {
    size_t operator()(const pair<int, int>& p) const {
        return hash<long long>()(((long long)p.first << 32) | (unsigned int)p.second);
    }
};

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
        const int length = abs(endX_ - (initX_));
        const int breadth = abs(endY_ - (initY_));
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

    bool populateCells(unordered_map<pair<int, int>, int, PairHash>& cells) const
    {
        const int xInitLim = initX_+OFFSET;
        const int xEndLim = endX_+OFFSET;
        
        const int yInitLim = initY_+OFFSET;
        const int yEndLim = endY_+OFFSET;
        
        for(int i=xInitLim; i<xEndLim; i++)
        {
            for(int j=yInitLim; j<yEndLim; j++)
            {
                if (++cells[make_pair(i,j)] > 1)
                {
                    return false;
                }   
            }
        }

        return true;
    }

int initX_;
int initY_;
int endX_;
int endY_;
};

struct Event {
    int x, y1, y2;
    bool isStart;

    // Ensure end events come before start events at the same x
    bool operator<(const Event& e) const {
        if (x == e.x) return isStart < e.isStart;
        return x < e.x;
    }
};

bool hasOverlap(const vector<vector<int>>& rectangles) {
    vector<Event> events;

    for (const auto& rect : rectangles) {
        int x1 = rect[0], y1 = rect[1], x2 = rect[2], y2 = rect[3];
        events.push_back({x1, y1, y2, true});   // start event
        events.push_back({x2, y1, y2, false});  // end event
    }

    sort(events.begin(), events.end());

    set<pair<int, int>> active;

    for (const auto& e : events) {
        if (e.isStart) {
            // Check for overlap with active intervals
            auto it = active.lower_bound({e.y1, e.y2});
            if (it != active.end() && it->first < e.y2)
                return true;
            if (it != active.begin()) {
                --it;
                if (it->second > e.y1)
                    return true;
            }
            active.insert({e.y1, e.y2});
        } else {
            active.erase({e.y1, e.y2});
        }
    }

    return false;
}

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

        if(hasOverlap(rectangles))
        {
            return false;
        }

        //Calculating the bounding box
        Rectangle boundingRectangle(INT_MAX, INT_MAX, INT_MIN, INT_MIN);
        int areaOfAllTheRectangles = 0;
        unordered_map<pair<int, int>, int, PairHash> cells;
        for ( const auto& rectangle : rectangles )
        {
            const int x0 = rectangle[0];
            const int y0 = rectangle[1];
            const int xn = rectangle[2];
            const int yn = rectangle[3];
            
            const Rectangle rect(x0, y0, xn, yn);
            
            // if (!rect.populateCells(cells))
            // {
            //     return false;
            // }

            boundingRectangle.initX_ = std::min(boundingRectangle.initX_, x0);
            boundingRectangle.initY_ = std::min(boundingRectangle.initY_, y0);
            boundingRectangle.endX_ = std::max(boundingRectangle.endX_, xn);
            boundingRectangle.endY_ = std::max(boundingRectangle.endY_, yn);
            
            areaOfAllTheRectangles += rect.getArea();
            //rectangles_.push_back(rect);
        }

        const int area = boundingRectangle.getArea();
        return area == areaOfAllTheRectangles;
    }

    vector<Rectangle> rectangles_;
};