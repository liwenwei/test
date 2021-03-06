#include <vector>

using namespace std;

#ifdef isBadVersion

// Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.
// You are given an API bool isBadVersion(version) which will return whether version is bad. 
// Implement a function to find the first bad version
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

// binary search
int binarySearch(int n)
{
    int start = 1, end = n;
    while (start < end)
    {
        int mid = start + (end - start) / 2;
        if (isBadVersion(mid)) end = mid;
        else start = mid + 1;
    }
    return start;
}

#endif

// Given a sorted array and a target value, return the index if the target is found.If not, 
// return the index where it would be if it were inserted in order.
int searchInsert(vector<int>& nums, int target)
{
    int low = 0;
    int high = nums.size();

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] < target) low = mid + 1;
        else high = mid - 1;
    }

    return low;
}

int lower_bound(vector<int>& nums, int target)
{
    int low = 0;
    int high = nums.size();

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] <= target) low = mid + 1;
        else high = mid - 1;
    }
    return low;
}

/*
*
* Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.
*
* If the target is not found in the array, return [-1, -1].
*
* For example,
* Given [5, 7, 7, 8, 8, 10] and target value 8,
* return [3, 4]
*
*/
vector<int> searchRange(vector<int>& nums, int target)
{
    int begin = lower_bound(nums, target);
    int end = lower_bound(nums, target + 1) - 1;
    if (begin < nums.size() && nums[begin] == target)
        return { begin, end };
    else
        return { -1, -1 };
}