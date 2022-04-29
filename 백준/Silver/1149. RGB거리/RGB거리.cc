#include<iostream>
#include<algorithm>
using namespace std;

int dp[1001][3];
int cor[1001][3];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {//0번째 빨강 1번째 초록 2번째 파랑
			cin >> cor[i][j];
		}
	}
	dp[0][0] = cor[0][0];
	dp[0][1] = cor[0][1];
	dp[0][2] = cor[0][2];
	for (int i = 1; i <=n; i++) {
		for (int j = 0; j < 3; j++) {
			if (j == 0) {
				dp[i][j] = min(dp[i - 1][j + 1], dp[i - 1][j + 2]) + cor[i][j];
			}
			else if (j == 1) {
				dp[i][j] = min(dp[i - 1][j + 1], dp[i - 1][j - 1]) + cor[i][j];
			}
			else {
				dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j - 2]) + cor[i][j];
			}
		}
	}

	cout << min(min(dp[n][1], dp[n][2]), dp[n][0])<<endl;

}