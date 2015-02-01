/*============================================================================
* Name : solution.cpp
* Author: taikido
* Description: Leetcode Problem 2: Add Two Numbers
* Source: https://oj.leetcode.com/problems/add-two-numbers/
* Date: Jan.2015
* Status: Accepted
*===========================================================================*/

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode* l3 = 0;
        ListNode* curr;
        int digit, sum, carry = 0;

        while (l1 && l2)
        {
            sum = (carry + l1->val + l2->val);
            digit = sum % 10;
            carry = sum/10;

            if (!l3)
            {
                l3 = new ListNode(digit);
                curr = l3;
            }
            else
            {
                curr->next = new ListNode(digit);
                curr = curr->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1)
        {
            sum = (carry + l1->val);
            digit = sum % 10;
            carry = sum/10;
            if (!l3)
            {
                l3 = new ListNode(digit);
                curr = l3;
            }
            else
            {
                curr->next = new ListNode(digit);
                curr = curr->next;
            }
            l1 = l1->next;
        }
        while (l2)
       {
            sum = (carry + l2->val);
            digit = sum % 10;
            carry = sum/10;

            if (!l3)
            {
                l3 = new ListNode(digit);
                curr = l3;
            }
            else
            {
                curr->next = new ListNode(digit);
                curr = curr->next;
            }
            l2 = l2->next;
        }

        if (carry > 0)
        {
           curr->next = new ListNode(carry);
        }
       return l3;
    }
};
