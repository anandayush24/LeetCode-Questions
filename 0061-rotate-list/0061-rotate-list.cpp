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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0){
            return head;
        }
        int length= 1;
        ListNode* ptr= head;
        while(ptr->next!=NULL){
            length++;
            ptr= ptr->next;
        }
        ptr->next= head;
        k= k % length;
        int diff= length-k;
        
        while(diff--){
            ptr= ptr->next;
        }
        
        head= ptr->next;
        ptr->next= NULL;
        
        return head;
    }
};