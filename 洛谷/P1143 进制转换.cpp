#include <iostream>
using namespace std;
#include <sstream>
const int N = 1e2;
int p1, p2;
int jz[N];
char zj[N];
void init()
{
	// char == > n
	for (int i = '0', j = 0; i <= '9'; ++i, ++j)
		jz[i] = j;
	for (int i = 'A', j = 10; i <= 'F'; ++i, ++j)
		jz[i] = j;

	//n == > char
	for (int i = 0, j = '0'; i <= 9; ++i, ++j)
		zj[i] = j;
	for (int i = 10, j = 'A'; i <= 15; ++i, ++j)
		zj[i] = j;

}

//p1 -> 10
int cg_to_10(string s)
{
	int res = 0;
	for (int i = 0; i <s.size(); ++i)
		res = res * p1 + jz[s[i]];
	return res;
}


//10 -> p2
string cg_to_p2(int n)
{
	string res;
	while (n)
	{
		res.push_back(zj[n % p2]);
		n /= p2;
	}
	return string(res.rbegin(), res.rend());
}

int main()
{
	init();
	string s;
	scanf("%d", &p1);
	cin >> s;

	int t = cg_to_10(s);

	scanf("%d", &p2);

	s = cg_to_p2(t);

	cout << s;
	return 0;
}

