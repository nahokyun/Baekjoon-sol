#include<iostream>

using namespace std;
int arr[100001];
int dp[100001][4];
int main() {
	int t;
	int n;

	cin >> t;
	dp[1][1] = 1;
	dp[2][2] = 1;
	dp[3][1] = 1;
	dp[3][2] = 1;
	dp[3][3] = 1;
	int mx = 0;
	for (int i = 0; i < t; i++) {
		cin >> n;
		arr[i] = n;
		if (mx < n)
			mx = n;
	}

	for (int i = 4; i <= mx; i++) {
		for (int j = 1; j <= 3; j++) {
			if (j == 1) {
				dp[i][j] = (dp[i - 1][2] + dp[i - 1][3])%1000000009;
			}
			else if (j == 2) {
				dp[i][j] = (dp[i - 2][1] + dp[i - 2][3]) % 1000000009;
			}
			else if (j == 3) {
				dp[i][j] = (dp[i - 3][1] + dp[i - 3][2]) % 1000000009;
			}
		}
	}
	int sum;
	for (int i = 0; i < t; i++) {
		sum = 0;
		for (int j = 1; j <= 3; j++) {
			sum =(sum+ dp[arr[i]][j]) % 1000000009;
		}
		cout << sum << endl;
	}
}