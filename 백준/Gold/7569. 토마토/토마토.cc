#include<iostream>
#include<queue>
using namespace std;

int map[10001][101];
bool flag[10001][101];
int n, m, h;
int dx[6] = { 0,1,0,-1,0,0 };
int dy[6] = { 1,0,-1,0 ,0,0 };
int dh[6] = { 0,0,0,0,1,-1 };
int mx = -1;

queue<pair<pair<int, int>, pair<int,int>>> q;
void bfs() {
	while (!q.empty()) {
		
		int c_y = q.front().first.first;
		int c_x = q.front().first.second;
		int c_h = q.front().second.first;
		int c_t = q.front().second.second;
		if (mx < c_t)
			mx = c_t;
		q.pop();
		flag[c_h * m + c_y][c_x] = true;

		for (int i = 0; i < 6; i++) {
			int n_y = c_y + dy[i];
			int n_x = c_x + dx[i];
			int n_h = c_h + dh[i];
			int n_t = c_t + 1;
			if (n_x >= 0 && n_x < n && n_y >= 0 && n_y < m && n_h >= 0 && n_h < h
				&& flag[n_h * m + n_y][n_x] == false&&map[n_h * m + n_y][n_x]==0) {
				map[n_h * m + n_y][n_x] = 1;
				q.push({ { n_y,n_x }, {n_h, n_t} });
				flag[n_h * m + n_y][n_x] == true;

			}

		}




	}
}


int main() {
	cin >> n >> m >> h;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < n; k++) {
				cin >> map[i * m + j][k];
				if (map[i * m + j][k] == 1) {
					q.push({ { j,k },{i,0} });//y,x,h로 저장
				}
			}
		}
	}



	if (!q.empty())
		bfs();

	int check = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < n; k++) {				
				if (map[i * m + j][k] == 0) {
					check = 1;
				}
			}
		}
	}
	if (check == 1)
		cout << -1 << endl;
	else
		cout << mx << endl;
}