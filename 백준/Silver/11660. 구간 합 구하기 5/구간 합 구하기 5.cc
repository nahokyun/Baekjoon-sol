#include<iostream>
using namespace std;

int map[1025][1025];
int dp[1025][1025];
int n;
int m;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1] + map[i][j];
		}
	}

	while (m--) {
		int x_1, y_1,x_2,y_2;
		cin >> y_1 >> x_1>>y_2>>x_2;
		int result;
		
		result = dp[y_2][x_2] - (dp[y_1 - 1][x_2] + dp[y_2][x_1 - 1])+dp[y_1-1][x_1-1];
		
		cout << result << "\n";
	}
}