// https://leetcode.com/explore/interview/card/top-interview-questions-easy/93/linked-list/771/
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* prev;
        ListNode* head;
        if (l1 && (!l2 || l1->val <= l2->val)) {
            head = l1;
        } else {
            head = l2;
        }
        bool moved;
        while (l1 || l2) {
            moved = false;
            while (l1 && (!l2 || l1->val <= l2->val)) {
                prev = l1;
                l1 = l1->next;
                moved = true;
            }
            if (moved) prev->next = l2;
            moved = false;
            while (l2 && (!l1 || l1->val >= l2->val)) {
                prev = l2;
                l2 = l2->next;
                moved = true;
            }
            if (moved) prev->next = l1;
        }
        return head;
    }
};
