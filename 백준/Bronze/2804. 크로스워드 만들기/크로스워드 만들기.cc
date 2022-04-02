#include<iostream>
#include<string>
using namespace std;

int main() {
	string a;
	string b;
	int flag = 0;
	int idx_a;
	int idx_b;
	cin >> a >> b;
	for (int i = 0; i < a.size(); i++) {
		if (flag == 1)
			break;
		for (int j = 0; j < b.size(); j++) {
			if (a[i] == b[j]) {
				flag = 1;
				idx_a = i;
				idx_b = j;
				break;
			}
		}
	}
	for (int i = 0; i < b.size(); i++) {
		
		for (int j = 0; j < a.size(); j++) {
			if (i == idx_b)
				cout << a[j];
			else if (j == idx_a) {
				cout << b[i];
			}else
				cout << ".";
		}
		cout << endl;
	}



}