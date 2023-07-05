/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*, int> mp;
        ListNode* ptrA= headA;
        while(ptrA!=NULL){
            mp[ptrA]++;
            ptrA= ptrA->next;
        }
        
        ListNode* ptrB= headB;
        while(ptrB!=NULL){
            if(mp.find(ptrB)!=mp.end()){
                return ptrB;
            }
            ptrB= ptrB->next;
        }
        return NULL;
    }
};