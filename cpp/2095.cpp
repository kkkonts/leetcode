/*
You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.

The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start using 0-based indexing, where ⌊x⌋ denotes the largest integer less than or equal to x.

For n = 1, 2, 3, 4, and 5, the middle nodes are 0, 1, 1, 2, and 2, respectively.
*/


struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 

class PrefectSolution {
    ListNode* deleteMiddle(ListNode* head) {
    if (head->next == nullptr)
        return nullptr;
    auto slow = head, fast = head->next->next;
    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    return head;
    }
};

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        int n = 1, i = 0, ind;
        ListNode *cur = head, *mid = head;
        
        while (cur->next != nullptr){
            ++n;
            cur = cur->next;
        }
        
        ind = n / 2;
        
        while (i != ind){
            ++i;
            mid = mid->next;
        }
        
        if (n == 2){
            head->next = nullptr;
        }
        else if (n == 1) {
            delete head;
            return nullptr;
        }
        else {
            mid->val = mid->next->val;
            mid->next = mid->next->next;
        }
        
        return head;
    }
};