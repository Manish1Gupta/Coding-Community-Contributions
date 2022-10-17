#include <iostream>
using namespace std;

int moveZero(int arr[], int n)
{
    int i = 0;
    for (int j = 0; j < n; j++){
        if (arr[j] != 0){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
        }
    }
}
void print(int ans[], int n){
    for (int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }
}

int main(){
    int n;
    cout << "Enter the size of an array : ";
    cin >> n;

    int arr[n];
    cout << "Enter the array element : ";
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    moveZero(arr, n);
    cout << "Array after shift all zero into right : ";
    print(arr, n);
    return 0;
}




// Output- 
// Enter the size of an array : 5
// Enter the array element : 10 0 20 0 30  
// Array after shift all zero into right : 10 2 30 0 0 
