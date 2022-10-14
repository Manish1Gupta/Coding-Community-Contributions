#include <iostream>
using namespace std;

void printfib(int n){
    int first = 0, second = 1, third;

    cout << first << " " << second;
    for (int i = 2; i < n; i++){
        third = first + second;
        cout << " " << third;
        first = second;
        second = third;
    }
}

int main() {
    int n, t1 = 0, t2 = 1, nextTerm = 0;

    cout << "Enter the number of terms: ";
    cin >> n;

    cout << "Fibonacci Series: ";

    for (int i = 1; i <= n; ++i) {
        // Prints the first two terms.
        if(i == 1) {
            cout << t1 << ", ";
            continue;
        }
        if(i == 2) {
            cout << t2 << ", ";
            continue;
        }
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
        
        cout << nextTerm << ", ";
    }
    // printfib(n);
    return 0;
