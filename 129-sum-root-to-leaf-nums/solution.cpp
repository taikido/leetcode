/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sumNumbers(TreeNode *root) {

        return sumNumbers(root, 1, 0);
    }

    int sumNumbers(TreeNode *root, int level, int sum)
    {
        if (!root) return 0;

        if (!root->left && !root->right && level == 1) return root->val;

        if (!root->left && !root->right && level > 1)
            return (sum * 10) + root->val;

        sum = (sum * 10) + root->val;
        return sumNumbers(root->left, level+1, sum) + sumNumbers(root->right, level+1, sum);
    }
};