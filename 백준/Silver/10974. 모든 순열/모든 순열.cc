#include<iostream>
#include<vector>
using namespace std;

int n;
vector<int> v;
bool check[9];
void tracking(int num) {

	if (num == n) {
		for (int i = 0; i<v.size(); i++) {
			cout << v[i] << " ";
		}
		cout <<"\n";
	}
	else {
		for (int i = 1; i <= n; i++) {
			if (check[i] == true)
				continue;
			else {
				v.push_back(i);
				check[i] = true;
				tracking(num + 1);
				check[i] = false;
				v.pop_back();
			}
		}


	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	
	cin >> n;
	tracking(0);

	

}