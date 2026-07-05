class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        const int MOD = 1e9 + 7;
        int n = board.size();

        vector<vector<int>> score(n + 1, vector<int>(n + 1, -1));
        vector<vector<int>> ways(n + 1, vector<int>(n + 1, 0));

        score[n - 1][n - 1] = 0;
        ways[n - 1][n - 1] = 1;

        int dx[3] = {1, 0, 1};
        int dy[3] = {0, 1, 1};

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {

                if (board[i][j] == 'X' || board[i][j] == 'S')
                    continue;

                int best = -1;
                int cnt = 0;

                for (int k = 0; k < 3; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];

                    if (score[ni][nj] > best) {
                        best = score[ni][nj];
                        cnt = ways[ni][nj];
                    } else if (score[ni][nj] == best && best != -1) {
                        cnt = (cnt + ways[ni][nj]) % MOD;
                    }
                }

                if (best == -1)
                    continue;

                score[i][j] = best;
                ways[i][j] = cnt;

                if (board[i][j] != 'E')
                    score[i][j] += board[i][j] - '0';
            }
        }

        if (ways[0][0] == 0)
            return {0, 0};

        return {score[0][0], ways[0][0]};
    }
};