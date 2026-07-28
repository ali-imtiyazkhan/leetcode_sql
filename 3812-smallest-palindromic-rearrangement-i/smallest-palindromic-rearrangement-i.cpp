class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26, 0);

        for (char ch : s)
            freq[ch - 'a']++;

        string left = "";
        string mid = "";

        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 == 1)
                mid = char(i + 'a');

            left.append(freq[i] / 2, char(i + 'a'));
        }

        string right = left;
        reverse(right.begin(), right.end());

        return left + mid + right;
    }
};