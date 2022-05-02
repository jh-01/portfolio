#include <iostream>
#define MAX 101
using namespace std;

int N, M;
int arr[MAX][MAX];

int floyd(){
	for(int k = 1; k <= N; k++){ // 거쳐가는 노드 
		for(int i = 1; i <= N; i++){
			for(int j = 1; j <= M; j++){
				if(arr[i][k] == 1 && arr[k][j] == 1){
					arr[i][j] = 1;
				}
			}
		}
	}
	
	for(int i = 1; i <= N; i++){
		int cnt = 0;
		for(int j = 1; j <= N; j++){
			if(i == j) continue;
			if(arr[i][j] == 0 && arr[j][i] == 0) cnt++;
		}
		cout << cnt << "\n";
	}
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;
	
	for(int i = 0; i < M; i++){
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
	}
	floyd();
	return 0;
}
