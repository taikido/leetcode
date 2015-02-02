/*============================================================================
* Name : solution.cpp
* Author: taikido
* Description: Balanced Binary Tree
* Source: https://oj.leetcode.com/problems/balanced-binary-tree/
* Date: Sun.Feb.1.2015
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
    bool isBalanced(TreeNode *root) {
        if (!root ) return true; // || (!root->left && !root->right)

        int left_height = getHeight(root->left);
        int right_height = getHeight(root->right);

        int height_diff = abs(left_height - right_height);

        if (height_diff > 1)
            return false;
        else return (isBalanced(root->left) && isBalanced(root->right));


    }

    int getHeight(TreeNode* root)
    {
        if (!root) return 0;
        else return max(getHeight(root->left), getHeight(root->right)) + 1;
    }

    int max(int a, int b)
    {
        return (a > b ? a : b);
    }

    /*
    int numNodes(TreeNode* root)
    {
        if (!root) return 0;
        else return  numNodes(root->left) + 1 +  numNodes(root->right);
    }*/
};


/*
This is actually the code for size (i.e. number of nodes in Tree)
    int getHeight(TreeNode* root)
    {
        if (!root) return 0;
        else return getHeight(root->left) + 1 + getHeight(root->right);
    }

*/