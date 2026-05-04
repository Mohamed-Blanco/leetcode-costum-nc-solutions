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
        
        ListNode* current = head ; 
        ListNode* dummy = new ListNode(0,head);  

        std::map<ListNode*,bool> nodes {};  
        while(current != nullptr )
        {
            if(!nodes[current])
            {
                nodes[current] = true ; 
            }else
            {
                return true ; 
            }
            current = current->next ; 
        }

        return false ; 

    }
};