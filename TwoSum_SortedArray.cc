//https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/?envType=study-plan-v2&envId=top-interview-150


//solution 1 exceeding time
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        const int sz = numbers.size();
        const int mididx = floor(sz/2);
        cout << mididx << endl;
        const int middlenum = numbers[mididx];
        auto it1 = numbers.begin();
        while ( it1 != numbers.end() )
        {
            const int leftnum = target - *it1; 
            auto it2 = numbers.end();
            if ( mididx<=(it1-numbers.begin()) )
                it2 = find( it1+1, numbers.end(), leftnum );
            else
            {
                if ( leftnum < middlenum )
                {
                    it2 = find(it1+1, numbers.begin()+mididx, leftnum );
                    if ( *it2 == middlenum )
                        it2 = numbers.end();
                }
                else 
                    it2 = find( numbers.begin()+mididx, numbers.end(), leftnum );
            }

            if ( it2 != numbers.end() )
            {
                
                
                numbers[0] = it1 - numbers.begin() + 1;
                
                numbers[1] = it2 - numbers.begin() + 1;
                
                numbers.erase( numbers.begin()+2, numbers.end() );
                break;
            }

            it1++;
        }

        return numbers;
    }
};

//using binary search tree
class Solution {
public:
    bool isPresent( int number, const vector<int>& numbers )
    {
        const int size = numbers.size();
        const int mididx = floor( size/2 );
        const int midnum = numbers[mididx];
        if ( size > 1 )
        {
            if ( number < midnum )
                return isPresent( number, vector<int>(numbers.begin(), numbers.begin()+mididx ) );
            else
                return isPresent( number, vector<int>(numbers.begin()+mididx, numbers.end() ) );
        }

        return number == midnum;
    }

    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        const int size = numbers.size();
        
        for ( int idx=0; idx<size; idx++ )
        {
            const int currnum = numbers[idx];
            const int leftnum = target-currnum;
            if ( isPresent(leftnum,numbers) )
            {
                auto it2 = find(numbers.begin() + idx +1, numbers.end(), leftnum );
                numbers[0] = idx + 1;
                numbers[1] = it2 - numbers.begin() + 1;
                numbers.erase( numbers.begin()+2, numbers.end() );
                break;
            }
        }

        return numbers;
    }
};

class Solution {
public:
    
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        const int size = numbers.size();
        auto itl = numbers.begin();
        auto itr = numbers.begin()+size-1;
        vector<int> result;
        while ( true )
        {
            const int sum = *itr + *itl;
            if ( sum == target )
            {
                result.push_back(itl-numbers.begin()+1);
                result.push_back(itr-numbers.begin()+1);
                return result;
            }
            else
            {
                if ( sum > target )
                    itr--;
                else
                    itl++;
            }
        }
        
        return {};
    }
};
