#include<iostream>
#include<stack>
#include<string>
using namespace std;
//stack		last in first out
int main() {
	string a;
	
	int n;
	
	cin >> n;
	while(n--) {
		int flag = 0;
		stack<char> s;
		cin >> a;
		for (int i = 0; i < a.size(); i++) {
			if (a[i] == '(') {
				s.push(a[i]);
			}
			else {
				if (s.size() > 0) {
					s.pop();

				}
				else
				{
					flag = 1;
					break;
				}

			}
		}
		if (!s.empty())
			flag = 1;
		if (flag == 1)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;

	}
}