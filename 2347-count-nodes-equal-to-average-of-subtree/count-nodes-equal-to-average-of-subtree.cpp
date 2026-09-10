class Solution {
public:

    pair<int, int> dfs(TreeNode* root, int& ans) {

        if (root == nullptr) {
            return {0, 0};
        }

        pair<int, int> left = dfs(root->left, ans);

        pair<int, int> right = dfs(root->right, ans);

        int sum = root->val + left.first + right.first;

        int count = 1 + left.second + right.second;

        int average = sum / count;


        if (root->val == average) {
            ans++;
        }

        return {sum, count};
    }

    int averageOfSubtree(TreeNode* root) {

        int ans = 0;

        dfs(root, ans);

        return ans;
    }
};