#include<bits/stdc++.h>
using namespace std;


void merge(int A[], int b, int m, int e)
{
    int len = (e-b+1);
    int B[len];
    int i = b, j = m+1, k = 0;
    while(i <= m && j <= e)
    {
        if(A[i]< A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }

    while(i <= m)
        B[k++] = A[i++];
    
    while(j <= e)
        B[k++] = A[j++];

    for(k = 0; k < len ; k++)
        A[b++] = B[k];    
}
void division(int A[], int low, int high)
{
    if(low < high)
    {
        int mid = (low+high)/2;
        division(A, low, mid);
        division(A, (mid+1), high);
        merge(A, low, mid, high);
    }
}


int main()
{
    int n,i,a[100];
    cout<<"Enter the no.of elements:- \n";
    cin>>n;
    cout<<"Enter the elements: \n";
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    division(a, 0, n-1);
    cout<<"The sorted array is:- \n";
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}