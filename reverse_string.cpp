#include<iostream>
using namespace std;
int main()
{
	string input_str;
	cin>>input_str;
	int n = input_str.length();
	for (int i = 0; i < n / 2; i++)
		swap(input_str[i], input_str[n - i - 1]);
	cout << "Reversed string: "<< input_str;
	return 0;
}
