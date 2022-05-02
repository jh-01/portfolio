#include <iostream>
#include <string.h>
#define MAX 101
#define INF 1e9
using namespace std;

int T, N, M, K;
int arr[MAX][MAX];
int room[MAX];
int f[MAX];

int floyd(){
	for(int k = 1; k <= N; k++){ // 거쳐가는 노드 
		for(int i = 1; i <= N; i++){
			for(int j = 1; j <= N; j++){
				if(arr[i][j] > arr[i][k] + arr[k][j]){
					arr[i][j] = arr[i][k] + arr[k][j];
				}
			}
		}
	}
	
	int min_num = INF;
	int res = 0;
	for(int i = 1; i <= N; i++){
		int cnt = 0;
		for(int j = 0; j < K; j++){
			cnt += arr[i][room[j]];
		}
		if(min_num > cnt){
			min_num = cnt;
			res = i;
		}	
	}
	return res;
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> T;
	while(T--){
		cin >> N >> M;
	
		for(int i = 1; i <= N; i++){
			for(int j = 1; j <= N; j++){
				if(i == j) continue;
				arr[i][j] = INF;
			}
		}
	
		for(int i = 0; i < M; i++){
			int a, b, c;
			cin >> a >> b >> c;
			arr[a][b] = c;
			arr[b][a] = c;
		}
		
		cin >> K;
		for(int i = 0 ; i < K; i++){
			cin >> room[i];
		}
		cout << floyd() << "\n";
		memset(room, 0, sizeof(room));
	}
	return 0;
}
