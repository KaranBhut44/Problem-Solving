class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *temp = head;
        int count = 0;
        while(temp!=nullptr)
        {
            count++;
            temp = temp->next;
        }
        int index = count - n;
        if(index==0)
        {
            head = head ->next;
            return head;
        }
        temp = head;
        if(head->next == nullptr && n==1)
            return nullptr;
        int counter = 1;
        while(counter!=index)
        {
            temp = temp->next;
            counter++;
        }
        
        temp->next = temp->next->next;
        return head;
    }
};