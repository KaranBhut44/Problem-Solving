class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *ptr1 = head , *ptr2 = head;
        while(ptr1!=nullptr && ptr2!=nullptr)
        {
            ptr1 = ptr1 ->next ;
            if(ptr2->next!=nullptr)
                ptr2 = ptr2 ->next ->next;
            else
                return false;
            if(ptr1==ptr2)
            {
                return true;
            }
        }
        return false;
    }
};