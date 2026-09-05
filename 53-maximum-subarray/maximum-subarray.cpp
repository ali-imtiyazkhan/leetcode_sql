class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int currentSum = 0;
       int maxSum = INT_MIN;
       int n = nums.size();

       for(int i = 0 ; i < n; i++){
         currentSum += nums[i];
         maxSum = max(maxSum,currentSum);

         if(currentSum < 0){
            currentSum = 0;
         }
       }
       return maxSum;
    }
};
