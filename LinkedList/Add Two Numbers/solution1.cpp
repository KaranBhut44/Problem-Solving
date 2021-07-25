#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l3 = new ListNode();
        ListNode *root = l3;
        int flag=0,ans=0;
        while(l1!=nullptr && l2!=nullptr)
        {
            ListNode *l4 = new ListNode();
            l3->next = l4;
            l3 = l4;
            ans = l1->val + l2->val + flag;
            if(ans>=10)
            {
                ans = ans%10;
                flag=1;
            }
            else
                flag=0;
            l3->val = ans;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1!=nullptr)
        {
            ListNode *l4 = new ListNode();
            l3->next = l4;
            l3 = l4;
            ans = l1->val + flag;
            if(ans>=10)
            {
                ans = ans%10;
                flag=1;
            }
            else
                flag=0;
            l3->val = ans;
            l1 = l1->next;
        }
        while(l2!=nullptr)
        {
            ListNode *l4 = new ListNode();
            l3->next = l4;
            l3 = l4;
            ans = l2->val + flag;
            if(ans>=10)
            {
                ans = ans%10;
                flag=1;
            }
            else
                flag=0;
            l3->val = ans;
            l2 = l2->next;
        }
        if(flag==1)
        {
            ListNode *l4 = new ListNode();
            l3->next = l4;
            l3 = l4;
            l3->val = 1;
        }
        return root->next;
    }
};