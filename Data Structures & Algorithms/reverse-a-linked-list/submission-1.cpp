/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


// this is the recursive solution
class Solution {
public:
    ListNode* reverse(ListNode* prev, ListNode* curr){
        if (curr == nullptr)
            return prev;
            
        ListNode* temp = curr->next;
        curr->next = prev;
        return reverse(curr, temp);
    }
    ListNode* reverseList(ListNode* head) {
        
        return reverse(NULL, head);
    }
};
