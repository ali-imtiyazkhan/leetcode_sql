class Solution {
public:
    struct BIT {
        vector<long long> bit;

        BIT(int n) {
            bit.assign(n + 1, 0);
        }

        void update(int idx, long long val) {
            while (idx < bit.size()) {
                bit[idx] += val;
                idx += idx & (-idx);
            }
        }

        long long query(int idx) {
            long long res = 0;
            while (idx > 0) {
                res += bit[idx];
                idx -= idx & (-idx);
            }
            return res;
        }
    };

    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        vector<long long> pref(n + 1, 0);

        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + (nums[i] == target ? 1 : -1);
        }

        vector<long long> vals = pref;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        BIT bit(vals.size() + 2);

        long long ans = 0;

        for (long long x : pref) {
            int pos = lower_bound(vals.begin(), vals.end(), x) - vals.begin() + 1;

            // Count previous prefix sums strictly smaller than x
            ans += bit.query(pos - 1);

            // Insert current prefix sum
            bit.update(pos, 1);
        }

        return ans;
    }
};