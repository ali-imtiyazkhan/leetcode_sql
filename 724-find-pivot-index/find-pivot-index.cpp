class Solution {
public:
    int pivotIndex(vector<int>& nums) {
      int total = 0;
      for(int num : nums){
        total += num;
      }

      int leftSum = 0;

      for(int i = 0; i < nums.size(); i++){
        int rightSum = total - nums[i] - leftSum;

        if(rightSum == leftSum){
            return i;
        }

        leftSum += nums[i];
      }

      return -1;
    }
};