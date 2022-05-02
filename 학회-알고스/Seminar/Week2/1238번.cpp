#include <iostream>
#define MAX 1001
#define INF 1e9
using namespace std;

int N, M, X;
int arr[MAX][MAX];

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
	
	int max_num = 0;
	for(int i = 1; i <= N; i++){
		if(max_num < arr[i][X] + arr[X][i]){
			max_num = arr[i][X] + arr[X][i];
		}	
	}
	return max_num;
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M >> X;
	
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			arr[i][j] = INF;
		}
		arr[i][i] = 0;
	}

	for(int i = 0; i < M; i++){
		int a, b, c;
		cin >> a >> b >> c;
		arr[a][b] = c;
	}

	cout << floyd();
	return 0;
}
