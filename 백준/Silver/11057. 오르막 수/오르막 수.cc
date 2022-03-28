#include<iostream>

using namespace std;

int dp[1001][10];//dp[i][x]라고 하면 i번째길이에서 x로 끝나는 오르막수의 수라고 정의

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < 10; i++) {
		dp[1][i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k <= j; k++) {
				dp[i][j] =(dp[i][j]+ dp[i - 1][k])%10007;
			}
		}
	}
	int up = 0;//오르막수의 개수를 저장할 변수
	for (int i = 0; i < 10; i++) {
		up = (up+dp[n][i])%10007;
	}

	cout << up << endl;
}