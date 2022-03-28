#include<iostream>
#define mod 1000000007 
using namespace std;
int n, m, k;
int house[1001][1001];
int dp[1001][1001];//dp[y][x]는 y,x에서 목적지까지 가는 경우의수

int h_dx[3] = { 1,1,0 };
int h_dy[3] = { -1,0,1 };
int j_dx[3] = {1,1,0};
int j_dy[3] = {0,1,1};

int dfs(int x, int y) {
	if (dp[y][x] != -1)
		return dp[y][x];
	if (y == n && x == m) {
		return 1;
	}
	
	dp[y][x] = 0;//한번이라도 방문했는가
	if (x % 2 == 1) {//가로 홀수칸일때
		for (int i = 0; i < 3; i++) {
			int nxt_x = x + h_dx[i];
			int nxt_y = y + h_dy[i];
			if (nxt_x > 0 && nxt_x <= m && nxt_y > 0 &&
				nxt_y <= n && house[nxt_y][nxt_x] != -1) {
				dp[y][x] =(dp[y][x]+ dfs(nxt_x, nxt_y))%mod;
			}


		}
	}
	else {
		for (int i = 0; i < 3; i++) {
			int nxt_x = x + j_dx[i];
			int nxt_y = y + j_dy[i];
			if (nxt_x > 0 && nxt_x <= m && nxt_y > 0 &&
				nxt_y <= n && house[nxt_y][nxt_x] != -1) {
				dp[y][x] =(dp[y][x]+ dfs(nxt_x, nxt_y))%mod;
			}


		}



	}

	return dp[y][x];

}


int main() {
	cin >> n >> m;
	cin >> k;
	int x_, y_;
	for (int i = 0; i < k; i++) {
		cin >> y_ >> x_;
		house[y_][x_] = -1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			dp[i][j] = -1;
	}
	dp[n][m] = 1;
	dfs(1, 1);
	cout << dp[1][1] << endl;
}