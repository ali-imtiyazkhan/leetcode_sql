class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> ans;

        for (int i = 0; i < nums.size() - 1; i++) {
            int curr = nums[i];
            int next = nums[i + 1];

            for (int j = curr + 1; j < next; j++) {
                ans.push_back(j);
            }
        }

        return ans;
    }
};