#include <iostream>
#define MAX 101
using namespace std;

int N, M;
int arr[MAX][MAX];
int kb[MAX];

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
	
	int min_num = 10000000;
	int res = 0;
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			kb[i] += arr[i][j];
		}
		if(min_num > kb[i]){
			min_num = kb[i];
			res = i;
		}	
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
			arr[i][j] = 10000000;
		}
	}
	
	for(int i = 0; i < M; i++){
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}
	cout << floyd();
	return 0;
}
