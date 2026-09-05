class Solution {
public:
    void sortColors(vector<int>& nums) {
        int oneCount = 0;
        int twoCount = 0;
        int zeroCount = 0;

        for(int num :nums){
            if(num == 1){
                oneCount++;
            }
            else if(num == 0){
                zeroCount++;
            }else{
                twoCount++;
            }
        }

        int i = 0;

        while(zeroCount--){
            nums[i++]= 0;
        }

        while(oneCount--){
            nums[i++] = 1;
        }

        while(twoCount--){
            nums[i++] = 2;
        }
       
    }
};