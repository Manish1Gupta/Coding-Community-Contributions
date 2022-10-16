// Header
#include <iostream>
using namespace std;

// Firstly we find the pivot element in an array 
int getPivot(int arr[], int n)
{
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;

    while (s < e)
    {
        if (arr[mid] >= arr[0])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
        mid = s + (e - s) / 2;
    }
    return s;
}

// Now we apply Binary search to search the target element 
int binarySearch(int arr[], int s, int e, int key)
{
    int start = s;
    int end = e;
    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        if (arr[mid] == key)
        {
            return mid;
        }
        if (key > arr[mid])
        {
            start = mid + 1;
        }
        if (key < arr[mid])
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return -1;
}

// Lastly we find the position of target element 
int findPosition(int arr[], int n, int k)
{

    int pivot = getPivot(arr, 5);

    if (k >= arr[pivot] && k <= arr[n - 1])
    {
        // BS on second line
        return binarySearch(arr, pivot, n - 1, k);
    }
    else
    {
        // BS on first line
        return binarySearch(arr, 0, pivot - 1, k);
    }
}

int main()
{
    // int arr[5] = {7, 9, 1, 2, 3};
    int n;
    cout << "Enter the size of array : ",
        cin >> n;

    int arr[n];
    cout << "Enter the element of an array : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int k;
    cout << "Enter the target element : ";
    cin >> k;

    cout << " Search in Rotated Sorted Array, Target element found at an index : " << findPosition(arr, n, k);
    return 0;
}
