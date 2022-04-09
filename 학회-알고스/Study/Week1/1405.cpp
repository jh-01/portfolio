#include <iostream>
#define MAX 29

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
bool c[MAX][MAX]; // 방문 여부 체크 배열 
int N;
double per[4]; // 확률 저장 배열 

double dfs(int x, int y, int count){ // dfs 사용
	if(count == N) return 1.0; 
	c[x][y] = true;
	double res = 0.0;
	for(int i = 0; i < 4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(c[nx][ny] == true) continue;
		res += per[i] * dfs(nx, ny, count + 1);
	}
	c[x][y] = false;
	return res;
}

int main() {
	double res;
	cin >> N;
	for(int i = 0; i < 4; i++){ 
		int a;
		cin >> a;
		per[i] = a / 100.0;
	}
	
	res = dfs(14, 14, 0);
	
	cout.precision(10);
	cout << fixed << res;
	return 0;
} 
