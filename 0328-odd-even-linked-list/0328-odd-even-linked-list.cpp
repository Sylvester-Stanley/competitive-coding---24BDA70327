class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;

        while (even != nullptr && even->next != nullptr) {
            // Connect current odd node to next odd node
            odd->next = even->next;
            odd = odd->next;

            // Connect current even node to next even node
            even->next = odd->next;
            even = even->next;
        }

        // Attach the even list after the odd list
        odd->next = evenHead;

        return head;
    }
};