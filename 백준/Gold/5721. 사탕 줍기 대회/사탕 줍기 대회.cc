#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;
int n, m;
int a;
int sum = 0;
vector<int> v[100001];
int dp[100001];
int dp_2[100001];
int cal_mx(int i) {
	memset(dp_2, 0, 100001);
	int maxx = 0;
	for (int j = 0; j < n; j++) {
		if (j == 0)
			dp_2[j] = v[i][j];
		else if(j <= n-1){
			/*
			for (int k = 0; k < j-1; k++) {
				if (dp_2[j] < dp_2[k])
					dp_2[j] = dp_2[k];
			}
			dp_2[j] += v[i][j];
			*/
			dp_2[j] = max(dp_2[j - 1], v[i][j] + dp_2[j - 2]);
		}

		if (maxx < dp_2[j])
			maxx = dp_2[j];
	}
	
	return maxx;

}
int cal_mx() {
	if (m == 2) {
		return max(dp[0], dp[1]);
	}
	for (int j = 1; j < m; j++) {
		/*
		for (int k = 0; k < j - 1; k++) {
			if (x < dp[k])
				x= dp[k];
		}
		dp[j] = x + dp[j];
		*/
		dp[j] = max(dp[j - 1], dp[j - 2]+dp[j]);
	}
	return dp[m-1];
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	while (1) {
		
		cin >> m >> n;
		sum = 0;
		if (n == 0 && m == 0)
			break;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a;
				v[i].push_back(a);
			}
		}
		for (int i = 0; i < m; i++) {
			dp[i] = cal_mx(i);
		}

		cout<<cal_mx()<<"\n";

		memset(dp, 0, 100001);
		for (int i = 0; i < m; i++) {
			v[i].clear();
		}
	}


}