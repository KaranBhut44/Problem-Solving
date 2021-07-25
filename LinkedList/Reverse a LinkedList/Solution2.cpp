class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr || head->next==nullptr)
            return head;
        ListNode *temp1= head;
        ListNode *temp2 = temp1->next;
        ListNode *back = temp1;
        temp1->next = nullptr;
        while(temp2!=nullptr)
        {
            temp1 = temp2->next;
            temp2->next = back;
            back = temp2;
            temp2 = temp1;
        }
        head = back;
        return head;
    }
};