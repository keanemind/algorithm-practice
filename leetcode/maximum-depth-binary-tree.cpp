// https://leetcode.com/explore/interview/card/top-interview-questions-easy/94/trees/555/
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
    int maxDepth(TreeNode* root) {
        // Breadth first search
        if (!root) {
            return 0;
        }
        queue<TreeNode*> queue;
        queue.push(root);
        TreeNode* current;
        int size;
        int depth = 0;
        while (!queue.empty()) {
            size = queue.size();
            for (int i = 0; i < size; i++) {
                current = queue.front();
                queue.pop();
                if (current->left) {
                    queue.push(current->left);
                }
                if (current->right) {
                    queue.push(current->right);
                }
            }
            depth++;
        }
        return depth;
    }
};
