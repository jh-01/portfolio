#include <iostream>
#include <vector>
#define MAX 101
using namespace std;

int N, M, cnt = 0;
vector<int> node[MAX];
bool visited[MAX];

void dfs(int x){
	visited[x] = true;
	for(int i = 0; i < node[x].size(); i++){
		int y = node[x][i];
		if(!visited[y]){
			dfs(y);
			cnt++;
		}
	}
}

int main() {
	cin >> N >> M;
	for(int i = 0; i < M; i++){
		int a, b;
		cin >> a >> b;
		node[a].push_back(b);
		node[b].push_back(a);
	}
	dfs(1);
	cout << cnt;
	return 0;
}
