#include<iostream>
#include<vector>
using namespace std;

int n;
int arr[9];
vector<int> varr;
int sum = 0;
int max_sum = 0;
bool check[9];
int cal() {
	sum = 0;
	for (int i = 0; i < n-1; i++) {
		sum=sum+abs(varr[i] - varr[i + 1]);
	}
	return sum;
}
void search(int num) {
	if (num == n) {
		if (cal() > max_sum)
			max_sum = cal();
	}
	else {
		for (int i = 0; i < n; i++) {
			if (check[i] == false) {
				check[i] = true;
				varr.push_back(arr[i]);
				search(num + 1);
				varr.pop_back();
				check[i] = false;
			}
		}
	}
}



int main() {
	

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	search(0);
	cout << max_sum << endl;

}