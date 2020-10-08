//
// Created by tzur on 9/25/2020.
//

//Given a linked list, remove the n-th node from the end of list and return its head.
//
//Example:
//
//Given linked list: 1->2->3->4->5, and n = 2.
//
//After removing the second node from the end, the linked list becomes 1->2->3->5.
//Note:
//
//Given n will always be valid.


 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!(head->next)){return nullptr;}
        ListNode* start = head;
        ListNode* end = head;
        ListNode* prev = head;
        int step = n -1;
        while(end->next != nullptr)
        {
            end = end->next;
            if (step){step--;}
            else
            {
                prev = start;
                start = start->next;
            }
        }
        if (start == head){return head->next;}

        prev->next = start->next;
        return head;
    }
};

