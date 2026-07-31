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

class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return;
        
        // find the mid point
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* midpoint = slow->next;
        slow->next = nullptr;

        // reverse the second half
        ListNode* prev = nullptr;
        ListNode* curr = midpoint;
        ListNode* front = nullptr;
        while(curr){
            front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }

        ListNode* newMid = prev;

        // join them according to the reorder
        ListNode* p1 = head;
        ListNode* p2 = newMid;

        while(p2){
            front = p1->next;
            prev = p2->next;

            p1->next = p2;
            p2->next = front;
            p1 = front;
            p2 = prev;
        }
    }
};
