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

    // [NW] 1-----2 [NE]
    //      |     |
    //      |     |
    // [SW] 0-----3 [SE]
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
int initX_;
int initY_;
int endX_;
int endY_;
};

// namespace std {
//     template <>
//     struct hash<Rectangle> {
//         size_t operator()(const Rectangle& r) const {
//             return ((std::hash<int>()(r.initX_) ^ (std::hash<int>()(r.initY_) << 1)) >> 1) ^
//                    ((std::hash<int>()(r.endX_) ^ (std::hash<int>()(r.endY_) << 1)) << 1);
//         }
//     };
// }

namespace std {
    template <>
    struct hash<Rectangle> {
        size_t operator()(const Rectangle& r) const {
            size_t h1 = std::hash<int>()(r.initX_);
            size_t h2 = std::hash<int>()(r.initY_);
            size_t h3 = std::hash<int>()(r.endX_);
            size_t h4 = std::hash<int>()(r.endY_);

            size_t combined = h1;
            combined ^= h2 + 0x9e3779b9 + (combined << 10) + (combined >> 2);
            combined ^= h3 + 0x9e3779b9 + (combined << 10) + (combined >> 2);
            combined ^= h4 + 0x9e3779b9 + (combined << 10) + (combined >> 2);
            return combined;
        }
    };
}

// struct Cell : public coord
// {
//     Cell(int i=0, int j=0)
//     : coord(i,j) {}
// };

// namespace std {
//     template <>
//     struct hash<Cell> {
//         size_t operator()(const Cell& c) const {
//             return (hash<int>()(c.x_) << 1) ^ hash<int>()(c.y_);
//         }
//     };
// }

// const int CELL_SIZE = 10;

// bool findOverlaps(const std::vector<Rectangle>& rects) 
// {
//     std::unordered_map<Cell, std::vector<Rectangle>> grid;
//     bool doesNotOverlap = true;
//     for (const auto& rect : rects) 
//     {
//         int minX = rect.initX_ / CELL_SIZE;
//         int maxX = (rect.endX_ - 1) / CELL_SIZE;
//         int minY = rect.initY_ / CELL_SIZE;
//         int maxY = (rect.endY_ - 1) / CELL_SIZE;

        
//         for (int i = minX; i <= maxX; ++i) 
//         {
//             for (int j = minY; j <= maxY; ++j) 
//             {
//                 Cell cell{i, j};
//                 auto& bucket = grid[cell];
//                 for (const auto& other : bucket) 
//                 {
//                     if (rect.overlaps(other)) 
//                     {
//                         doesNotOverlap = false;
//                         break;
//                     }
//                 }
//                 bucket.push_back(rect);
//             }
//         }
//     }
//     return doesNotOverlap;
// }

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
        for ( const auto& rectangle : rectangles )
        {
            const int x0 = rectangle[0];
            const int y0 = rectangle[1];
            const int xn = rectangle[2];
            const int yn = rectangle[3];
            
            const Rectangle rect(x0, y0, xn, yn);
            rectangles_.push_back(rect);

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
        }

        // Check if boudning box is perfect rectangle
        // what is perfect rectangle ??

        // First we move UP, we have the bounding box, we find the rectangle whose SW matches with the SW of the
        // bounding box. We take the NW of this rectangle and repeat till we do not reach the end of this edge.
        // If we do not find any next point and we have not reached the end, there is hole and we need to address
        // the situation.
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

        //Check for overlapping rectangles
        // for (size_t i = 0; i < rectangles_.size(); ++i) 
        // {
        //     for (size_t j = i + 1; j < rectangles_.size(); ++j) 
        //     {
        //         if (rectangles_[i].overlaps(rectangles_[j])) 
        //         {
        //             return false;
        //         }
        //     }
        // }

        // std::sort(rectangles_.begin(), rectangles_.end(), [](const Rectangle& a, const Rectangle& b) {
        //         return a.initX_ < b.initX_;
        // });

        // for (size_t i = 0; i < rectangles_.size(); ++i) 
        // {
        //     const auto& a = rectangles_[i];
        //     for (size_t j = i + 1; j < rectangles_.size(); ++j) 
        //     {
        //         const auto& b = rectangles_[j];
        //         if (b.initX_ >= a.endX_)
        //             break;  // No need to check further, can't overlap in x

        //         if (a.overlaps(b)) 
        //         {
        //             return false;
        //         }
        //     }
        // }

        const int area = boundingRectangle.getArea();
        if (area == areaOfAllTheRectangles)
        {
            std::unordered_map<Rectangle, int> rectMap;
            rectMap.reserve(rectangles_.size());
            for (size_t i = 0; i < rectangles_.size(); ++i) 
            {
                if (rectMap.count(rectangles_[i]) != 0) 
                {
                    return false;
                } 
                else {
                    rectMap[rectangles_[i]] = i;
                }
            }

            //return findOverlaps(rectangles_);
            return true;
        }
        
        return false;
    }

    vector<Rectangle> rectangles_;
};