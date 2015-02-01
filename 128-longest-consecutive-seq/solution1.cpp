/*============================================================================
* Name : solution1.cpp
* Author: taikido
* Description: Longest Consecutive Sequence
* Source: hhttps://oj.leetcode.com/problems/longest-consecutive-sequence/
* Date: Sun.Feb.1.2015
* Status: Time Limit Exceeded
*===========================================================================*/

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        Node* head = 0;
        constructList(head, num);

        int count = countConsecutives(head);
        return count;
    }

    struct Node
    {
        int data;
        Node* next;

        Node(int data) : data(data), next(0) {};
        Node(int data, Node* next) : data(data), next(next) {};
    };


    void push(Node*& head, int data)
    {
        Node* n = new Node(data, head);
        head = n;
        return;
    }

    void insert(Node*& head, int data)
    {
        // Empty list
        if (!head )
        {
            Node* n = new Node(data, head);
            head = n;
            return;
        }

        // 1 Element List
        if (!head->next)
        {
            if (data < head->data)
            {
                Node* n = new Node(data, head);
                head = n;
                return;
            }
            else
            {
                Node* temp = head->next;
                Node* n = new Node(data, temp);
                head->next = n;
            }
        }

        // 2 or more Element List

        if (data <= head->data)
        {
            push(head, data);
        }
        else
        {
            Node* curr = head;
            Node* next = curr->next;

            while (next)
            {
                if (data <= next->data)
                {
                    Node* temp = next->next;
                    //push(next, data);
                    Node* n = new Node(data, next);
                    curr->next = n;
                    curr = curr->next;
                    next = temp;
                    break; // break when we've found correct position
                }
                else if (data > next->data & !next->next)
                {
                    Node* n = new Node(data, next->next);
                    next->next = n;
                    curr = next;
                    next = next->next;
                    break;
                }
                else
                {
                    next = next->next;
                    curr = curr->next;
                }

            }
        }

    }

    void constructList(Node*& head, vector<int> &num)
    {
        //Node* tail = 0;

        for(int i=0; i<num.size(); i++)
        {
            //append(head, tail, num[i]);
            insert(head, num[i]);
        }
    }

    int countConsecutives(Node* head)
    {
        if (!head) return 0;
        if (!head ->next) return 1;

        int count = 1;

        int max_count = 1;

        Node* curr = head;

        while(curr)
        {
            if (curr->next)
            {
                if ((curr->next->data - curr->data) == 1)
                    count++;
                else
                {

                    count = 1; // reset count
                }
            }
            curr = curr->next;
            if (count > max_count) max_count = count;

        }

        return max_count;


    }


};

/*
    void append(Node*& head, Node*&tail, int data);
    {
        if (!head && !tail)
        {

            Node* n = Node(data, head);
            head = n;
            tail = head;
        }

        else
        {
            Node* n = Node(data, tail->next);
            tail->next = n;
            tail = n;
        }

    }
*/