class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;

        for (int start = 1; start <= 9; start++) {
            int num = start;
            int next = start + 1;

            while (next <= 9) {
                num = num * 10 + next;

                if (num >= low && num <= high)
                    ans.push_back(num);

                next++;
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};