// https://leetcode.com/explore/interview/card/top-interview-questions-easy/94/trees/625/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    bool first_time = true;
    int max = 0;
public:
    bool isValidBST(TreeNode* root) {
        first_time = true;
        return bst(root);
    }
    bool bst(TreeNode* root) {
        if (!root) {
            return true;
        }
        if (!bst(root->left)) {
            return false;
        }
        if (first_time && !root->left) {
            first_time = false;
            max = root->val;
        } else if (root->val <= max) {
            return false;
        }
        max = root->val;
        if (!bst(root->right)) {
            return false;
        }
        return true;
    }
};
