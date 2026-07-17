class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        vector<int> freq(mx + 1, 0);
        for (int x : nums)
            freq[x]++;

        vector<long long> exact(mx + 1, 0);

        for (int i = 1; i <= mx; i++) {
            long long cnt = 0;
            for (int j = i; j <= mx; j += i)
                cnt += freq[j];

            exact[i] = cnt * (cnt - 1) / 2;
        }

        for (int i = mx; i >= 1; i--) {
            for (int j = i * 2; j <= mx; j += i)
                exact[i] -= exact[j];
        }

        vector<long long> prefix(mx + 1, 0);
        for (int i = 1; i <= mx; i++)
            prefix[i] = prefix[i - 1] + exact[i];

        vector<int> ans;
        for (long long q : queries) {
            int l = 1, r = mx;
            while (l < r) {
                int mid = (l + r) / 2;
                if (prefix[mid] > q)
                    r = mid;
                else
                    l = mid + 1;
            }
            ans.push_back(l);
        }

        return ans;
    }
};