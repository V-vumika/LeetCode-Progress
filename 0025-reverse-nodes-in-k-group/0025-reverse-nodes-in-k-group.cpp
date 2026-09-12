class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
       
        ListNode* node = head;
        int count = 0;
        while (node != nullptr && count < k) {
            node = node->next;
            count++;
        }
        
        if (count < k) return head; 
        ListNode* prev = reverseKGroup(node, k); 
        ListNode* current = head;
        
        for (int i = 0; i < k; i++) {
            ListNode* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        
        return prev;
    }
};