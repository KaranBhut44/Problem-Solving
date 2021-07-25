class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ptr1 = headA;
        ListNode *ptr2 = headB;
        int var = 3;
        while(var--)
        {
            while(ptr1!=nullptr && ptr2!=nullptr)
            {
                if(ptr1==ptr2)
                {
                    return ptr1;
                }
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }
            if(ptr1==nullptr)
                ptr1 = headB;
            else if(ptr2==nullptr)
                ptr2 = headA;
        }
        return nullptr;
    }
};