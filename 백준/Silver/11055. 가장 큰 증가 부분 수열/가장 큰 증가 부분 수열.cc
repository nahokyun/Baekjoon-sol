#include<iostream>
using namespace std;
int dp[1001];
int arr[1001];
int n;
int mx;//j 루프에서 dp의 최대값
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	dp[1] = arr[1];
	for (int i = 2; i <= n; i++) {
		mx = 0;
		for (int j = 1; j < i; j++) {
			if (arr[i] > arr[j]) {
				if (dp[mx] < dp[j])
					mx = j;
			}
		}
		dp[i] = dp[mx] + arr[i];//자기 자신을 넣었을때  수열의 합의 최댓값
	}
	mx = 0;
	for (int i = 1; i <= n; i++) {//여기선 mx 용도가 다름 그냥 있는변수 쓴거
		if (mx < dp[i])
			mx = dp[i];
	}
	cout << mx << endl;
	
}