class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> left, equal, right;

        for (int num : nums) {
            if (num < pivot)
                left.push_back(num);
            else if (num == pivot)
                equal.push_back(num);
            else
                right.push_back(num);
        }

        left.insert(left.end(), equal.begin(), equal.end());
        left.insert(left.end(), right.begin(), right.end());

        return left;
    }
};