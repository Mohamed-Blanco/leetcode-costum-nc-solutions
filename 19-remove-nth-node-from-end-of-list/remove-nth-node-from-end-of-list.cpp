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
        
        
        if(!head) return nullptr; 

        ListNode* dummy = new ListNode(0,head); 
        ListNode* current1 = dummy; 
        ListNode* current2 = dummy; 

        int i = 0;         
        //create gap between both of them of size N 
        while(current2->next != nullptr && i < n)
        {
            current2 = current2->next;
            ++i; 
        }

        if(current2->next == nullptr) return head->next; 
        while(current2->next != nullptr )
        {
            current1 = current1->next;
            current2 = current2->next; 
        }
        
        current1->next = current1->next->next;    
        return dummy->next ; 

    }
};