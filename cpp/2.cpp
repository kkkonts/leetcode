/*
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order, and each of their nodes contains a single digit. 
Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

*/
#include <iostream>
#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;
using std::cin;
using std::cout;


struct ListNode {
     int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
    int toInt(ListNode *node) {
        int num = 0;
        while (node != nullptr) {
            num *= 10;
            num += node->val;
            node = node->next;
        }
        return num;
    }

    ListNode *toList(int num) {
        ListNode *last = new ListNode;
        ListNode *cur;
        last->val = num % 10;
        last->next = nullptr;
        num /= 10;
        
        while (num > 0) {
            cur = new ListNode;
            cur->val = num % 10;
            cur->next = last;
            last = cur;
            num /= 10;
        }
        return cur;
    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int num1 = toInt(l1), num2 = toInt(l2);
        return toList(num1 + num2);
    }
};

int main() {
    
    return 0;
}



