class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result;

        for (int i = 0; i < nums.size(); i++) {
            int value = abs(nums[i]);
            int position = value - 1;

            if (nums[position] > 0) {
                nums[position] = -nums[position];
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                result.push_back(i + 1);
            }
        }

        return result;
    }
};