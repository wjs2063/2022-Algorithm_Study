#pragma warning(disable: 4996)
#include <bits/stdc++.h>
using namespace std;

int n, k;
string add[36];

// 10진수를 36진수로
char conv10to36(int i)
{
	if (i <= 9)
		return '0' + i;
	return 'A' + i - 10;
}

// 36진수를 10진수로
int conv36to10(char i)
{
	if (i <= '9')
		return i - '0';
	return i - 'A' + 10;
}

// 36진수 덧셈
string add36(string a, string b)
{
	string result = "";
	
	int i = a.size() - 1;
	int j = b.size() - 1;

	int z = 0;
	while (i >= 0 || j >= 0 || z)
	{
		int tmp = z;
		if (j >= 0)
			tmp += conv36to10(b[j]);
		if (i >= 0)
			tmp += conv36to10(a[i]);

		result = conv10to36(tmp % 36) + result;
		z = tmp / 36;

		i--;
		j--;
	}

	return result;
}

// 36진수와 자릿수를 받으면 그에 맞는 문자열 반환
string getPivot(int m, char s)
{
	if (s == '0')
		return "0";

	string result = string() + s;
	for (int i = 0; i < m; i++)
		result += "0";
	return result;
}

int main()
{
	string sum = "0";

	for (int i = 0; i < 36; i++)
		add[i] = "0";

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;

		sum = add36(sum, s);

		int cnt = 0;
		for (auto iter = s.rbegin(); iter != s.rend(); iter++, cnt++)
		{
			string t = getPivot(cnt, conv10to36((35 - conv36to10(*iter))));
			add[conv36to10(*iter)] = add36(add[conv36to10(*iter)], t);
		}
	}
	scanf("%d", &k);

	sort(add, add + 36, [](string a, string b) {
		if (a.size() == b.size())
		{
			for (int i = 0; i < a.size(); i++)
			{
				if (a[i] == b[i])
					continue;
				return conv36to10(a[i]) > conv36to10(b[i]);
			}
		}
		return a.size() > b.size();
		});

	for (int i = 0; i < k; i++)
		sum = add36(sum, add[i]);

	cout << sum;
}