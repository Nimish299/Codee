
#include <bits/stdc++.h>

using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        //      ListNode *check1=list1;
        //     ListNode *check2=list2;
        ListNode head;
        ListNode *sort = &head;

        while (list1->next != NULL && list2->next != NULL)
        {
            if (list1->val <= list2->val)
            {
                sort->next = list1;
                list1 = list1->next;
            }
            else
            {
                sort->next = list2;
                list2 = list2->next;
            }
            sort = sort->next;
        }
        while (list1->next != NULL)
        {
            sort->next = list1;
            list1 = list1->next;
        }
        while (list2->next != NULL)
        {
            sort->next = list2;
            list2 = list2->next;
        }
        return head.next;
    }
};
int main()
{

    cout << "cc" << endl;
    int a, v;
    cin >> a;
    cin >> v;
    int c;
    cin >> c;
    if (c == 1)
        cout << a + v;
    else
        cout << a - v;
}
