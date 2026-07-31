class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;

        int i = s.length() - 1;

        while (i >= 0) {

            while (i >= 0 && s[i] == ' ')
                i--;

            if (i < 0)
                break;

            int j = i;

            while (j >= 0 && s[j] != ' ')
                j--;

            words.push_back(s.substr(j + 1, i - j));

            i = j;
        }

        string ans;

        for (int k = 0; k < words.size(); k++) {
            ans += words[k];

            if (k != words.size() - 1)
                ans += " ";
        }

        return ans;
    }
};