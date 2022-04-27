#include<iostream>
#include<vector>
using namespace std;
bool flag[50];
vector<int> res;
void bt(vector<int> v, int cur) {
	if (cur == 6){
		for (int i = 0; i < 6; i++) {
			cout << res[i]<<" ";
		}
		cout << "\n";
	}
	else {
		for (int i = cur; i < v.size(); i++) {
			if (!res.empty()&&v[i] < res[res.size() - 1])
				continue;
			if (flag[v[i]] == false) {
				flag[v[i]] = true;
				res.push_back(v[i]);
				bt(v, cur + 1);
				res.pop_back();
				flag[v[i]] = false;
			}
		}



	}
}





int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	int x;
	cin >> n;
	
	while (n != 0) {
		vector<int> v;
		for (int i = 0; i < n; i++) {
			cin >> x;
			v.push_back(x);
			
		}
		bt(v, 0);

		cout << "\n";
		cin >> n;
	}




}