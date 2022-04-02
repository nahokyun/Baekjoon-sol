#include<iostream>
#include<algorithm>
using namespace std;
pair<int, int> a[50];
pair<int, int> b[50];
int main() {
	int n;
	cin >> n;
	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		a[i] = make_pair( x, i );
		b[i] = make_pair(x, i);
	}
	sort(a, a+n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[j].first == b[i].first) {
				b[i].second = j;
				a[j].first = -1;
				break;
			}
		}
	}
	for (int i = 0; i < n; i++)
		cout << b[i].second<<" ";

}