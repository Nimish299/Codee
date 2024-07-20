
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *Newhead = new ListNode();
        Newhead->next = head;
        ListNode *slow = Newhead;
        ListNode *fast = Newhead;

        while (n--)
        {
            fast = fast->next;
        }
        while (fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return Newhead->next;
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
