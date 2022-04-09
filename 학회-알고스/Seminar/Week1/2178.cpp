#include <iostream>
#include <queue>
#define MAX 101

using namespace std;

int N, M;
int map[MAX][MAX];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
bool v[MAX][MAX];

int bfs(int x, int y, int c){
	queue<pair<pair<int, int>, int>> q;
	q.push(make_pair(make_pair(x, y), c));
	
	while(!q.empty()){
		x = q.front().first.first;
		y = q.front().first.second;
		c = q.front().second;
		q.pop();
		
		if(x == N - 1 && y == M - 1){
			return c;
		}
		
		for(int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if(map[nx][ny] == 1 && !v[nx][ny]){
				q.push(make_pair(make_pair(nx, ny), c + 1));
				v[nx][ny] = true;
			}
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			scanf("%1d", &map[i][j]);
		}
	}	
	
	printf("%d", bfs(0, 0, 1));
	return 0;
}
