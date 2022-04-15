#include <iostream>
#include <cstring>
#include <queue>
#define MAX 51
using namespace std;

int N, L, R;
int day = 0;
int map[MAX][MAX];
bool c[MAX][MAX];
bool flag;
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

void bfs(int a, int b) {
	int sum = 0, country_num = 0;
	queue<pair<int, int>> q1;
	queue<pair<int, int>> q2;

	c[a][b] = true;
	q1.push(make_pair(a, b));
	q2.push(make_pair(a, b));
	sum += map[a][b];
	country_num++;

	while (!q1.empty()) {
		int y = q1.front().first;
		int x = q1.front().second;
		q1.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
			if (c[ny][nx]) continue;
			if (abs(map[y][x] - map[ny][nx]) >= L && abs(map[y][x] - map[ny][nx]) <= R) {
				c[ny][nx] = true;
				q1.push(make_pair(ny, nx));
				q2.push(make_pair(ny, nx));
				sum += map[ny][nx];
				country_num++;
				flag = true;
			}
		}
	}
	if (q2.size() != 1) {
		while (!q2.empty()) {
			int y = q2.front().first;
			int x = q2.front().second;
			map[y][x] = sum / country_num;
			q2.pop();
		}
	}
}

int main() {
	cin >> N >> L >> R;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	while (1) {
		memset(c, false, sizeof(c));
		flag = false;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (!c[i][j]) {
					bfs(i, j);
				}
			}
		}
		if (flag) day++;
		else break;
	}
	cout << day << '\n';
	
	return 0;
}
