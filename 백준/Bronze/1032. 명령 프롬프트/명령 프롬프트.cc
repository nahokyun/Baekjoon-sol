#include<string>
#include<iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	string a[50];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int len = a[0].size();

	string b;
	for (int i = 0; i < a[0].size(); i++) {
		int flag = 0;
		char cmp = a[0][i];
		for (int j = 1; j < n; j++) {
			if (a[j][i] != cmp) {
				flag = 1;
				b+= '?';
				break;
			}
		}
		if (flag == 0)
			b+= cmp;

	}


	cout << b<<endl;
}