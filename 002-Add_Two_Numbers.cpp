#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

void testRun(ListNode*(*fn)(ListNode*, ListNode*))
{
    auto creatLL = [](int* arr, int size) -> ListNode* {
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
        while (ptr != nullptr)
        {
            printf("%d%s", ptr->val, (ptr->next != nullptr) ? " -> " : "");
            ptr = ptr->next;
        }
    };

    auto destroyLL = [](ListNode* head) {
        while (head != nullptr)
        {
            ListNode* temp = head->next;
            delete head;
            head = temp;
        }
    };

    struct testCase
    {
        ListNode* list1Head;
        ListNode* list2Head;
    };

    testCase cases[] = { {creatLL(new int[3] {2, 4, 3}, 3), creatLL(new int[3] {5, 6, 4}, 3)}, {creatLL(new int[1] {0}, 1), creatLL(new int[1] {0}, 1)}, {creatLL(new int[7] {9, 9, 9, 9, 9, 9, 9}, 7), creatLL(new int[4] {9, 9, 9, 9}, 4)}, {creatLL(new int[4] {1, 2, 5, 9}, 4), creatLL(new int[3] {4, 2, 6}, 3)} };

	for (int i = 0; i < sizeof(cases) / sizeof(testCase); i++)
	{
        printf("Case %d\nInput: List1 = \'", i + 1);
        printLL(cases[i].list1Head);
        printf("\', List2 = \'");
        printLL(cases[i].list2Head);
        printf("\'\n");

		ListNode* output = fn(cases[i].list1Head, cases[i].list2Head);

        printf("Output = \'");
        printLL(output);
        printf("\'\n\n");

        destroyLL(cases[i].list1Head);
        destroyLL(cases[i].list2Head);
        destroyLL(output);
	}

    cout << endl;
}

/* Solution part */

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    ListNode* head = new ListNode(-1);

    ListNode* ptr1 = l1;
    ListNode* ptr2 = l2;
    ListNode* ptr3 = head;
    int carry = 0;
    while (ptr1 != nullptr || ptr2 != nullptr || carry == 1)
    {
        int sum = carry;

        if (ptr1 != nullptr)
        {
            sum += ptr1->val;
            ptr1 = ptr1->next;
        }

        if (ptr2 != nullptr)
        {
            sum += ptr2->val;
            ptr2 = ptr2->next;
        }

        carry = sum >= 10 ? 1 : 0;

        if (ptr3->val != -1)
        {
            ptr3->next = new ListNode(sum % 10);
            ptr3 = ptr3->next;
        }
        else
        {
            ptr3->val = sum % 10;
        }
    }

    return head;
}

int main()
{
    testRun(addTwoNumbers);

	return 0;
}