
#include <bits/stdc++.h>

using namespace std;
void sortedstack(stack<int> &stack, int num)
{
    if (stack.empty())
    {
        stack.push(num);
        return;
    }
    if (!stack.empty() && stack.top() < num)
    {
        stack.push(num);
        return;
    }
    int n = stack.top();
    stack.pop();
    sortedstack(stack, num);
    stack.push(n);
}
void sortStack(stack<int> &stack)
{
    if (stack.empty())
        return;
    int s = stack.top();
    stack.pop();
    sortStack(stack);

    sortedstack(stack, s);
}
int main()
{

    cout << "cc" << endl;
}
