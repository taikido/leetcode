/*============================================================================
* Name : solution.cpp
* Author: taikido
* Description: Leetcode Problem 148: Sorted a linked list in O(Nlog(N))
* Source: https://oj.leetcode.com/problems/sort-list/
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
    ListNode *sortList(ListNode *head) {

        mergesort(head);
        ListNode* sorted_list = head;

        return sorted_list;
    }

    void mergesort(ListNode*& a)
    {
        if (!a || !a->next) return;

        ListNode* front = 0, *back = 0;
        split(a, front, back);
        mergesort(front);
        mergesort(back);

        ListNode* c = 0;
        merge(front, back, c);
        a = c;
    }


    void split(ListNode*& a, ListNode*& front, ListNode*& back)
    {
        if (!a) return;
        if (!a->next)
        {
            front = a; // assume back = 0
            return;
        }

        int l = len(a);
        front = a;
        ListNode* curr = a;

        for(int i=0; i < (l/2) - 1; i++)
            curr = curr->next;

        back = curr->next;
        curr->next = 0; // Remember to separate lists

    }


    int len(ListNode* a)
    {
        ListNode* curr = a;

        int l = 0;

        while(curr)
        {
            l++;
            curr = curr->next;
        }

        return l;

    }



    /*
        merge: assume 2 lists are sorted and merge them in increasing order
    */


    void merge(ListNode*& a, ListNode*& b, ListNode*& c)
    {

        if (!a && !b) return;

        ListNode* currA = a, *currB = b;

        while (currA && currB)
        {
            if (currA->val < currB->val)
                moveNode(currA, c);  // Move currA not a
            else
                moveNode(currB, c);
        }

        while(currA)  moveNode(currA, c);
        while(currB)  moveNode(currB, c);

        reverse(c);

    }

    void reverse(ListNode*& a)
    {
        ListNode* b = 0;

        while(a) moveNode(a, b);
        a = b;
    }

    // Moves head from a to b
    void moveNode(ListNode*& a, ListNode*& b)
    {
        if (!a) return;

        ListNode* temp = a->next;
        a->next = b;
        b = a;
        a = temp;
    }
};