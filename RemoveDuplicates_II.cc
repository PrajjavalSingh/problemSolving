//https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        const int size = nums.size();
        auto it1 = nums.begin();
        auto it2 = nums.begin()+1;
        while( it2 != nums.end() )
        {
            if ( *it1 != *it2 )
            {
                it1++;
                it2++; 
                continue;
            }
            else
            {
                while( true )
                {
                    it2++;
                    if ( it2 == nums.end() )
                        break;
                    
                    if ( *it1 == *it2 )
                    {
                        nums.erase( it1 );
                        it2--;
                        continue;
                    }

                    it1++;
                    break;
                }
            }
        }

        // for ( int idx=size-1; idx>=1; idx-- )
        // {
        //     if ( nums[idx] != nums[idx-1] )
        //         continue;
        //     else
        //     {
        //         while(idx!=1)
        //         {
        //             idx--;
        //             if ( nums[idx] == nums[idx-1] )
        //             {
        //                 nums.erase(nums.begin()+idx);
        //                 continue;
        //             }

        //             break;
        //         } 
        //     }

        // }

        
        return nums.size();
    }
};
