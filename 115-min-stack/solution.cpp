/*============================================================================
* Name : solution.cpp
* Author: taikido
* Description: Min Stack
* Source: https://oj.leetcode.com/problems/min-stack/
* Date: Sun.Feb.1.2015
* Status: Memory Limit Exceeded
*===========================================================================*/

class MinStack {
public:

    struct Node
    {
        int data;
        Node* next;

        Node(int data) : data(data), next(0) {}
        Node(int data, Node* next) : data(data), next(next) {}

    };

    MinStack()
    {
        head = 0;
        min_stack = 0;
    }

    void push(int x) {
        Node* n = new Node(x, head);
        head = n;

        if (!min_stack || (x<= min_stack->data))
        {
            Node* n = new Node(x, min_stack);
            min_stack = n;
        }

    }

    void pop() {

        if (!head) return;

        if ( (head && min_stack) && (head->data == min_stack->data))
        {
            Node* next = min_stack->next;
            delete min_stack;
            min_stack = next;
        }

        Node* next = head->next;
        delete head;
        head = next;
    }

    int top() {
        if (head) return head->data;
    }

    int getMin() {
        if (min_stack) return min_stack->data;
    }

    Node* head;
    Node* min_stack;
};