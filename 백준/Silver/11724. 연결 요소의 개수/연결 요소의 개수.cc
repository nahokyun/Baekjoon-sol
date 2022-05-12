#include<iostream>
#include<vector>
using namespace std;
vector<int> arr[1001];
bool flag[1001];
int ct = 0;
void dfs(int x) {
	flag[x] = true;
	for (int i = 0; i < arr[x].size(); i++) {
		int a = arr[x][i];
		if (flag[a] == false) {
			flag[a] = true;
			dfs(a);
		}
	}
	
}


int main() {
	int n, m;
	int a, b;
	

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		if (flag[i] == false) {
			dfs(i);
			ct++;
		}
	}
	cout << ct << endl;
}