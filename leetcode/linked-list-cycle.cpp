// https://leetcode.com/explore/interview/card/top-interview-questions-easy/93/linked-list/773/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // Reverse every node as you traverse and
        // see if the head is encountered again.
        ListNode* prev  = nullptr;
        ListNode* current = head;
        ListNode* next;
        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            if (current == head) {
                return true;
            }
        }
        return false;
    }
};
