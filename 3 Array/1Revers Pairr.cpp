#include <bits/stdc++.h>

using namespace std;

class Solution
{

public:
    void merge(vector<int> &array, int left, int mid, int right)
    {
        int const subArrayOne = mid - left + 1;
        int const subArrayTwo = right - mid;

        // Create temp arrays
        vector<int> leftArray(subArrayOne);
        vector<int> rightArray(subArrayTwo);

        // Copy data to temp arrays leftArray[] and rightArray[]
        for (int i = 0; i < subArrayOne; i++)
            leftArray[i] = array[left + i];
        for (int j = 0; j < subArrayTwo; j++)
            rightArray[j] = array[mid + 1 + j];

        int indexOfSubArrayOne = 0;
        int indexOfSubArrayTwo = 0;
        int indexOfMergedArray = left;

        // Merge the temp arrays back into array[left..right]
        while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo)
        {
            if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo])
            {
                array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
                indexOfSubArrayOne++;
            }
            else
            {
                array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
                indexOfSubArrayTwo++;
            }
            indexOfMergedArray++;
        }

        // Copy the remaining elements of leftArray[], if there are any
        while (indexOfSubArrayOne < subArrayOne)
        {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
            indexOfMergedArray++;
        }

        // Copy the remaining elements of rightArray[], if there are any
        while (indexOfSubArrayTwo < subArrayTwo)
        {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
            indexOfMergedArray++;
        }
    }
    int count(vector<int> &array, int begin, int end, int mid)
    {
        int r = mid + 1;
        int c = 0;
        for (int i = begin; i <= mid; i++)
        {
            while (r <= end && array[i] > 2 * array[r])
                r++;
            c += r - mid - 1;
        }
        return c;
    }
    int mergeSort(vector<int> &array, int begin, int end)
    {
        int c = 0;
        if (begin >= end)
            return c;

        int mid = begin + (end - begin) / 2;
        c += mergeSort(array, begin, mid);
        c += mergeSort(array, mid + 1, end);
        c += count(array, begin, end, mid);
        merge(array, begin, mid, end);
        return c;
    }

    int reversePairs(vector<int> &nums)
    {
        mergeSort(nums, 0, nums.size() - 1);
    }
};

/*
class Solution {
private:
    void merge(vector<int>& nums, int low, int mid, int high, int& reversePairsCount){
        int j = mid+1;
        for(int i=low; i<=mid; i++){
            while(j<=high && nums[i] > 2*(long long)nums[j]){
                j++;
            }
            reversePairsCount += j-(mid+1);
        }
        int size = high-low+1;
        vector<int> temp(size, 0);
        int left = low, right = mid+1, k=0;
        while(left<=mid && right<=high){
            if(nums[left] < nums[right]){
                temp[k++] = nums[left++];
            }
            else{
                temp[k++] = nums[right++];
            }
        }
        while(left<=mid){
            temp[k++] = nums[left++];
        }
        while(right<=high){
            temp[k++] = nums[right++];
        }
        int m=0;
        for(int i=low; i<=high; i++){
            nums[i] = temp[m++];
        }
    }

    void mergeSort(vector<int>& nums, int low, int high, int& reversePairsCount){
        if(low >= high){
            return;
        }
        int mid = (low + high) >> 1;
        mergeSort(nums, low, mid, reversePairsCount);
        mergeSort(nums, mid+1, high, reversePairsCount);
        merge(nums, low, mid, high, reversePairsCount);
    }
public:
    int reversePairs(vector<int>& nums) {
        int reversePairsCount = 0;
        mergeSort(nums, 0, nums.size()-1, reversePairsCount);
        return reversePairsCount;
    }
};
*/