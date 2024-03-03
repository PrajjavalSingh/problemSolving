//https://leetcode.com/problems/kth-largest-element-in-an-array/?envType=study-plan-v2&envId=top-interview-150
//Using priority queue : good exercise
//similar solution with vector will result in timeout for bigger cases
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        std::priority_queue<int,vector<int>,greater<int>> heap(nums.begin(),nums.begin()+k);
        for ( int idx=k; idx<nums.size(); idx++ )
        {
            if ( nums[idx] > heap.top() )
            {
                heap.pop();
                heap.push( nums[idx] );
            }
        } 

        return heap.top();
    }
};
