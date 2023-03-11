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
private:
    ListNode* ListHead=nullptr; 
    int NodeSize=0;

public:
    
    Solution(ListNode* head) {
        ListHead=head;
        ListNode* tmp=head;
        while(tmp != nullptr)
        {
            NodeSize++;
            tmp=tmp->next; 
        }
    }
    
    int getRandom() {

        int RandomNode = rand() % NodeSize;
        int counter=0;
        ListNode* tmp=ListHead; 
       
       while (tmp != nullptr)
       {
           if (counter == RandomNode)
           {
               return tmp->val;
           }
           counter++;
           tmp = tmp->next; 
       }
       return -1; 
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */