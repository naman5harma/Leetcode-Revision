/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        

        int l1=0;
        int l2=0;

        ListNode* temp1=headA;
        ListNode* temp2=headB;

        while(temp1!=NULL)
        {
            temp1=temp1->next;
            l1++;
        }
        while(temp2!=NULL)
        {
            temp2=temp2->next;
            l2++;
        }
        temp1=headA;
        temp2=headB;
    
        if (l1 > l2) {
            int diff = l1 - l2;
            while (diff > 0) {
                temp1 = temp1->next;
                diff--;
            }
        } else {
            int diff = l2 - l1;
            while (diff > 0) {
                temp2 = temp2->next;
                diff--;
            }
        }

        while (temp1 != temp2) {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return temp1;
        


    }
};
