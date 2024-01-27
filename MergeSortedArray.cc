//https://leetcode.com/problems/merge-sorted-array/?envType=study-plan-v2&envId=top-interview-150
//
//
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        const int totsz = m + n;
        for ( int idx = m; idx<totsz; idx++ )
            nums1[idx] = nums2[idx-m];
         
        sort( nums1.begin(), nums1.end() );
//Below is O(m+n) complexity solution
    //     int num1idx = m-1;
    //     int num2idx = n-1;
    //     int totidx = m+n-1;
    //     while( num2idx >= 0 )
    //     {
    //         if ( num1idx>=0 && (nums1[num1idx] > nums2[num2idx]) )
    //         {
    //             nums1[totidx] = nums1[num1idx];
    //             totidx--;
    //             num1idx--;
    //         }
    //         else
    //         {
    //             nums1[totidx] = nums2[num2idx];
    //             totidx--;
    //             num2idx--;
    //         }
    //     }
     }
};
