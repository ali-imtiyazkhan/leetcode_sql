class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int ans = 0;
        int pushes = 1;

        while (n >= 8) {
            ans += pushes * 8;
            n -= 8;
            pushes++;
        }

        ans += pushes * n;

        return ans;
    }
};