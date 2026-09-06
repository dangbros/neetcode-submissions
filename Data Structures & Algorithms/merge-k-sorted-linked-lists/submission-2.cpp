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

// naive solution
class Solution {
public:
    ListNode* merge2(ListNode* head1, ListNode* head2){
        ListNode* t1 = head1;
        ListNode* t2 = head2;
        ListNode* dNode = new ListNode(-1);
        ListNode* temp = dNode;
        while(t1 != NULL && t2 != NULL){
            if(t1->val < t2->val){
                temp->next = t1;
                temp = t1;
                t1 = t1->next;
            }
            else{
                temp->next = t2;
                temp = t2;
                t2 = t2->next;
            }
        }

        if(t1) temp->next = t1;
        else temp->next = t2;
        
        return dNode->next;
    }


    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();

        if (lists.empty())
            return nullptr;
        
        int interval = 1;
        
        while(interval < n){
            for(int i = 0; i + interval < n; i += interval*2){
                lists[i] = merge2(lists[i], lists[i+interval]);
            }

            interval *= 2;
        }
            
        return lists[0];
    }
};
