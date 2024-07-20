
#include <bits/stdc++.h>

using namespace std;
class RandomizedSet
{
private:
    unordered_map<int, int> mp; // Maps value to its index in vector v
    vector<int> v;              // Stores values

public:
    RandomizedSet()
    {
        // Constructor initializes the empty set
    }

    bool insert(int val)
    {
        if (mp.find(val) != mp.end())
        {
            return false; // Value already exists
        }

        v.push_back(val);       // Add value to the end of the vector
        mp[val] = v.size() - 1; // Update index in the map
        return true;
    }

    bool remove(int val)
    {
        if (mp.find(val) == mp.end())
        {
            return false; // Value does not exist
        }

        int last_val = v.back(); // Get the last value in the vector
        int idx = mp[val];       // Get the index of the value to remove

        v[idx] = last_val;  // Move last value to the position of val
        mp[last_val] = idx; // Update index of last_val in the map

        v.pop_back();  // Remove the last element from the vector
        mp.erase(val); // Remove val from the map

        return true;
    }

    int getRandom()
    {
        int random_index = rand() % v.size();
        return v[random_index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */