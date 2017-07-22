#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	char a[200], b[200];
	while (cin >> a)
	{
		cin >> b;
		int len1 = strlen(a);
		int len2 = strlen(b);
		int n[200], m[200];
		memset(n, 0, sizeof(n));
		memset(m, 0, sizeof(m));
		for (int i = 0; i < len1; ++i)
		{
			n[i] = a[len1 - i - 1] - '0';
		}
		for (int i = 0; i < len2; ++i)
		{
			m[i] = b[len2 - i - 1] - '0';
		}
		int borrow[200], ans[200];
		memset(borrow, 0, sizeof(borrow));
		memset(ans, 0, sizeof(ans));
		for (int i = 0; i < len1; ++i)
		{
			int t = n[i] - m[i] - borrow[i];
			if (t < 0)
			{
				t += 10;
				borrow[i + 1] = 1;
			}
			ans[i] = t;

		}
		int last = len1 - 1;
		while (last >= 0 && ans[last] == 0)
			--last;
		if (last < 0)
			cout << 0 << endl;
		else
		{
			for (int i = last; i >= 0; --i)
				cout << ans[i];
			cout << endl;
		}
	}

}

