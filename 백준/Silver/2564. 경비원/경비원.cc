#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main() {
	int x, y;
	int c, d;
	int n;
	int m_x, m_y;//동근이 위치 좌표
	vector<pair<int, int>> v;
	vector<int>dir;
	cin >> x >> y;
	cin >> n;
	for (int i = 0; i <= n; i++) {
		cin >> c >> d;
		dir.push_back(c);
		switch (c) {
		case 1://북쪽
			v.push_back({ y, d });
			break;
		case 2://남쪽
			v.push_back({ 0,d });
			break;
		case 3://서쪽
			v.push_back({ y-d,0 });
			break;
		case 4://동쪽
			v.push_back({ y-d,x });
			break;
		}
	}
	//first가 y좌표 second가 x좌표
	m_y = v[v.size() - 1].first;
	m_x = v[v.size() - 1].second;
	int sum = 0;
	int d_ = dir[n];//동근이 축
	for (int i = 0; i < v.size()-1; i++) {
		if (d_ == dir[i])//같은 축에 있을때
			sum = sum + abs(m_y - v[i].first) + abs(m_x - v[i].second);
		else if (d_ == 1) {//동근이가 북일때
			if (dir[i] == 3) {
				sum = sum + m_x + y - v[i].first;
			}
			if (dir[i] == 2) {
				sum = sum + min(m_x + y + v[i].second,x-m_x+y+x-v[i].second);
			}
			if (dir[i] == 4) {
				sum = sum + x - m_x + y - v[i].first;
			}
		}
		else if (d_ == 2) {//동근이가 남일때
			if (dir[i] == 3) {
				sum = sum + m_x + v[i].first;
			}
			if (dir[i] == 1) {
				sum = sum + min(m_x + v[i].first + v[i].second, x - m_x + y + x - v[i].second);
			}
			if (dir[i] == 4) {
				sum = sum + x - m_x + v[i].first;
			}
		}
		else if (d_ == 3) {//동근이가 서일때
			if (dir[i] == 1) {
				sum = sum +y-m_y  + v[i].second;
			}
			if (dir[i] == 4) {
				sum = sum + min(m_y + x + v[i].first, y - m_y + x + y - v[i].first);
			}
			if (dir[i] == 2) {
				sum = sum + m_y + v[i].second;
			}
		}
		else if (d_ == 4) {//동근이가 동일때
			if (dir[i] == 2) {
				sum = sum + x - v[i].second + m_y;
			}
			if (dir[i] == 3) {
				sum = sum + min(m_y + v[i].first + x, y - m_y + x + y - v[i].first);
			}
			if (dir[i] == 1) {
				sum = sum + x - v[i].second + y - m_y;
			}
		}
	}


	cout << sum << endl;


}