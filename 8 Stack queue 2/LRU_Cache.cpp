
#include <bits/stdc++.h>

using namespace std;

class LRUCache
{
private:
    int cap;
    int curr = 0;
    queue<int> qu;
    map<int, int> mp;

public:
    LRUCache(int capacity)
    {

        cap = capacity;
    }

    int get(int key)
    {
        int len = qu.size();
        int f = 0;
        int t;
        while (len--)
        {
            if (qu.front() == key)
            {
                f = 1;
                t = qu.front();
                qu.pop();
            }
            else
            {
                int s = qu.front();
                qu.pop();
                qu.push(s);
            }
        }
        if (f == 1)
        {
            qu.push(t);
            return mp[t];
        }
        else
            return -1;
    }

    void put(int key, int value)
    {
        if (mp.find(key) != mp.end())
        {
            int l = get(key);
            mp[key] = value; // Correct assignment
        }
        else
        {
            // cout << "cuur/cap" << curr << "  <<" << cap << " " << key << " " << value << endl;
            if (curr < cap)
            {

                qu.push(key);
                mp[key] = value;

                curr++;
            }
            else
            {

                int frontKey = qu.front();
                cout << frontKey << "key" << endl;
                qu.pop();
                mp.erase(frontKey); // Remove the least recently used key from the map
                qu.push(key);
                mp[key] = value;
            }
        }
    }
};

int main()
{
    LRUCache *obj = new LRUCache(2);

    // Perform operations as per the given sequence
    obj->put(2, 1);
    obj->put(1, 1);
    obj->put(2, 3);
    obj->put(4, 1);

    cout << obj->get(1) << endl; // Output: -1 (Key 1 not found)
    cout << obj->get(2) << endl; // Output: 3

    // Free the allocated memory
    delete obj;
    return 0;
}