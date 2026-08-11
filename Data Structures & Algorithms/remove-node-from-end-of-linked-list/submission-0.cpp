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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL) return head;

        int count = 0;
        ListNode* temp = head;

        // count the size of the list
        while(temp){
            temp = temp->next;
            count++;
        }

        // if we have to remove the head
        if(count == n) {
            ListNode* delNode = head;
            head = head->next;
            delete delNode;
            return head;
        }

        int nthNode = count - n - 1;
        temp = head;

        for(int i = 0; i < nthNode; i++) {
            temp = temp->next;
        }

        ListNode* delNode = temp->next;
        temp->next = temp->next->next;
        delete delNode;

        return head;
    }
};
