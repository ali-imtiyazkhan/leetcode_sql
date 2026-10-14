class Solution {
public:
    int findMin(vector<int>& nums) {
        int mini = nums[0];

        for(int num : nums){
            if(num < mini){
                mini = num;
            }
        }
     return mini;
    }
};