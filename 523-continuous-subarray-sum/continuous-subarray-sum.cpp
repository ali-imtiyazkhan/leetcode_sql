class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> firstIndex;
        firstIndex[0] = -1;

        long long prefixSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];

            int rem;
            if (k == 0) {
                rem = prefixSum;
            } else {
                rem = prefixSum % k;
                if (rem < 0) rem += abs(k);
            }

            if (firstIndex.count(rem)) {
                if (i - firstIndex[rem] >= 2)
                    return true;
            } else {
                firstIndex[rem] = i;
            }
        }

        return false;
    }
};