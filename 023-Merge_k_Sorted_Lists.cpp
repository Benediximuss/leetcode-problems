#include <iostream>
#include <vector>

using namespace std;


struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

void testRun(ListNode* (*fn)(vector<ListNode*>&))
{
    auto createLL = [](int* arr, int size) -> ListNode* {
        ListNode* head = new ListNode(arr[0]);

        ListNode* ptr = head;
        for (int i = 1; i < size; i++)
        {
            ptr->next = new ListNode(arr[i]);
            ptr = ptr->next;
        }

        delete[] arr;

        return head;
    };

    auto printLL = [](ListNode* head) {
        ListNode* ptr = head;
        printf("[ ");
        while (ptr != nullptr)
        {
            printf("%d%c", ptr->val, (ptr->next != nullptr) ? ',' : ' ');
            ptr = ptr->next;
        }
        printf("]");
    };

    auto destroyLL = [](ListNode* head) {
        while (head != nullptr)
        {
            ListNode* temp = head->next;
            delete head;
            head = temp;
        }
    };


    vector<vector<ListNode*>> cases = { {createLL(new int[1] {1}, 1)}, {createLL(new int[3] {1, 4, 5}, 3), createLL(new int[3] {1, 3, 4}, 3), createLL(new int[2] {2, 6}, 2)}, {nullptr}, {nullptr, createLL(new int[1] {1}, 1)}, { createLL(new int[1] {2}, 1), nullptr, createLL(new int[4] {1, 1, 1, 1}, 4), nullptr} };

    for (int i = 0; i < cases.size(); i++)
    {
        printf("Case %d\nInput: Lists = [ ", i + 1);
        
        for (ListNode*& p : cases[i])
        {
            printLL(p);
            printf(" ");
        }

        printf("]\n");

        ListNode* output = fn(cases[i]);

        printf("Output = ");
        printLL(output);
        printf("\n");


        for (ListNode*& p : cases[i])
        {
            destroyLL(p);
        }

        destroyLL(output);
    }

    cout << endl;
}


/* Solution part */

ListNode* mergeKLists(vector<ListNode*>& lists)
{
    vector<ListNode*> ptrs;
    int nulledPtr = 0;

    for (int i = 0; i < lists.size(); i++)
    {
        if (lists[i] == nullptr)
        {
            nulledPtr += 1;
        }
        else
        {
            ptrs.push_back(lists[i]);
        }
    }

    ListNode* head = new ListNode(-1);
    ListNode* ptr2 = head;

    while (nulledPtr < lists.size())
    {
        int min = INT_MAX;
        int minPtr;
        for (int i = 0; i < ptrs.size(); i++)
        {
            if (ptrs[i]->val < min)
            {
                min = ptrs[i]->val;
                minPtr = i;
            }
        }

        ptr2->next = new ListNode(ptrs[minPtr]->val);
        ptr2 = ptr2->next;

        ptrs[minPtr] = ptrs[minPtr]->next;

        if (ptrs[minPtr] == nullptr)
        {
            ptrs[minPtr] = ptrs.back();
            ptrs.pop_back();
            nulledPtr++;
        }
    }

    ptr2 = head;
    head = head->next;
    delete ptr2;

    return head;
}

int main()
{
    testRun(mergeKLists);

    return 0;
}
