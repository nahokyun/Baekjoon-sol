#include<iostream>
using namespace std;
int dp[31];
int one = 2;
int main() {
	dp[2] = 3;
	dp[3] = 0;
	int n;
	cin >> n;
	for (int i = 4; i <=n; i++) {
		if (i % 2 == 1)
			dp[i] = 0;
		else {
			int temp = 0;
			for (int j = 2; j <i; j = j + 2) {
				if (j == 2)
					temp += dp[i - j] * dp[2];
				else
					temp += dp[i - j] * 2;
			}

			dp[i] = temp + 2;



		}
	}

	cout << dp[n] << endl;
}