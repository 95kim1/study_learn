#include <iostream>
#include <stack>
#include <queue>
#include <string>
using namespace std;

int main(void)
{
	string str, num;
	cin >> str;
	stack<int> nums;
	stack<char> ops;
	num = "";
	for (int i = 0; i < (int)str.length(); i++)
	{
		char c = str[i];
		if (c == '-')
		{
			nums.push(stoi(num));
			num = "";
			ops.push(c);
		}
		else if (c == '+')
		{
			int n1 = stoi(num);
			num = "";
			i++;
			while ('0' <= str[i] && str[i] <= '9')
			{
				num += str[i];
				i++;
			}
			i--;
			int n2 = stoi(num);
			num = to_string(n1 + n2);
		}
		else
		{
			num += c;
		}
	}
	if (num != "")
		nums.push(stoi(num));

	while (!ops.empty())
	{
		ops.pop();

		int n2 = nums.top();
		nums.pop();
		int n1 = nums.top();
		nums.pop();

		if (nums.empty())
			nums.push(n1 - n2);
		else
			nums.push(n1 + n2);
	}
	cout << nums.top() << '\n';
	return 0;
}
