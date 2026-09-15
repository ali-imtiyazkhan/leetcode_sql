class Solution {
public:
    void backtrack(vector<int>& nums, int start,
                   vector<int>& current,
                   vector<vector<int>>& result) {

        if (start >= nums.size()) {
            result.push_back(current);
            return;
        }

        backtrack(nums, start + 1, current, result);

        current.push_back(nums[start]);

        backtrack(nums, start + 1, current, result);

        current.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;

        backtrack(nums, 0, current, result);

        return result;
    }
};