/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    void sortingList(ListNode** head)
    {
        ListNode* curr = *head;
        ListNode* firsthalf;
        ListNode* secondhalf;

        if(curr == NULL or curr->next == NULL)
        {
            return;
        }

        find_the_middle_node(curr,&firsthalf,&secondhalf);


        sortingList(&firsthalf);
        sortingList(&secondhalf);

        *head = join(firsthalf,secondhalf);
        
    }

    void find_the_middle_node(ListNode* curr, ListNode** firsthalf,ListNode** secondhalf)
    {
        ListNode* slow = curr;
        ListNode* fast = curr->next;

        while(fast!=NULL)
        {
            fast=fast->next;
            if(fast!=NULL)
            {
                fast=fast->next;
                slow=slow->next;
            }
        }

        *firsthalf = curr;
        *secondhalf = slow->next;
        slow->next = NULL;
    }

    ListNode* join(ListNode* firsthalf, ListNode* secondhalf)
{
    ListNode* answer = nullptr;

    if (firsthalf == NULL)
        return secondhalf;

    if (secondhalf == NULL)
        return firsthalf;

    if (firsthalf->val <= secondhalf->val) {
        answer = firsthalf;
        answer->next = join(firsthalf->next, secondhalf);
    } else {
        // Change from firsthalf to secondhalf in the else block
        answer = secondhalf;
        answer->next = join(firsthalf, secondhalf->next);
    }

    return answer;
}

    ListNode* sortList(ListNode* head) {

      sortingList(&head);
     return head;
    
    }
};
