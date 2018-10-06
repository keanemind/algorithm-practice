// https://leetcode.com/explore/interview/card/top-interview-questions-easy/93/linked-list/560/
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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* new_head = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return new_head;
        // If head is not the true head, then head->next will be changed once
        // the function returns.
        // If head is the true head (this is the root function), then nullptr
        // is the correct value for head->next.
    }
};
