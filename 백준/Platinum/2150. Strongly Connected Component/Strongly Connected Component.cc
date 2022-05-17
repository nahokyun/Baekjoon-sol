#include<stack>
#include<iostream>
#include<algorithm>
#include<vector>
#define MAX 10002
using namespace std;

vector<int> v[MAX];//입력정보(그래프)를 받을 vector
vector<int> trans_v[MAX];//transpose 그래프 정보를 저장할 vector
vector<int> scc;//매 루프마다 scc cycle에 해당하는 노드를 임시로 저장해둘 vector
vector<vector<int>> result;
stack<int> s;//dfs결과순을 저장해줄 stack

bool visit[MAX];//dfs에서 탐색체크를 위한 bool array
bool visit_2[MAX];//dfs_2에서 탐색체크를 위한 bool array
int n, m;//input n과 m
int x, y;//list 넣을 입력받을 변수


void dfs(int cur) {
	visit[cur] = true;
	
	for (int i = 0; i < v[cur].size(); i++) {
		int nxt = v[cur][i];
		if (visit[nxt] == true)
			continue;
		dfs(nxt);
	}
	s.push(cur);
}

void dfs_2(int cur) {
	visit_2[cur] = true;
	
	for (int i = 0; i < trans_v[cur].size(); i++) {
		int t_nxt = trans_v[cur][i];
		if (visit_2[t_nxt] == true)
			continue;
		dfs_2(t_nxt);
	}
	scc.push_back(cur);
}





int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;//노드개수와 간선개수 입력

	for (int i = 0; i < m; i++) {//그래프 입력
		cin >> x >> y;
		v[x].push_back(y);
		trans_v[y].push_back(x);
	}
	//여기까지 그래프 입력후 탐색순서까지 저장한 상태

	for (int i = 1; i <= n; i++) {//첫번째 dfs 사용 
		if (visit[i] == false)
			dfs(i);
	}



	while (!s.empty()) {
		int cur = s.top();
		s.pop();

		if (visit_2[cur] == true)
			continue;
		dfs_2(cur);

		sort(scc.begin(), scc.end());
		result.push_back(scc);
		scc.clear();
		
	}
	

	sort(result.begin(), result.end());
	cout << result.size()<<endl;
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			cout << result[i][j]<<" ";
		}
		cout << -1 << endl;
	}


}