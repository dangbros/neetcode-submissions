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
    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode* dNode = new ListNode(-1);
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        ListNode* temp = dNode;

        while(t1 != NULL && t2 != NULL) {
            if(t1->val < t2-> val){
                temp->next = t1;
                t1 = t1->next;
            }
            else{
                temp->next = t2;
                t2 = t2->next;
            }
            temp = temp->next;
        }

        if (t1) temp->next = t1;
        else temp->next = t2;

        return dNode->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;

        while(lists.size() > 1){
            vector<ListNode*> mergedList;
            for(int i = 0; i < lists.size(); i+=2){
                ListNode* l1 = lists[i];
                ListNode* l2;

                if (lists.size() > (i + 1)) l2 = lists[i+1];
                else l2 = nullptr;

                mergedList.push_back(merge(l1, l2));
            }

            lists = mergedList;
        }

        return lists[0];
    }
};
