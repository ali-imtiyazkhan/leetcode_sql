class Solution {
public:
    int maxDepth(string s) {
        int maxAns = 0;
        int count = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                count++;
                maxAns = max(maxAns, count);
            }
            else if (s[i] == ')') {
                count--;
            }
        }

        return maxAns;
    }
};