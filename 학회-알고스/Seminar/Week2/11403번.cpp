#include <iostream>
#define MAX 101
using namespace std;

int N;
int arr[MAX][MAX];

void floyd(){
	for(int k = 1; k <= N; k++){ // 거쳐가는 노드 
		for(int i = 1; i <= N; i++){
			for(int j = 1; j <= N; j++){
				if(arr[i][k] == 1 && arr[k][j] == 1){
					arr[i][j] = 1;
				}
			}
		}
	}
	
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			if(arr[i][j] == 1) cout << 1 << " ";
			else cout << 0 << " ";
		}
		cout << "\n";
	}
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;

	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			cin >> arr[i][j];
		}
	}
	floyd();
	return 0;
}
