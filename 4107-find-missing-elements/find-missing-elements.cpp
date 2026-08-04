class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_set<int> st;

        int mn = INT_MAX;
        int mx = INT_MIN;

        for (int num : nums) {
            st.insert(num);
            mn = min(mn, num);
            mx = max(mx, num);
        }

        vector<int> ans;

        for (int i = mn; i <= mx; i++) {
            if (st.find(i) == st.end()) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};