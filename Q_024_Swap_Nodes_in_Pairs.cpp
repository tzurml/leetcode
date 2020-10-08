//
// Created by tzur on 10/6/2020.
//

//Given a linked list, swap every two adjacent nodes and return its head.
//
//You may not modify the values in the list's nodes. Only nodes itself may be changed.
//
//Example 1:
//
//
//Input: head = [1,2,3,4]
//Output: [2,1,4,3]
//Example 2:
//
//Input: head = []
//Output: []
//Example 3:
//
//Input: head = [1]
//Output: [1]

#include "iostream"
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* tmp = head;
        ListNode *prev = new ListNode();
        ListNode *next = nullptr;
        ListNode* ret = head;


        while(tmp && tmp->next)
        {
            next = tmp->next;
            tmp->next = next->next;
            next->next = tmp;
            if (prev->next != nullptr)
            {
                prev->next = next;
            }
            else
            {
                ret = next;
            }

            prev = tmp;
            tmp = tmp->next;
        }
        return ret;
    }
};


int main()
{
    auto x1 = new ListNode(4);
    auto x2 = new ListNode(3,x1);
    auto x3 = new ListNode(2,x2);
    auto x4 = new ListNode(1,x3);

    Solution s;
    auto y = s.swapPairs(x4);
    while(y)
    {
        cout << y->val << endl ;
        y = y->next;
    }

}
