#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int dp[10001];
vector<int> coin;
//배낭문제와 유사하였다
int main() {
	int n, k;
	int c;
	cin >> n >> k;//dp[i][j]는 i번까지의 동전을 써서 만드는 j원의 갯수
	for (int i = 0; i < n; i++) {
		cin >> c;
		coin.push_back(c);
	}
	sort(coin.begin(), coin.end());
	if (coin[0] == 1)
		dp[1] = 1;
	else
		dp[1] = 0;
	//초기dp값 설정
	int first = coin[0];
	for (int i = 1; i <= k; i++) {
		if (i / first >= 0 && i % first == 0)
			dp[i] = 1;
		else {
			dp[i] = 0;
		}
	}


	for (int i = 2; i <= n; i++) {
		int x = coin[i - 1];

		for (int j = 1; j <= k; j++) {
			if (x == j) {
				dp[j] = dp[j] + 1;
			}
			else if(j>=x) {
				dp[j] = dp[j - x] + dp[j];

			}

		}


	}
	cout << dp[k] << endl;

}