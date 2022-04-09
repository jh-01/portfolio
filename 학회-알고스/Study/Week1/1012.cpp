#include <iostream>
#include <cstring>
#define MAX 51

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
bool c[MAX][MAX]; // 방문 여부 체크 배열 
int T, M, N, K;
int cabbage[MAX][MAX]; // 배추 위치 저장 배열 

void dfs(int x, int y){ // dfs 사용 
	c[x][y] = true;
	for(int i = 0; i < 4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx >= 0 && nx < M && ny >= 0 && ny < N){ 
		// 좌표가 밭의 범위를 넘어가지 않을 때 
			if(cabbage[nx][ny] == 1) { // 배추가 있고 방문하지 않았다면 dfs 재귀 수행 
				if(!c[nx][ny]) dfs(nx, ny);
			}
		}
		else continue;
	}
}

int main() {
	scanf("%d", &T);
	while(T--){
		int count = 0;
		scanf("%d %d %d", &M, &N, &K);
		for(int i = 0; i < K; i++){ // K개의 배추 위치 입력받기 
			int a, b;
			scanf("%d %d", &a, &b);
			cabbage[a][b] = 1;
		}
		for(int i = 0; i < M; i++){
			for(int j = 0; j < N; j++){
				if(cabbage[i][j] == 1 && !c[i][j]){
					count++;
					dfs(i, j);
				}
					
			}
		}
		printf("%d\n", count);
		memset(c, false, sizeof(c)); // 배열 값 초기화 
		memset(cabbage, 0, sizeof(cabbage));
	}
	return 0;
}
