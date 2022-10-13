/* Hamming code is a set of error-correction codes that can be used to detect and correct the errors that can occur when the data is moved or stored from the sender to the receiver. It is a technique developed by R.W. Hamming for error correction. Redundant bits – Redundant bits are extra binary bits that are generated and added to the information-carrying bits of data transfer to ensure that no bits were lost during the data transfer. */

#include <iostream>
#include <cmath>
using namespace std;

char Parity(char, int);

int length(char expr[])
{
    int i = 0;
    int count = 0;
    while(expr[i] != '\0')
    {
        count++;
        i++;
    }
    
    return count;
}

int eval_r(int m)
{
    int r = 1;
    while(!(pow(2,r) >= (m + r + 1)))
    {
        r++;
    }
    
    return r;
}

void codeword(const char* expr, char* arr, int size)
{
    int j = 0;
    int k = 0;
    for(int i = 0; i<size; i++)
    {
        if((i + 1) == pow(2,j))
        {
            arr[i] = 'c';
            j++;
        }
        else
        {
            arr[i] = expr[k];
            k++;
        }
    }
}

void finalcode(char* arr, int size, int r, char parity)
{
    unsigned int check;
    unsigned int count;
    for(int i = 0; i<r; i++)
    {
        count = 0;
        check = pow(2,i);
        for(int j = check; j<size; j++)
        {
            if((j + 1) & check)
            {
                count += int(arr[j] - '0');
            }
        }
        arr[int(check - 1)] = Parity(parity, count);
    }
}

char Parity(char ch, int c)
{
    switch(toupper(ch))
    {
        case 'O':   if(c%2 == 0)
                    {
                        return '1';
                    }
                    return '0';
                  
        case 'E':   if(c%2 != 0)
                    {
                        return '1';
                    }
                    return '0';
                    
        default:    cout << "Invalid character!";
                    exit(1);
    }
}

int main()
{
    int m;
    int r;
    const unsigned int size = 100;
    
    char binary[size];
    cout << "Enter the binary code(for data bits) : ";
    cin.getline(binary, size);

    m = length(binary);
    r = eval_r(m);
    
    int n = (m + r);
    char coded[n];
    codeword(binary, coded, n);
    
    cout << "coded binary code : ";
    for(int i=0; i<n; i++)
    {
        cout << coded[i];
    }
    
    char ans;
    cout << "\n\nEnter the parity type (press E for 'even' and O for 'odd'): ";
    cin >> ans;
    
    finalcode(coded,n,r,ans);
    
    cout << "Hamming Code transmitted: ";
    for(int i = 0; i<n; i++)
    {
        cout << coded[i];
    }
    
    return 0;
}
