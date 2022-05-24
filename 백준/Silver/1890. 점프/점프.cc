#include<iostream>

using namespace std;
unsigned long long map[101][101];
unsigned long long dp[101][101];
unsigned long long n;
unsigned long long back(int a, int b) {
	if (dp[a][b] != -1)
		return dp[a][b];
	if (a == n - 1 && b == n - 1)
		return 1;

	dp[a][b] = 0;
	unsigned long long move_size = map[a][b];
	if (map[a][b] != 0) {
		if (a + move_size < n)
			dp[a][b] += back(a + move_size, b);
		if (b + move_size < n)
			dp[a][b] += back(a, b + move_size);
	}
	return dp[a][b];
}


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			dp[i][j] = -1;
		}
	}

	cout<< back(0, 0)<<endl;





}