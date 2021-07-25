class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *temp=head;
        int count=0;
        while(temp!=nullptr)
        {
            count++;
            temp=temp->next;
        }
        temp=head;
        int res;
        if(count%2==0)
        {
            res=count/2;
        }
        else
        {
            res=count/2;
        }
        count=0;
        while(true)
        {
            if(count==res)
                return temp;
            count++;
            temp=temp->next;
        }
    }
};