#include<cstdlib>
#include <cstring>
#include <iostream>
#include <cstdio>
using namespace std;

const int MAXN = 5005;
int n;
string f[MAXN]; //��string���ʹ洢
int a1[MAXN], a2[MAXN]; //�߾�������

string jiafa(string s1, string s2) {
	string ans;
	int len1 = s1.size();
	int len2 = s2.size();
	for (int i = 0; i < len1; i++) {
		a1[i] = s1[len1 - 1- i] - '0';
	}
	for (int i = 0; i < len2; i++) {
		a2[i] = s2[len2 - 1 - i] - '0';
	}
	
	len1 = max(len1, len2);
	for (int i = 0; i < len1; i++) {
		a1[i] += a2[i]; //�ӷ�
	}
	for (int i = 0; i < len1; i++) {
		a1[i + 1] += a1[i] / 10;
		a1[i] %= 10; //����һ�½�λ
	}
	while (a1[len1]) {
		a1[len1 + 1] += a1[len1] / 10;
		a1[len1] %= 10; //����һ�½�λ���µĳ�������
		len1++; 
	}
	for (int i = len1 - 1; i >= 0; i--) {
		ans += a1[i] + '0'; //�ۼӵ��ַ�����
	}
	return ans;
}

int main()
{
	cin >> n;
	f[0] = "1", f[1] = "1";
	if (n == 0) {
		cout << 0 << endl;
		return 0;
	}
	for (int i = 2; i <= n; i++) {
		f[i] = jiafa(f[i - 1], f[i - 2]); //�߾��ȵ���NB~��
	}

	cout << f[n] << endl;
	return 0;
}

