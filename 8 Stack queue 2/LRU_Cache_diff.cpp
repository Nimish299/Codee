
#include <bits/stdc++.h>

using namespace std;

class LRUCache
{
private:
    int cap;
    int curr = 0;
    stack<pair<int, int>> st;

public:
    LRUCache(int capacity)
    {

        cap = capacity;
    }

    int get(int key)
    {
        stack<pair<int, int>> check;
        while (!st.empty() && st.top().first != key)
        {
            pair<int, int> s = st.top();
            check.push(s);
            st.pop();
        }

        if (st.empty())
        {

            while (!check.empty())
            {
                pair<int, int> s = check.top();
                st.push(s);
                check.pop();
            }
            return -1;
        }
        else
        {
            pair<int, int> s = st.top();
            cout << s.first << " " << s.second << endl;
            st.pop();
            while (!check.empty())
            {
                pair<int, int> s = check.top();
                st.push(s);
                check.pop();
            }
            st.push(s);
            return s.second;
        }
    }

    void put(int key, int value)
    {
        cout << "cuur/cap" << curr << "  <<" << cap << endl;

        if (curr < cap)
        {

            st.push({key, value});
            curr++;
        }
        else
        {
            // cout << "here";
            pair<int, int> s = st.top();
            cout << "top " << s.first << " " << s.second << endl;
            st.pop();
            st.push({key, value});
        }
    }
};

int main()
{
    // Create an instance of LRUCache
    LRUCache *obj = new LRUCache(2);

    obj->put(1, 1);
    obj->put(2, 2);

    cout << obj->get(1) << endl; // Output: 1
    // cout << obj->get(2) << endl; // Output: 2

    obj->put(3, 3);

    cout << obj->get(2) << endl; // Output: -1 (Key 2 got evicted)

    // obj->put(4, 4);

    // cout << obj->get(1) << endl; // Output: -1 (Key 1 got evicted)
    // cout << obj->get(3) << endl; // Output: 3
    // cout << obj->get(4) << endl; // Output: 4

    // Free the allocated memory
    delete obj;

    return 0;
}