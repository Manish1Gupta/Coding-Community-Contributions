//Name : Akashdeep-k
//Date : 15/10/2022
// optimized code for bubble sorting of array in ascending order
//Time complexity : best case - O(n) & worst case - O(n^2)
#include <iostream>
using namespace std;
int main()
{
    int n; // size of array
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) // array input
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n - 1; i++) // sorting algorithm
    {
        int flag = 0;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                flag = 1;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
    for (int i = 0; i < n; i++) // array printing
    {
        if (i < n - 1)
            cout << arr[i] << " ";
        else
            cout << arr[n - 1];
    }
    return 0;
}
