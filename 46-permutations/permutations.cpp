class Solution {
private:
    void solve(vector<int> nums, vector<vector<int>> &result, int index) {

        if (index >= nums.size()) {
            result.push_back(nums);
            return;
        }

        for (int j = index; j < nums.size(); j++) {
            swap(nums[index], nums[j]);

            solve(nums, result, index + 1);

            swap(nums[index], nums[j]);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(nums, ans, 0);
        return ans;
    }
};
