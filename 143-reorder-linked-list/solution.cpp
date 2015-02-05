/*============================================================================
* Name : solution.cpp
* Author: taikido
* Description: Reorder Linked List
* Source: https://oj.leetcode.com/problems/reorder-list/
* Date: Wed.Feb.4.2015
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
    void reorderList(ListNode* head)
    {
         int length = len(head);
         if (length <= 2) return;

         // Cut list in half

         ListNode* upper = head, *curr = head, *tail;

         int mid = length/2;

         for(int i=0; i<mid-1; i++)
             curr = curr->next;

         tail = curr->next;

         curr->next = 0;

         reverse(tail);

         ListNode* upper_next, *tail_next; // Names led to 2 similar bugs - use better names next time

         while(upper && tail)
         {
             upper_next = upper->next;
             tail_next = tail->next;
             upper->next = tail;
             tail->next = upper_next;

             if (!upper_next) break; // bug was (!upper->next)

             upper = upper_next;
             tail = tail_next;  // bug tail->next;
         }

         if (tail)
             tail->next = tail_next;


    }

    void reverse(ListNode*& head)
    {
        if (!head) return;
        ListNode* first = head;
        ListNode* tail = head->next;

        if (!tail) return;
        reverse(tail);
        first->next->next = first;
        first->next = 0;
        head = tail;
    }

    int len(ListNode* head)
    {
        if (!head) return 0;

        ListNode* curr = head;
        int l = 0;
        while(curr)
        {
            curr = curr->next;
            l++;
        }

        return l;
    }
};