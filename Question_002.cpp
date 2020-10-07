//
// Created by tzur on 8/7/2020.
//

//You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
//
//You may assume the two numbers do not contain any leading zero, except the number 0 itself.
//
//Example:
//
//Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
//Output: 7 -> 0 -> 8
//Explanation: 342 + 465 = 807
#include <vector>
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //process two of the lists
        vector<int> arr;
        int v1,v2,v3,v4,carry = 0;
        while(l1 && l2)
        {
            v1 = l1->val;
            v2 = l2->val;
            v3 = v1 + v2 + carry;
            v4 = v3%10;
            arr.push_back(v4);
            carry = v3/10;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1)
        {
            v1 = l1->val;
            v3 = v1 + carry;
            arr.push_back(v3%10);
            carry = v3/10;
            l1 = l1->next;
        }
        while(l2)
        {
            v2 = l2->val;
            v3 = v2 + carry;
            arr.push_back(v3%10);
            carry = v3/10;
            l2 = l2->next;
        }
        if(carry)
        {
            arr.push_back(carry);
        }

        ListNode* ret = new ListNode(arr[0]);
        auto tmp = ret;
        for(int i = 1 ; i < arr.size() ; i++)
        {
            tmp->next = new ListNode(arr[i]);
            tmp = tmp->next;
        }
        return ret;
    }


};