#include<iostream>


using namespace std;

int arr[31][2];//계수
int a[31];
int b[31];

int n, k;
int flag = 0;

int main() {
	cin >> n >> k;
	a[1] = 1;
	a[2] = 0;
	b[1] = 0;
	b[2] = 1;
	for (int i = 3; i <= n; i++) {
		a[i] = a[i - 1] + a[i - 2];
		b[i] = b[i - 1] + b[i - 2];
	}

	for (int i = 1; i <= k; i++) {
		int sp = k - (a[n] * i);
		if (sp % b[n] == 0) {
			cout << i << "\n"<<sp/b[n] << endl;
			break;
		}
	}
}

