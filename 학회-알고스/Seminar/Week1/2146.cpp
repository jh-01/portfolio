#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>
#define INF 987654321
#define MAX 101
using namespace std;

int N, min_leng;
int cnt = 0;
int c[MAX][MAX];
int map[MAX][MAX];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
vector<pair<int, int> > v;

// 다리 찾기
int find(int x, int y) {
    queue<pair<int, int> > q;
    int result[MAX][MAX] = { 0, };
    int num = map[x][y];
    result[x][y] = 1;
    q.push(make_pair(x, y));
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        if (num < map[x][y]) return result[x][y] - 2;
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (result[nx][ny] > 0) continue;
            if (ny < N && ny >= 0 && nx < N && nx >= 0) {
                if (map[nx][ny] != num) {
                    result[nx][ny] = result[x][y] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
    return INF;
}

// 섬 숫자 바꾸기
void change(int x, int y, int a) {
    queue<pair<int, int> > q;
    c[x][y] = 1;
    map[x][y] = a;
    q.push(make_pair(x, y));
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny >= N || ny < 0 || nx >= N || nx < 0)
                continue;
            if (c[nx][ny])
                continue;
            if (map[nx][ny] == 1) {
                c[nx][ny] = 1;
                q.push(make_pair(nx, ny));
                map[nx][ny] = a;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!c[i][j] && map[i][j] == 1) {
                cnt++;
                change(i, j, cnt); 
            }
        }
    }
    int min_leng = INF;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] >= 1) {
                //change(i, j, cnt);
                memset(c, 0, sizeof(c));
                min_leng = min(min_leng, find(i, j));
            }
        }
    }
    cout << min_leng;
    return 0;
}
