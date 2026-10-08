class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxWater = 0;
        int currentWater = 0;

        int right = n -1 ;
        int left = 0;

        while(left <= right){

            currentWater = (right-left)*min(height[left],height[right]);

            maxWater = max(currentWater,maxWater);


            if(height[left]< height[right]){
                    
                    left++;

            }else{
                right--;
            }

        }
     return maxWater;
        
    }
};