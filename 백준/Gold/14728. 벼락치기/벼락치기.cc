#include<iostream>
#include<algorithm>
using namespace std;

int dp[101][10001];
int chapter[101];
int score[101];

int main() {
	int n, t, k, s;
	//n 단원개수 t 공부가능시간 k단원별 공부시간 s문제배점

	cin >> n >> t;
	for (int i = 1; i <= n; i++) {
		cin >> chapter[i] >> score[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= t; j++) {
			if (j >= chapter[i]) {
				dp[i][j] = max(dp[i-1][j-chapter[i]]+score[i],dp[i-1][j]);//max(넣었을때,안넣었을때)
			}
			else {
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	cout << dp[n][t]<<endl;


}