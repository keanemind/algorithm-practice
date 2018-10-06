// https://leetcode.com/explore/interview/card/top-interview-questions-easy/93/linked-list/603/
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* back = head;

        // Offset front from back by n
        ListNode* front = back;
        for (int i = 0; i < n; i++) {
            front = front->next;
        }

        // Move both back and front until front reaches end
        while (front && front->next != nullptr) {
            back = back->next;
            front = front->next;
        }

        // Check for edge cases (could be head or tail or other)
        ListNode* next = back->next;
        // back is behind the node to be removed in all cases
        // except when the node to be removed is head.
        if (front == nullptr) {
            // back == head
            delete back;
            return next;
        }
        // Remove the node after back (could be tail)
        back->next = next->next;
        delete next;
        return head;
    }
};
