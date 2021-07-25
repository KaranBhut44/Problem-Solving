class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ptr1 = headA,*ptr2 = headB;
        int count1 =0, count2=0;
        while(ptr1!=nullptr && ptr2!=nullptr)
        {
            count1++;
            count2++;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        while(ptr1!=nullptr)
        {
            count1++;
            ptr1 = ptr1->next;
        }
        while(ptr2!=nullptr)
        {
            count2++;
            ptr2 = ptr2->next;
        }
        ptr1 = headA;
        ptr2 = headB;
        if(count1<=count2)
        {
            int diff = count2 - count1;
            while(diff--)
            {
                ptr2 = ptr2->next;
            }   
        }
        else
        {
            int diff = count1 - count2;
            while(diff--)
            {
                ptr1 = ptr1->next;
            }
        }
        while(ptr1!=nullptr && ptr2!=nullptr)
        {
            if(ptr1==ptr2)
                return ptr1;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        return nullptr;
    }
};