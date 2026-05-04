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

        std::unordered_set<ListNode*> nodes {};  
        while(current != nullptr )
        {
            if(nodes.find(current) == nodes.end())
            {
                nodes.insert(current); 
            }else
            {
                return true ; 
            }
            current = current->next ; 
        }

        return false ; 

    }
};