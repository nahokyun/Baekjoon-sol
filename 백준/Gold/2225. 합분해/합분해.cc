#include<iostream>
#define mod 1000000000
using namespace std;
int dp[201][201];
int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i <= n; i++) {
		dp[1][i] = 1;
	}
	for (int i = 1; i <= k; i++) {
		dp[i][0] = 1;
	}
	


	for (int i = 2; i <= k; i++) {
		
		for (int j = 1; j <= n; j++) {
			dp[i][j] = (dp[i][j - 1] + dp[i - 1][j])%mod;


		}
	}

	cout << dp[k][n]%mod << endl;

}