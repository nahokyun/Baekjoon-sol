#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<int, int>> v;


int main() {
	int t, n,x,y;
	cin >> t;
	while (t--) {
		v.clear();
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> x >> y;
			v.push_back({ x,y });
		}
		sort(v.begin(), v.end());
		int grade = v[0].second;
		int count = 1;
		for (int i = 1; i < n; i++) {
			if (v[i].second < grade) {//지금 조사하는 사람의 등수가 더 좋음
				grade = v[i].second;
				count++;
			}
			else {
				continue;
			}
		}
		cout << count << endl;
	}


}