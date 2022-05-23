#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int arr[101][101];
bool flag[101][101];
int n, m, k;
int x, y;
int f_x, f_y;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int c_section = 0;//영역 갯수
int ct = 0;//dfs결과 넓이
void dfs(int a, int b) {
	flag[a][b] = true;
	ct++;
	for (int i = 0; i < 4; i++) {
		int n_y = a + dy[i];
		int n_x = b + dx[i];
		if (n_y >= 0 && n_y < n && n_x >= 0 && n_x < m && flag[n_y][n_x] == false && arr[n_y][n_x] == 0) {
			flag[n_y][n_x] = true;
			dfs(n_y, n_x);
			
		}

	}

}


vector<int> v;
int main() {
	cin >> n >> m >> k;

	while (k--) {
		cin >> x >> y;
		cin >> f_x >> f_y;
		int dif_x = f_x - 1 - x;
		int dif_y = f_y - 1 - y;
		for (int i = y; i < f_y; i++) {
			for (int j = x; j < f_x; j++) {
				arr[i][j] = 1;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (flag[i][j] == false && arr[i][j] == 0) {
				c_section++;
				ct = 0;
				dfs(i, j);
				v.push_back(ct);
			}
		}
	}

	sort(v.begin(), v.end());
	cout << c_section << endl;
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

}