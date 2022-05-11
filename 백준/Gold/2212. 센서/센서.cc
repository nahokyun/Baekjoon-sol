#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, k;
vector<int> arr;
vector<int> cmp;
int main() {
	cin >> n >> k;
	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		arr.push_back(x);
	}
	sort(arr.begin(), arr.end());
	for (int i = 1; i < n; i++) {
		cmp.push_back( arr[i] - arr[i-1]);
	}
	sort(cmp.begin(), cmp.end());
	if (n <= k) {
		cout << 0 << endl;
	}
	else {
		for (int i = 0; i < k - 1; i++) {
			x = cmp.size() - 1;
			cmp[x - i] = 0;
		}
		int mx = 0;
		for (int i = 0; i < n - 1; i++) {
			mx += cmp[i];
		}

		cout << mx << endl;
	}
}