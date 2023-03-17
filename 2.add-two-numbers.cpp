/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode l1_head = ListNode(0);
        l1_head.next = l1;
        ListNode* former_l1_ptr = &l1_head;
        bool carry = false;
        while (true) {
            if (l2 == nullptr) {
                break;
            }

            if (l1 == nullptr) {
                former_l1_ptr->next = l2;
                l1 = l2;
                break;
            }

            l1->val += l2->val + carry;
            if (l1->val > 9) {
                carry = true;
                l1->val -= 10;
            } else {
                carry = false;
            }

            former_l1_ptr = l1;
            l1 = l1->next;
            l2 = l2->next;
        }

        while (carry == true) {
            if (l1 == nullptr) {
                former_l1_ptr->next = new ListNode(1);
                break;
            }

            if (l1->val < 9) {
                l1->val += 1;
                break;
            }

            // l1->val == 9
            l1->val = 0;
            former_l1_ptr = l1;
            l1 = l1->next;
        }

        return l1_head.next;
    }
};
// @lc code=end

