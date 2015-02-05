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

ListNode *reverseBetween(ListNode *head, int m, int n) {

    if (m == n) return head;

    ListNode* a = head;
    ListNode* b = head;
    //ListNode* c;

    //int i = 0, j = 0;
    for(int i = 0; i<m-2; i++)
        a = a->next;

    for (int j=0; j<n-1; j++)
        b = b->next;

    ListNode* c = b->next;
    ListNode* mid_list;

    if ( m > 1)
    {
        mid_list = a->next;
        a->next = 0;
    }
    else mid_list = a;

    b->next = 0;

    reverse(mid_list);

    if (m > 1) a->next = mid_list;
    else a = mid_list;


    ListNode* d = mid_list;

    while(d->next)
        d = d->next;

    d->next = c;

    if (m == 1) return a;
    else return head;


}



    void moveNode(ListNode*& a, ListNode*& b)
    {
        if (!a) return;

        ListNode* next = a->next;
        a->next = b;
        b = a;
        a = next;
    }


    void reverse(ListNode*& a)
    {
        ListNode* c = 0;
        while(a)
            moveNode(a, c);
        a = c;

    }
};