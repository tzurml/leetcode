//
// Created by tzur on 10/5/2020.
//
//Merge two sorted linked lists and return it as a new sorted list. The new list should be made by splicing together the nodes of the first two lists.
//
//Example 1:
//
//Input: l1 = [1,2,4], l2 = [1,3,4]
//Output: [1,1,2,3,4,4]
//Example 2:
//
//Input: l1 = [], l2 = []
//Output: []
//Example 3:
//
//Input: l1 = [], l2 = [0]
//Output: [0]
//
//
//Constraints:
//
//The number of nodes in both lists is in the range [0, 50].
//-100 <= Node.val <= 100
//Both l1 and l2 are sorted in non-decreasing order.

#include <algorithm>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // edge cases out
        if (!l1) return l2;
        if (!l2) return l1;
        // let's make sure l1's first value is not bigger than l2's
        if (l1->val > l2->val) std::swap(l1, l2);
        // support variables
        ListNode *tmp, *root = l1;
        int val;
        // main loop through l2
        while (l2) {
            val = l2->val;
            while (l1->next && l1->next->val < val) l1 = l1->next;
            // splicing l1 with l2
            tmp = l1->next;
            l1->next = l2;
            l2 = l2->next;
            l1->next->next = tmp;
        }
        return root;
    }
};
