
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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || !head->next || k == 0)
            return head;
        ListNode *dummy = head;
        int c = 1;
        while (dummy->next != NULL)
        {
            c++;
            dummy = dummy->next;
        }
        dummy->next = head;

        k = k % c;
        if (k == 0)
        {
            dummy->next = NULL; // Break the circular list
            return head;
        }
        int rotate = c - k;
        while (rotate--)
        {
            dummy = dummy->next;
        }
        head = dummy->next;
        dummy->next = NULL;
        return head;
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
