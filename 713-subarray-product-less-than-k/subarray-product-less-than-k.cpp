class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;

        long long product = 1;
        int left = 0;
        int result = 0;

        for(int right = 0; right < nums.size(); right++) {
            product *= nums[right];

            while(product >= k && left <= right) {
                product /= nums[left];
                left++;
            }

            result += (right - left + 1);
        }
        return result;
    }
};
