/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <map>

class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        ListNode* slow = head;
        ListNode* fast = head ; 

        if(head != nullptr && head->next != nullptr && fast->next != nullptr && fast->next->next != nullptr)
        {
            fast = fast->next->next;   
        }else
        {
            return false ; 
        }

        
        while(fast->next != nullptr && fast->next->next != nullptr)
        {
            if(fast == slow)
            {
                return true ; 
            }

            fast = fast->next->next; 
            slow = slow->next;
        }

        return false ; 

    }
};