#include <iostream>
#define MAX 1001
#define INF 1e9
using namespace std;

int N, M;
int arr[MAX][MAX];

int floyd(){
	for(int k = 1; k <= N; k++){ // 거쳐가는 노드 
		for(int i = 1; i <= N; i++){
			for(int j = 1; j <= N; j++){
				if(arr[i][k] == 1 && arr[k][j] == 1){
					arr[i][j] = 1;
				} 
			}
		}
	}
	
	int res = 0;
	for(int i = 1; i <= N; i++){
		int cnt = 0;
		for(int j = 1; j <=N; j++){
			if(arr[i][j] != INF || arr[j][i] != INF) cnt++;
		}
		if(cnt == N - 1) res++;
	}
	return res;
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;

	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			arr[i][j] = INF;
		}
	}
	
	for(int i = 0; i < M; i++){
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
	}

	cout << floyd();
	return 0;
}
