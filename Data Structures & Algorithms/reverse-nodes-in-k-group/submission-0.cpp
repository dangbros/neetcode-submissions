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
    ListNode* getKth(ListNode* curr, int k){
        while(curr && k > 0){
            curr = curr->next;
            k--;
        }

        return curr;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dNode = new ListNode(0, head);
        ListNode* groupPrev = dNode;

        while(true){
            ListNode* kth = getKth(groupPrev, k);
            if(!kth) break;
            ListNode* groupNext = kth->next;

            // reversing the group
            ListNode* prev = kth->next;
            ListNode* curr = groupPrev->next;
            ListNode* tmp;
            while(curr != groupNext){
                tmp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = tmp;
            }

            tmp = groupPrev->next;
            groupPrev->next = kth;
            groupPrev = tmp;
        }

        return dNode->next;
    }


};
