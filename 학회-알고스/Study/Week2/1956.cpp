#include <iostream>
#define MAX 401
#define INF 2000000000
using namespace std;

int V, E;
long long arr[MAX][MAX];

int floyd(){
	for(int k = 1; k <= V; k++){ // 거쳐가는 노드 
		for(int i = 1; i <= V; i++){
			for(int j = 1; j <= V; j++){
				if(arr[i][j] > arr[i][k] + arr[k][j]){
					arr[i][j] = arr[i][k] + arr[k][j];
				}
			}
		}
	}
	long long res = INF;
	for(int i = 1; i <= V; i++){
		for(int j = 1; j <= V; j++){
			if(i == j) continue;
			res = min(res, arr[i][j] + arr[j][i]);
		}
	}
	if(res == INF) return -1;
	else return res;
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> V >> E;
	
	for(int i = 1; i <= V; i++){
		for(int j = 1; j <= V; j++){
			if(i == j) arr[i][j] = 0;
			else arr[i][j] = INF;
		}
	}
	
	for(int i = 0; i < E; i++){
		int a, b, c;
		cin >> a >> b >> c;
		arr[a][b] = c;
	}
	cout << floyd();
	return 0;
}
