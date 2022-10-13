Hi there,
Thank you for your interest in Hacktoberfest and in helping others make their first contributions to open source.


SOLVE THIS ISSUE.


Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters.




Solution:

#include<iostream>
#include<algorithm>

using namespace std;

string longestCommonPrefix(string ar[], int n)
{

	if (n == 0)
		return "";

	if (n == 1)
		return ar[0];

	sort(ar, ar + n);

	int en = min(ar[0].size(),
				ar[n - 1].size());

	string first = ar[0], last = ar[n - 1];
	int i = 0;
	while (i < en && first[i] == last[i])
		i++;

	string pre = first.substr(0, i);
	return pre;
}

int main()
{
	string ar[] = {"flower","flow","flight"};
	int n = sizeof(ar) / sizeof(ar[0]);
	cout << "The longest common prefix is: "
		<< longestCommonPrefix(ar, n);
	return 0;
}



