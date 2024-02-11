//https://leetcode.com/problems/permutations/editorial/


class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr = {};
        backtrack(curr, ans, nums);
        return ans;
    }

    /*Explanation of following 	
	123 : Initial position
	1   | 123 : Adding 1 to curr vector and calling recursion
	12  | 123 : 1 already added so adding next number 2
	123 | 123 =>123 : Similarly adding 3 and adding it to answer vector
	12  | 123 : popping 2
	13  | 123 : Next number 3 added
	132 | 123 =>132 : Missing number 2 added and sequence added to answer
     */
    
    void backtrack(vector<int>& curr, vector<vector<int>>& ans, vector<int>& nums) {
        if (curr.size() == nums.size()) {
            ans.push_back(curr);
            return;
        }
        
        for (int num: nums) {
            if (find(curr.begin(), curr.end(), num) == curr.end()) {
                curr.push_back(num);
                backtrack(curr, ans, nums);
                curr.pop_back();
            }
        }
    }
};
