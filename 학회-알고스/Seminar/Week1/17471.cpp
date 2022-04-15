#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <queue>
#define MAX 11
using namespace std;

int N;
int INF = INT_MAX;
int cnt = 0;
int people[MAX];

vector<int> neighb[MAX];

bool bfs(vector<int> v) { // 선거구 내에 구역들이 연결되어 있는 지 확인
	bool c[MAX] = { false, }; 
	queue<int> q;
	vector<int>::iterator it;
	q.push(v[0]);
	c[v[0]] = true;

	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (int i = 0; i < neighb[node].size(); i++) {
			int next = neighb[node][i];
			it = find(v.begin(), v.end(), next);
			if (c[next] || it == v.end()) continue;
			c[next] = true;
			q.push(next);
		}
	}
	for (int i = 0; i < v.size(); i++) {
		if (c[v[i]] == false) return false;
	}
	return true;
}

void solve(vector<int> v) {
	int tmp = 0; // 선거구 인원 차이  
	vector<int> a, b;

	for (int i = 0; i < v.size(); i++) {
		if (v[i] == 0) a.push_back(i + 1);
		else b.push_back(i + 1);
	}

	if (bfs(a) == false || bfs(b) == false) return;
	for (int i = 0; i < a.size(); i++) tmp += people[a[i]]; // 인구수 차이를 구함
	for (int i = 0; i < b.size(); i++) tmp -= people[b[i]];
	cnt = min(cnt, abs(tmp));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cnt = INF;
	vector<int> v;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> people[i];
	}
	for (int i = 1; i <= N; i++) { // 구역 연결 정보 입력받기
		int a; cin >> a;
		for (int j = 0; j < a; j++) {
			int b; cin >> b;
			neighb[i].push_back(b);
		}
	}

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++)
			v.push_back(0);
		for (int j = 0; j < N - i; j++)
			v.push_back(1);
		do {
			solve(v);
			//v.clear();
		} while (next_permutation(v.begin(), v.end()));
		v.clear();
	}

	if (cnt == INF) 
		cout << -1 << '\n';
	else 
		cout << cnt << '\n';
	return 0;
}
