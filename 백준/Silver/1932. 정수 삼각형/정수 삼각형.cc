#include<iostream>
#include<algorithm>
using namespace std;

int dp[501][501];
int n;
int arr[501][501];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> arr[i][j];
		}
	}
	dp[0][0] = arr[0][0];
	dp[1][0] = arr[0][0] + arr[1][0];
	dp[1][1] = arr[0][0] + arr[1][1];
	int max_v = 0;
	for (int i = 2; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0)
				dp[i][j] = dp[i - 1][j] + arr[i][j];
			else if (j == i)
				dp[i][j] = dp[i - 1][j-1]+ arr[i][j];
			else
				dp[i][j] = max(dp[i - 1][j-1] + arr[i][j],dp[i-1][j]+arr[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		if (max_v < dp[n - 1][i])
			max_v = dp[n - 1][i];
	}
	cout << max_v << endl;
}