
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
class Solution
{

public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (head == nullptr || k == 1)
            return head;

        // Initialize a dummy node
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        // Initialize pointers
        ListNode *cur = dummy, *nex = dummy, *pre = dummy;
        int count = 0;

        // Count the number of nodes in the list
        while (cur->next != nullptr)
        {
            count++;
            cur = cur->next;
        }

        // Loop until there are no more nodes to reverse in groups of k
        while (count >= k)
        {
            cur = pre->next;
            nex = cur->next;

            // Reverse k nodes
            for (int i = 1; i < k; i++)
            {
                cur->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = cur->next;
            }

            // Move pre to the end of the reversed section
            pre = cur;
            count -= k;
        }

        // Return the new head of the reversed list
        return dummy->next;
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
