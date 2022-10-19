#include <bits/stdc++.h>
using namespace std;
void reverseStr(string& str)
{
	int n = str.length();
	for (int i = 0; i < n / 2; i++)
		swap(str[i], str[n - i - 1]);
}
int main()
{
	string input_str;
	cin>>input_str;
	reverseStr(input_str);
	cout << "Reversed string: "<< input_str;
	return 0;
}
