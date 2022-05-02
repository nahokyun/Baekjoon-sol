#include<iostream>
#include<queue>
using namespace std;
int map[101][101];
bool flag[101][101];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int n;

int bfs(int x, int y,int height) {
	queue<pair<int,int>> q;
	q.push({ x, y });
	while (!q.empty()) {
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nxt_x = cur_x + dx[i];
			int nxt_y = cur_y + dy[i];
			if (nxt_x >= 0 && nxt_x < n && nxt_y >= 0 && nxt_y < n &&
				flag[nxt_y][nxt_x] != true &&map[nxt_y][nxt_x]>height) {
				flag[nxt_y][nxt_x] = true;
				q.push({ nxt_x,nxt_y });
				
			}
		}

	}
	return 1;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int min=101;//물잠기는 최소높이
	int mx = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (min > map[i][j])
				min = map[i][j];
			if (mx < map[i][j])
				mx = map[i][j];
		}
	}
	int mx_count = 0;
	for (int z = min-1; z < mx; z++) {
		int count = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (flag[i][j] == false && map[i][j] > z) {
					flag[i][j] = true;
					count += bfs(j, i, z);
				}
			}
		}
		if (count > mx_count)
			mx_count = count;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				flag[i][j] = false;
			}
		}
	}
	cout << mx_count<<endl;

}