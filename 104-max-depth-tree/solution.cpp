/*============================================================================
* Name : solution.cpp
* Author: taikido
* Description: Maximum Depth of a Binary Tree
* Source: https://oj.leetcode.com/problems/maximum-depth-of-binary-tree/
* Date: Mon.Feb.2.2015
* Status: Accepted
*===========================================================================*/

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
    int max(int a, int b)
    {
        return (a > b ? a : b);
    }

    int maxDepth(TreeNode* root)
    {
        if (!root) return 0;
        int left_depth = maxDepth(root->left) + 1;
        int right_depth = maxDepth(root->right) + 1;

        return max(left_depth, right_depth);
    }
};