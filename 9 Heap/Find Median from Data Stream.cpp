#include <bits/stdc++.h>

using namespace std;

class MedianFinder
{
    priority_queue<int> maxpq;                            // Max heap for the lower half
    priority_queue<int, vector<int>, greater<int>> minpq; // Min heap for the upper half

public:
    MedianFinder() {}

    void addNum(int num)
    {
        // Add to max heap if empty or num is less than or equal to max of max heap
        if (maxpq.empty() || maxpq.top() >= num)
            maxpq.push(num);
        else
            minpq.push(num);

        // Balance the heaps: maxpq can have at most one more element than minpq
        if (maxpq.size() > minpq.size() + 1)
        {
            minpq.push(maxpq.top());
            maxpq.pop();
        }
        else if (minpq.size() > maxpq.size())
        {
            maxpq.push(minpq.top());
            minpq.pop();
        }
    }

    double findMedian()
    {
        int count = maxpq.size() + minpq.size();
        // If the total number of elements is odd, the median is the top of maxpq
        if (count % 2 == 1)
        {
            return maxpq.top();
        }
        // If the total number of elements is even, the median is the average of the tops of both heaps
        else
        {
            return (maxpq.top() + minpq.top()) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
