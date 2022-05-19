#include<iostream>

using namespace std;
bool flag[41];
int dp[41];
int main() {
	int n;
	int m;
	int x;
	cin >> n >> m;
	dp[0] = 1;//1이 고정석일때 dp값을 위한 설정
	dp[1] = 1;
	for (int i = 0; i < m; i++) {
		cin >> x;
		flag[x] = true;
	}
	for (int i = 2; i <= n; i++) {
		if (flag[i]||flag[i-1]) {
			dp[i] = dp[i - 1];
		}
		else {
			dp[i] = dp[i - 1] + dp[i - 2];
		}

	}
	cout << dp[n] << endl;


}