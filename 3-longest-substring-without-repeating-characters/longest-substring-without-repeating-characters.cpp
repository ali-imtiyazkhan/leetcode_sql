class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;

        int left = 0;
        int maxLength = 0;

        for (int i = 0; i < s.length(); i++) {

            mp[s[i]]++;

            while (mp[s[i]] > 1) {
                mp[s[left]]--;
                left++;
            }

            int currentLength = i - left + 1;

            maxLength = max(maxLength, currentLength);
        }

        return maxLength;
    }
};