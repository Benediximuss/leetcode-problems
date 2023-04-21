class Solution {
public:

    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* fast = head;        
        bool isFirst = false;

        for (int i = 0; i < n + 1 && !isFirst; i++)
        {
            fast = fast->next;
            if (fast == nullptr && i < n)
            {
                isFirst = true;
            }
        }

        if (!isFirst)
        {
            ListNode* slow = head;
            while(fast != nullptr)
            {
                fast = fast->next;
                slow = slow->next;
            }

            ListNode* temp = slow->next;
            slow->next = temp->next;
            delete temp;
        }
        else
        {
            ListNode* temp = head;
            head = temp->next;
            delete temp;
        }

        return head;
    }
};