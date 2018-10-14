// https://leetcode.com/explore/interview/card/top-interview-questions-easy/94/trees/628/
#include <vector>
#include <queue>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
using namespace std;

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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if (!root) {
            return ret;
        }
        queue<TreeNode*> queue;
        queue.push(root);
        TreeNode* current;
        size_t size;
        while (!queue.empty()) {
            size = queue.size();
            ret.push_back(vector<int>());
            for (size_t i = 0; i < size; i++) {
                current = queue.front();
                queue.pop();
                ret[ret.size()-1].push_back(current->val);
                if (current->left) queue.push(current->left);
                if (current->right) queue.push(current->right);
            }
        }
        return ret;
    }
};
