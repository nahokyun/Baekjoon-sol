#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int n, m, s;
int v[51];
vector<int> dp[51];
bool flag[1001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> s >> m;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	if (s + v[0] <= m) {
		dp[1].push_back(s + v[0]);
	}
	if (s - v[0] >= 0) {
		dp[1].push_back(s - v[0]);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < dp[i].size(); j++) {
			int x = dp[i][j];
			if (x + v[i] <= m&&flag[x+v[i]]==false) {
				flag[x + v[i]] = true;
				dp[i + 1].push_back(x + v[i]);
			}
			if (x - v[i] >= 0 && flag[x - v[i]] == false) {
				flag[x - v[i]] = true;
				dp[i + 1].push_back(x - v[i]);
			}
		}
		if (dp[i+1].empty()){
			cout << -1 << endl;
			return 0;
		}
		memset(flag, false, 1001);
	}
	int mx=0;
	for (int i = 0; i < dp[n + 1].size(); i++) {
		if (mx < dp[n + 1][i])
			mx = dp[n + 1][i];
	}
	cout << mx << endl;
}