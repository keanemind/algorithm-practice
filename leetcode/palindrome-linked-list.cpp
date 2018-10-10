// https://leetcode.com/explore/interview/card/top-interview-questions-easy/93/linked-list/772/
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
    bool isPalindrome(ListNode* head) {
        // Find middle of list
        ListNode* current = head;
        ListNode* true_middle;
        int length = 0;
        while (current) {
            current = current->next;
            length++;
        }
        current = head;
        for (int i = 0; i < length / 2; i++) {
            current = current->next;
        }
        // For odd length linked lists, true middle is the middle node.
        // For even length linked lists, true middle is the same as halfpoint.
        true_middle = current;
        if (length % 2) {
            current = current->next;
        }
        // Halfpoint is the first node in the second half of the linked list.
        // For an odd length linked list, halfpoint is the node after the
        // middle node.
        ListNode* halfpoint = current;

        // Reverse order of second half
        ListNode* prev = nullptr;
        ListNode* temp;
        while (current) {
            temp = current->next;
            current->next = prev;
            prev = current;
            current = temp;
        }
        ListNode* reversed_head = prev;

        // Compare first and second half
        current = head;
        ListNode* current2 = reversed_head;
        bool retval = true;
        while ((current != true_middle) && current2) {
            if (current->val != current2->val) {
                retval = false;
                break;
            }
            current = current->next;
            current2 = current2->next;
        }
        if ((current != true_middle) != !!current2) { // Same length check
            retval = false;
        }

        // Restore order of second half
        prev = nullptr;
        current = reversed_head;
        while (current) {
            temp = current->next;
            current->next = prev;
            prev = current;
            current = temp;
        }

        return retval;
    }
};
