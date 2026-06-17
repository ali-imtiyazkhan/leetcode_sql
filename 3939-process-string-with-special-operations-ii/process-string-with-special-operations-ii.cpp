class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.size();

        vector<long long> len(n + 1, 0);

        const long long LIM = (long long)1e15;

        for (int i = 0; i < n; i++) {
            long long cur = len[i];

            if (islower(s[i])) {
                len[i + 1] = min(LIM, cur + 1);
            }
            else if (s[i] == '*') {
                len[i + 1] = max(0LL, cur - 1);
            }
            else if (s[i] == '#') {
                len[i + 1] = min(LIM, cur * 2);
            }
            else { 
                len[i + 1] = cur;
            }
        }

        if (k >= len[n]) return '.';

        for (int i = n - 1; i >= 0; i--) {

            long long oldLen = len[i];
            char c = s[i];

            if (islower(c)) {

                if (k == oldLen)
                    return c;

            }
            else if (c == '#') {

                if (oldLen > 0)
                    k %= oldLen;

            }
            else if (c == '%') {

                if (oldLen > 0)
                    k = oldLen - 1 - k;

            }
    
        }

        return '.';
    }
};