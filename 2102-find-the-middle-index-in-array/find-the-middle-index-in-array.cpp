class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {

        int sum = 0;

        for(int num : nums){
            sum += num;
        }

        int leftSum = 0;
        int rightSum = sum;

        for(int i = 0; i < nums.size(); i++){

            rightSum -= nums[i];

            if(leftSum == rightSum){
                return i;
            }

            leftSum += nums[i];
        }

        return -1;
    }
};