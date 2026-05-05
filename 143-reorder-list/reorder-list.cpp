class Solution {
public:
    void reorderList(ListNode* head) {

        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }

        // Reverse second half
        ListNode* current = slow->next;
        slow->next = nullptr;        // ← FIX 1: sever the two halves
        ListNode* prev = nullptr;
        while (current != nullptr) {
            ListNode* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        // Merge                      // ← FIX 2: clean merge
        ListNode* p1 = head;
        ListNode* p2 = prev;
        while (p2 != nullptr) {
            ListNode* next1 = p1->next;
            ListNode* next2 = p2->next;
            p1->next = p2;
            p2->next = next1;
            p1 = next1;
            p2 = next2;
        }
    }
};