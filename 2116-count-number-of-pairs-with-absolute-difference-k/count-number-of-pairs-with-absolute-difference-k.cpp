class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {

            int target1 = nums[i] - k;
            int target2 = nums[i] + k;

            if (mp.count(target1)) {
                count += mp[target1];
            }

            if (mp.count(target2)) {
                count += mp[target2];
            }

            mp[nums[i]]++;
        }

        return count;
    }
};