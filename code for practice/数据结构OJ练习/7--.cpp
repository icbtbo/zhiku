#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

struct term
{
	int coef;
	int exp;
};

int main()
{
	int cmp(term a, term b);
	string s;
	while (getline(cin, s))
	{
		stringstream ss(s);
		int m = 0, n = 0;
		term poly1[300], poly2[300];
		while (ss >> poly1[m].coef)
		{
			ss >> poly1[m].exp;
			++m;
		}
		getline(cin, s);
		stringstream ss2(s);
		while (ss2 >> poly2[n].coef)
		{
			ss2 >> poly2[n].exp;
			++n;
		}
		for (int i = 0; i < n; ++i)
		{
			int isfound = 0;
			for (int j = 0; j < m; ++j)
			{
				if (poly1[j].exp == poly2[i].exp)
				{
					isfound = 1;
					poly1[j].coef += poly2[i].coef;
					break;
				}
			}
			if (!isfound)
			{
				poly1[m++] = poly2[i];
			}
		}
		sort(poly1, poly1 + m, cmp);
		for (int i = 0; i < m; ++i)
		{
			if (poly1[i].coef)
			{
				cout << poly1[i].coef << ' ';
				cout << poly1[i].exp << ' ';
			}
		}
		cout << endl;
	}
	return 0;
}

int cmp(term a, term b)
{
	return a.exp > b.exp;
}

