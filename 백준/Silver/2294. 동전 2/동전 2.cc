#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n, k;
vector<int> arr;
int dp[101][10001];
int main() {


	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		arr.push_back(x);

	}
	sort(arr.begin(), arr.end());
	for (int i = 1; i <= n; i++) {
		dp[i][1] = 10001;
	}
	for (int i = 1; i <= k; i++) {
		if (i % arr[0] == 0)
			dp[1][i] = i / arr[0];
		else
			dp[1][i] = 10001;
	}

	for (int i = 2; i <= n; i++) {
		int cur = arr[i - 1];
		for (int j = 1; j <= k; j++) {
			if (j < cur) {
				dp[i][j] = dp[i - 1][j];
				continue;
			}
			if (j % cur == 0) {
				dp[i][j] = j / cur;
				continue;
			}
			dp[i][j] = min(dp[i][j - cur] + 1, dp[i - 1][j]);
			
		}
	}

	if (dp[n][k] != 10001)
		cout << dp[n][k] << endl;
	else
		cout << -1 << endl;
}