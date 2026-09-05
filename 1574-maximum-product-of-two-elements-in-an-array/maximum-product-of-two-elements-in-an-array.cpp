class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int firstMax = 0;
        int secondMax = 0;

        for(int num : nums) {
            if(num > firstMax) {
                secondMax = firstMax;
                firstMax = num;
            }
            else if(num > secondMax) {
                secondMax = num;
            }
        }

        return (firstMax - 1) * (secondMax - 1);
    }
};