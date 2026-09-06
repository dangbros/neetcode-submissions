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

// optimal solution
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
                t1 = t1->next;
            }
            else{
                temp->next = t2;
                t2 = t2->next;
            }
            temp = temp->next;
        }

        if(t1) temp->next = t1;
        else temp->next = t2;

        return dNode->next;
    }


    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;

        while(lists.size() > 1){
            vector<ListNode*> mergedLists;
            for(int i = 0; i < lists.size(); i += 2) {
                ListNode* l1 = lists[i];
                ListNode* l2 = (i + 1) < lists.size() ? lists[i+1]: nullptr;
                mergedLists.push_back(merge2(l1,l2));
            }
            lists = mergedLists;
        }
       
        return lists[0];
    }
};
