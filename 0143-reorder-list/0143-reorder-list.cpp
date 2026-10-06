class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return;
        
        // ধাপ ১: slow-fast pointer দিয়ে মাঝের নোড খুঁজে বের করা
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* secondHalf = reverse(slow->next);
        slow->next = nullptr; 
        
        ListNode* firstHalf = head;
        
        while (secondHalf != nullptr) {
            ListNode* temp1 = firstHalf->next;
            ListNode* temp2 = secondHalf->next;
            
            firstHalf->next = secondHalf;
            secondHalf->next = temp1;
            
            firstHalf = temp1;
            secondHalf = temp2;
        }
    }
    
private:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;
        
        while (current != nullptr) {
            ListNode* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        
        return prev;
    }
};