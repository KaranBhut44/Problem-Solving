class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head,*fast = head;
        if(head==nullptr || head->next==nullptr)
            return true;
        while(fast->next!=nullptr && fast->next->next!=nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *temp1= slow->next;
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
        slow->next = back;
        while(back!=nullptr)
        {
            if(head->val != back->val)
            {
                return false;
            }
            head = head->next;
            back = back->next;
        }
        return true;
        
    }
};