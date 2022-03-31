#include<iostream>
//#include<algorithm>
using namespace std;
int dp_max[3][4];
int dp_min[3][4];
int arr[4];

int max(int a, int b) {
	if (a > b)
		return a;
	else
		return b;
}
int min(int a, int b) {
	if (a > b)
		return b;
	else
		return a;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	int x;
	cin >> n;
	for (int i = 0; i < 3; i++) {
		cin >> x;
		arr[i + 1] = x;
		dp_max[2][i + 1] = x;
		dp_max[1][i + 1] = x;
		dp_min[2][i + 1] = x;
		dp_min[1][i + 1] = x;
	}

	for (int i = 4; i <= 3 * n; i++) {

		//4번째 이후부터 3글자씩 받음
		if (i % 3 == 1) {
			cin >> arr[1];
			continue;
		}
		if (i % 3 == 2) {
			cin >> arr[2];
			continue;
		}
		if (i % 3 == 0) {
			cin >> arr[3];
		}
		//4,5,6번째를 받았을때
		for (int j = 1; j < 4; j++) {
			x = arr[j];
			if (j % 3 == 1) {
				dp_max[2][1] = max(dp_max[1][1], dp_max[1][2]) + x;
				dp_min[2][1] = min(dp_min[1][1], dp_min[1][2]) + x;
			}
			else if (j % 3 == 2) {
				dp_max[2][2] = max(dp_max[1][2], max(dp_max[1][1], dp_max[1][3])) + x;
				dp_min[2][2] = min(dp_min[1][2], min(dp_min[1][1], dp_min[1][3])) + x;
			}
			else if (j % 3 == 0) {
				dp_max[2][3] = max(dp_max[1][3], dp_max[1][2]) + x;
				dp_min[2][3] = min(dp_min[1][3], dp_min[1][2]) + x;
			}
		}

		for (int j = 1; j < 4; j++) {
			dp_max[1][j] = dp_max[2][j];
			dp_min[1][j] = dp_min[2][j];
		}

	}
	cout << max(dp_max[2][1], max(dp_max[2][2], dp_max[2][3])) << " "
		<< min(dp_min[2][1], min(dp_min[2][2], dp_min[2][3])) << endl;
}

