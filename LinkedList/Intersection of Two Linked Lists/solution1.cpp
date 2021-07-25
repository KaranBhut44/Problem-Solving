class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ptr1 = headA,*ptr2 = headB;
        if(ptr1 == ptr2)
            return ptr1;
        while(ptr1!=nullptr)
        {
            while(ptr2!=nullptr)
            {
                if(ptr1==ptr2)
                {
                    return ptr1;
                }
                ptr2 = ptr2->next;
            }
            ptr2 = headB;
            ptr1 = ptr1->next;
        }
        return nullptr;
    }
};