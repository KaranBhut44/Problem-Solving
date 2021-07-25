class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* ptr1 = l1, *ptr2 = l2;
        ListNode* head;
        if(ptr1!=nullptr && ptr2!=nullptr)
        {
            if(ptr1->val <= ptr2->val)
            {
                head = ptr1;
                ptr1 = ptr1->next;
            }
            else
            {
                head = ptr2;
                ptr2 = ptr2->next;
            }
        }
        else if(ptr1!=nullptr)
            return ptr1;
        else if(ptr2!=nullptr)
            return ptr2;
        
        ListNode* temp = head;
        while(ptr1!=nullptr && ptr2!=nullptr)
        {
            if(ptr1->val <= ptr2->val)
            {
                temp->next = ptr1;
                temp = temp->next;
                ptr1 = ptr1->next;
            }
            else
            {
                temp->next = ptr2;
                temp = temp->next;
                ptr2 = ptr2->next;
            }
            
        }
        while(ptr1!=nullptr)
        {
            temp->next = ptr1;
            temp = temp->next;
            ptr1 = ptr1->next;
        }
        while(ptr2!=nullptr)
        {
            temp->next = ptr2;
            temp = temp->next;
            ptr2 = ptr2->next;
        }
        return head;
        
    }
};