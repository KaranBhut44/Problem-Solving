class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ptr1 = headA,*ptr2 = headB;
        unordered_map<ListNode*,int>m;
        while(ptr1!=nullptr)
        {
            m[ptr1]++;
            ptr1 = ptr1->next;
        }
        while(ptr2!=nullptr)
        {
            if(m[ptr2]!=0)
                return ptr2;
            ptr2 = ptr2->next;
        }
        return nullptr;
    }
};