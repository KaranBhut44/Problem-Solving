class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head,*fast = head;
        while(fast!=nullptr && fast->next!=nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};