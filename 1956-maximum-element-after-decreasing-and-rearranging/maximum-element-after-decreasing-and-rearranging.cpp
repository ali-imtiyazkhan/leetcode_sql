class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());

        int prev = 1;

        for(int i = 1; i < arr.size();i++){
            prev = min(arr[i],prev+1);
        }

        return prev;
    }
};